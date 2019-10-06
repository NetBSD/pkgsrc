# $NetBSD: Shell.pm,v 1.2 2019/10/06 10:33:34 rillig Exp $
#
# Parsing and checking shell commands embedded in Makefiles
#

sub checkline_mk_shellword($$$) {
	my ($line, $shellword, $check_quoting) = @_;
	my ($rest, $state, $value);

	$opt_debug_trace and $line->log_debug("checkline_mk_shellword(\"${shellword}\", ${check_quoting}).");
	use constant shellcommand_context_type => PkgLint::Type->new(
		LK_NONE, "ShellCommand", [[ qr".*", "adsu" ]], NOT_GUESSED
	);
	use constant shellword_vuc => PkgLint::VarUseContext->new(
		VUC_TIME_UNKNOWN,
		shellcommand_context_type,
		VUC_SHELLWORD_PLAIN,
		VUC_EXTENT_WORD
	);

	if ($shellword =~ m"^\$\{(${regex_varname})(:[^{}]+)?\}$") {
		my ($varname, $mod) = ($1, $2);

		checkline_mk_varuse($line, $varname, defined($mod) ? $mod : "", shellword_vuc);
		return;
	}

	if ($shellword =~ m"\$\{PREFIX\}/man(?:$|/)") {
		$line->log_warning("Please use \${PKGMANDIR} instead of \"man\".");
	}

	if ($shellword =~ m"etc/rc\.d") {
		$line->log_warning("Please use the RCD_SCRIPTS mechanism to install rc.d scripts automatically to \${RCD_SCRIPTS_EXAMPLEDIR}.");
	}

	# Note: SWST means [S]hell[W]ord [ST]ate
	use enum qw(:SWST_ PLAIN SQUOT DQUOT DQUOT_BACKT BACKT);
	use constant statename		=> [
		"SWST_PLAIN", "SWST_SQUOT", "SWST_DQUOT",
		"SWST_DQUOT_BACKT", "SWST_BACKT",
	];
	use constant user_statename	=> [
		"unquoted string", "single quoted string",
		"double quoted string", "backticks inside double quoted string",
		"backticks",
	];

	$rest = ($shellword =~ m"^#") ? "" : $shellword;
	$state = SWST_PLAIN;
	while ($rest ne "") {

		$opt_debug_shell and $line->log_debug(statename->[$state] . ": ${rest}");

		# When we are parsing inside backticks, it is more
		# reasonable to check the whole shell command
		# recursively, instead of splitting off the first
		# make(1) variable (see the elsif below).
		if ($state == SWST_BACKT || $state == SWST_DQUOT_BACKT) {

			# Scan for the end of the backticks, checking
			# for single backslashes and removing one level
			# of backslashes. Backslashes are only removed
			# before a dollar, a backslash or a backtick.
			#
			# References:
			# * http://www.opengroup.org/onlinepubs/009695399/utilities/xcu_chap02.html#tag_02_06_03
			my $stripped = "";
			while ($rest ne "") {
				if ($rest =~ s/^\`//) { #`
					$state = ($state == SWST_BACKT) ? SWST_PLAIN : SWST_DQUOT;
					goto end_of_backquotes;
				} elsif ($rest =~ s/^\\([\\\`\$])//) { #`
					$stripped .= $1;
				} elsif ($rest =~ s/^(\\)//) {
					$line->log_warning("Backslashes should be doubled inside backticks.");
					$stripped .= $1;
				} elsif ($state == SWST_DQUOT_BACKT && $rest =~ s/^"//) { #"
					$line->log_warning("Double quotes inside backticks inside double quotes are error prone.");
					$line->explain_warning(
"According to the SUSv3, they produce undefined results.",
"",
"See the paragraph starting \"Within the backquoted ...\" in",
"http://www.opengroup.org/onlinepubs/009695399/utilities/xcu_chap02.html");
				} elsif ($rest =~ s/^([^\\\`]+)//) { #`
					$stripped .= $1;
				} else {
					assert(false, "rest=$rest");
				}
			}
			$line->log_error("Unfinished backquotes: rest=$rest");

		end_of_backquotes:
			# Check the resulting command.
			checkline_mk_shelltext($line, $stripped);

		# make(1) variables have the same syntax, no matter in
		# which state we are currently.
		} elsif ($rest =~ s/^\$\{(${regex_varname}|[\@])(:[^\{]+)?\}//
		||  $rest =~ s/^\$\((${regex_varname}|[\@])(:[^\)]+)?\)//
		||  $rest =~ s/^\$([\w\@])//) {
			my ($varname, $mod) = ($1, $2);

			if ($varname eq "\@") {
				$line->log_warning("Please use \"\${.TARGET}\" instead of \"\$\@\".");
				$line->explain_warning(
"The variable \$\@ can easily be confused with the shell variable of the",
"same name, which has a completely different meaning.");
				$varname = ".TARGET";
			}

			if ($state == SWST_PLAIN && defined($mod) && $mod =~ m":Q$") {
				# Fine.

			} elsif ($state == SWST_BACKT) {
				# Don't check here, to avoid false positives
				# for tool names.

			} elsif (($state == SWST_SQUOT || $state == SWST_DQUOT) && $varname =~ m"^(?:.*DIR|.*FILE|.*PATH|.*_VAR|PREFIX|.*BASE|PKGNAME)$") {
				# This is ok if we don't allow these
				# variables to have embedded [\$\\\"\'\`].

			} elsif ($state == SWST_DQUOT && defined($mod) && $mod =~ m":Q$") {
				$line->log_warning("Please don't use the :Q operator in double quotes.");
				$line->explain_warning(
"Either remove the :Q or the double quotes. In most cases, it is more",
"appropriate to remove the double quotes.");

			}

			my $ctx = PkgLint::VarUseContext->new_from_pool(
				VUC_TIME_UNKNOWN,
				shellcommand_context_type,
				  ($state == SWST_PLAIN) ? VUC_SHELLWORD_PLAIN
				: ($state == SWST_DQUOT) ? VUC_SHELLWORD_DQUOT
				: ($state == SWST_SQUOT) ? VUC_SHELLWORD_SQUOT
				: ($state == SWST_BACKT) ? VUC_SHELLWORD_BACKT
				: VUC_SHELLWORD_UNKNOWN,
				VUC_EXTENT_WORD_PART
			);
			if ($varname ne "\@") {
				checkline_mk_varuse($line, $varname, defined($mod) ? $mod : "", $ctx);
			}

		# The syntax of the variable modifiers can get quite
		# hairy. In lack of motivation, we just skip anything
		# complicated, hoping that at least the braces are
		# balanced.
		} elsif ($rest =~ s/^\$\{//) {
			my $braces = 1;
			while ($rest ne "" && $braces > 0) {
				if ($rest =~ s/^\}//) {
					$braces--;
				} elsif ($rest =~ s/^\{//) {
					$braces++;
				} elsif ($rest =~ s/^[^{}]+//) {
					# Nothing to do here.
				} else {
					last;
				}
			}

		} elsif ($state == SWST_PLAIN) {

			# XXX: This is only true for the "first" word in a
			# shell command, not for every word. For example,
			# FOO_ENV+= VAR=`command` may be underquoted.
			if (false && $rest =~ m"([\w_]+)=\"\`") {
				$line->log_note("In the assignment to \"$1\", you don't need double quotes around backticks.");
				$line->explain_note(
"Assignments are a special context, where no double quotes are needed",
"around backticks. In other contexts, the double quotes are necessary.");
			}

			if ($rest =~ s/^[!#\%&\(\)*+,\-.\/0-9:;<=>?\@A-Z\[\]^_a-z{|}~]+//) {
			} elsif ($rest =~ s/^\'//) {
				$state = SWST_SQUOT;
			} elsif ($rest =~ s/^\"//) {
				$state = SWST_DQUOT;
			} elsif ($rest =~ s/^\`//) { #`
				$state = SWST_BACKT;
			} elsif ($rest =~ s/^\\(?:[ !"#'\(\)*;?\\^{|}]|\$\$)//) {
			} elsif ($rest =~ s/^\$\$([0-9A-Z_a-z]+|\#)//
			    || $rest =~ s/^\$\$\{([0-9A-Z_a-z]+|\#)\}//
			    || $rest =~ s/^\$\$(\$)\$//) {
				my ($shvarname) = ($1);
				if ($opt_warn_quoting && $check_quoting) {
					$line->log_warning("Unquoted shell variable \"${shvarname}\".");
					$line->explain_warning(
"When a shell variable contains white-space, it is expanded (split into", 
"multiple words) when it is written as \$variable in a shell script.",
"If that is not intended, you should add quotation marks around it,",
"like \"\$variable\". Then, the variable will always expand to a single",
"word, preserving all white-space and other special characters.",
"",
"Example:",
"\tfname=\"Curriculum vitae.doc\"",
"\tcp \$fname /tmp",
"\t# tries to copy the two files \"Curriculum\" and \"Vitae.doc\"",
"\tcp \"\$fname\" /tmp",
"\t# copies one file, as intended");
				}

			} elsif ($rest =~ s/^\$\@//) {
				$line->log_warning("Please use \"\${.TARGET}\" instead of \"\$@\".");
				$line->explain_warning(
"It is more readable and prevents confusion with the shell variable of",
"the same name.");

			} elsif ($rest =~ s/^\$\$\@//) {
				$line->log_warning("The \$@ shell variable should only be used in double quotes.");

			} elsif ($rest =~ s/^\$\$\?//) {
				$line->log_warning("The \$? shell variable is often not available in \"set -e\" mode.");

			} elsif ($rest =~ s/^\$\$\(/(/) {
				$line->log_warning("Invoking subshells via \$(...) is not portable enough.");
				$line->explain_warning(
"The Solaris /bin/sh does not know this way to execute a command in a",
"subshell. Please use backticks (\`...\`) as a replacement.");

			} else {
				last;
			}

		} elsif ($state == SWST_SQUOT) {
			if ($rest =~ s/^\'//) {
				$state = SWST_PLAIN;
			} elsif ($rest =~ s/^[^\$\']+//) { #'
			} elsif ($rest =~ s/^\$\$//) {
			} else {
				last;
			}

		} elsif ($state == SWST_DQUOT) {
			if ($rest =~ s/^\"//) {
				$state = SWST_PLAIN;
			} elsif ($rest =~ s/^\`//) { #`
				$state = SWST_DQUOT_BACKT;
			} elsif ($rest =~ s/^[^\$"\\\`]+//) { #`
			} elsif ($rest =~ s/^\\(?:[\\\"\`]|\$\$)//) { #`
			} elsif ($rest =~ s/^\$\$\{([0-9A-Za-z_]+)\}//
			    || $rest =~ s/^\$\$([0-9A-Z_a-z]+|[!#?\@]|\$\$)//) {
				my ($shvarname) = ($1);
				$opt_debug_shell and $line->log_debug("[checkline_mk_shellword] Found double-quoted variable ${shvarname}.");
			} elsif ($rest =~ s/^\$\$//) {
				$line->log_warning("Unquoted \$ or strange shell variable found.");
			} elsif ($rest =~ s/^\\(.)//) {
				my ($char) = ($1);
				$line->log_warning("Please use \"\\\\${char}\" instead of \"\\${char}\".");
				$line->explain_warning(
"Although the current code may work, it is not good style to rely on",
"the shell passing \"\\${char}\" exactly as is, and not discarding the",
"backslash. Alternatively you can use single quotes instead of double",
"quotes.");
			} else {
				last;
			}

		} else {
			last;
		}
	}
	if ($rest !~ m"^\s*$") {
		$line->log_error("Internal pkglint error: " . statename->[$state] . ": rest=${rest}");
	}
}

# Some shell commands should not be used in the install phase.
#
sub checkline_mk_shellcmd_use($$) {
	my ($line, $shellcmd) = @_;

	use constant allowed_install_commands => array_to_hash(qw(
		${INSTALL}
		${INSTALL_DATA} ${INSTALL_DATA_DIR}
		${INSTALL_LIB} ${INSTALL_LIB_DIR}
		${INSTALL_MAN} ${INSTALL_MAN_DIR}
		${INSTALL_PROGRAM} ${INSTALL_PROGRAM_DIR}
		${INSTALL_SCRIPT}
		${LIBTOOL}
		${LN}
		${PAX}
	));
	use constant discouraged_install_commands => array_to_hash(qw(
		sed ${SED}
		tr ${TR}
	));

	if (defined($mkctx_target) && $mkctx_target =~ m"^(?:pre|do|post)-install") {

		if (exists(allowed_install_commands->{$shellcmd})) {
			# Fine.

		} elsif (exists(discouraged_install_commands->{$shellcmd})) {
			$line->log_warning("The shell command \"${shellcmd}\" should not be used in the install phase.");
			$line->explain_warning(
"In the install phase, the only thing that should be done is to install",
"the prepared files to their final location. The file's contents should",
"not be changed anymore.");

		} elsif ($shellcmd eq "\${CP}") {
			$line->log_warning("\${CP} should not be used to install files.");
			$line->explain_warning(
"The \${CP} command is highly platform dependent and cannot overwrite",
"files that don't have write permission. Please use \${PAX} instead.",
"",
"For example, instead of",
"\t\${CP} -R \${WRKSRC}/* \${PREFIX}/foodir",
"you should use",
"\tcd \${WRKSRC} && \${PAX} -wr * \${PREFIX}/foodir");

		} else {
			$opt_debug_misc and $line->log_debug("May \"${shellcmd}\" be used in the install phase?");
		}
	}
}

sub checkline_mk_shelltext($$) {
	my ($line, $text) = @_;
	my ($vartools, $state, $rest, $set_e_mode);

	$opt_debug_trace and $line->log_debug("checkline_mk_shelltext(\"$text\")");

	# Note: SCST is the abbreviation for [S]hell [C]ommand [ST]ate.
	use constant scst => qw(
		START CONT
		INSTALL INSTALL_D
		MKDIR
		PAX PAX_S
		SED SED_E
		SET SET_CONT
		COND COND_CONT
		CASE CASE_IN CASE_LABEL CASE_LABEL_CONT CASE_PAREN
		FOR FOR_IN FOR_CONT
		ECHO
		INSTALL_DIR INSTALL_DIR2
	);
	use enum (":SCST_", scst);
	use constant scst_statename => [ map { "SCST_$_" } scst ];

	use constant forbidden_commands => array_to_hash(qw(
		ktrace
		mktexlsr
		strace
		texconfig truss
	));

	if ($text =~ m"\$\{SED\}" && $text =~ m"\$\{MV\}") {
		$line->log_note("Please use the SUBST framework instead of \${SED} and \${MV}.");
		$line->explain_note(
"When converting things, pay attention to \"#\" characters. In shell",
"commands make(1) does not interpret them as comment character, but",
"in other lines it does. Therefore, instead of the shell command",
"",
"\tsed -e 's,#define foo,,'",
"",
"you need to write",
"",
"\tSUBST_SED.foo+=\t's,\\#define foo,,'");
	}

	if ($text =~ m"^\@*-(.*(MKDIR|INSTALL.*-d|INSTALL_.*_DIR).*)") {
		my ($mkdir_cmd) = ($1);

		$line->log_note("You don't need to use \"-\" before ${mkdir_cmd}.");
	}

	$vartools = get_vartool_names();
	$rest = $text;

	use constant hidden_shell_commands => array_to_hash(qw(
		${DELAYED_ERROR_MSG} ${DELAYED_WARNING_MSG}
		${DO_NADA}
		${ECHO} ${ECHO_MSG} ${ECHO_N} ${ERROR_CAT} ${ERROR_MSG}
		${FAIL_MSG}
		${PHASE_MSG} ${PRINTF}
		${SHCOMMENT} ${STEP_MSG}
		${WARNING_CAT} ${WARNING_MSG}
	));

	$set_e_mode = false;

	if ($rest =~ s/^\s*([-@]*)(\$\{_PKG_SILENT\}\$\{_PKG_DEBUG\}|\$\{RUN\}|)//) {
		my ($hidden, $macro) = ($1, $2);

		if ($hidden !~ m"\@") {
			# Nothing is hidden at all.

		} elsif (defined($mkctx_target) && $mkctx_target =~ m"^(?:show-.*|.*-message)$") {
			# In some targets commands may be hidden.

		} elsif ($rest =~ m"^#") {
			# Shell comments may be hidden, as they have no side effects

		} elsif ($rest =~ $regex_shellword) {
			my ($cmd) = ($1);

			if (!exists(hidden_shell_commands->{$cmd})) {
				$line->log_warning("The shell command \"${cmd}\" should not be hidden.");
				$line->explain_warning(
"Hidden shell commands do not appear on the terminal or in the log file",
"when they are executed. When they fail, the error message cannot be",
"assigned to the command, which is very difficult to debug.");
			}
		}

		if ($hidden =~ m"-") {
			$line->log_warning("The use of a leading \"-\" to suppress errors is deprecated.");
			$line->explain_warning(
"If you really want to ignore any errors from this command (including",
"all errors you never thought of), append \"|| \${TRUE}\" to the",
"command.");
		}

		if ($macro eq "\${RUN}") {
			$set_e_mode = true;
		}
	}

	$state = SCST_START;
	while ($rest =~ s/^$regex_shellword//) {
		my ($shellword) = ($1);

		$opt_debug_shell and $line->log_debug(scst_statename->[$state] . ": ${shellword}");

		checkline_mk_shellword($line, $shellword, !(
		       $state == SCST_CASE
		    || $state == SCST_FOR_CONT
		    || $state == SCST_SET_CONT
		    || ($state == SCST_START && $shellword =~ regex_sh_varassign)));

		#
		# Actions associated with the current state
		# and the symbol on the "input tape".
		#

		if ($state == SCST_START || $state == SCST_COND) {
			my ($type);

			if ($shellword eq "\${RUN}") {
				# Just skip this one.

			} elsif (exists(forbidden_commands->{basename($shellword)})) {
				$line->log_error("${shellword} must not be used in Makefiles.");
				$line->explain_error(
"This command must appear in INSTALL scripts, not in the package",
"Makefile, so that the package also works if it is installed as a binary",
"package via pkg_add.");

			} elsif (exists(get_tool_names()->{$shellword})) {
				if (!exists($mkctx_tools->{$shellword}) && !exists($mkctx_tools->{"g$shellword"})) {
					$line->log_warning("The \"${shellword}\" tool is used but not added to USE_TOOLS.");
				}

				if (exists(get_required_vartools()->{$shellword})) {
					$line->log_warning("Please use \"\${" . get_vartool_names()->{$shellword} . "}\" instead of \"${shellword}\".");
				}

				checkline_mk_shellcmd_use($line, $shellword);

			} elsif ($shellword =~ m"^\$\{([\w_]+)\}$" && exists(get_varname_to_toolname()->{$1})) {
				my ($vartool) = ($1);
				my $plain_tool = get_varname_to_toolname()->{$vartool};

				if (!exists($mkctx_tools->{$plain_tool})) {
					$line->log_warning("The \"${plain_tool}\" tool is used but not added to USE_TOOLS.");
				}

				# Deactivated to allow package developers to write
				# consistent code that uses ${TOOL} in all places.
				if (false && defined($mkctx_target) && $mkctx_target =~ m"^(?:pre|do|post)-(?:extract|patch|wrapper|configure|build|install|package|clean)$") {
					if (!exists(get_required_vartool_varnames()->{$vartool})) {
						$opt_warn_extra and $line->log_note("You can write \"${plain_tool}\" instead of \"${shellword}\".");
						$opt_warn_extra and $line->explain_note(
"The wrapper framework from pkgsrc takes care that a sufficiently",
"capable implementation of that tool will be selected.",
"",
"Calling the commands by their plain name instead of the macros is",
"only available in the {pre,do,post}-* targets. For all other targets,",
"you should still use the macros.");
					}
				}

				checkline_mk_shellcmd_use($line, $shellword);

			} elsif ($shellword =~ m"^\$\{([\w_]+)\}$" && defined($type = get_variable_type($line, $1)) && $type->basic_type eq "ShellCommand") {
				checkline_mk_shellcmd_use($line, $shellword);

			} elsif ($shellword =~ m"^\$\{(\w+)\}$" && defined($pkgctx_vardef) && exists($pkgctx_vardef->{$1})) {
				# When the package author has explicitly
				# defined a command variable, assume it
				# to be valid.

			} elsif ($shellword =~ m"^(?:\(|\)|:|;|;;|&&|\|\||\{|\}|break|case|cd|continue|do|done|elif|else|esac|eval|exec|exit|export|fi|for|if|read|set|shift|then|umask|unset|while)$") {
				# Shell builtins are fine.

			} elsif ($shellword =~ m"^[\w_]+=.*$") {
				# Variable assignment.

			} elsif ($shellword =~ m"^\./.*$") {
				# All commands from the current directory are fine.

			} elsif ($shellword =~ m"^#") {
				my $semicolon = ($shellword =~ m";");
				my $multiline = ($line->lines =~ m"--");

				if ($semicolon) {
					$line->log_warning("A shell comment should not contain semicolons.");
				}
				if ($multiline) {
					$line->log_warning("A shell comment does not stop at the end of line.");
				}

				if ($semicolon || $multiline) {
					$line->explain_warning(
"When you split a shell command into multiple lines that are continued",
"with a backslash, they will nevertheless be converted to a single line",
"before the shell sees them. That means that even if it _looks_ like that",
"the comment only spans one line in the Makefile, in fact it spans until",
"the end of the whole shell command. To insert a comment into shell code,",
"you can pass it as an argument to the \${SHCOMMENT} macro, which expands",
"to a command doing nothing. Note that any special characters are",
"nevertheless interpreted by the shell.");
				}

			} else {
				$opt_warn_extra and $line->log_warning("Unknown shell command \"${shellword}\".");
				$opt_warn_extra and $line->explain_warning(
"If you want your package to be portable to all platforms that pkgsrc",
"supports, you should only use shell commands that are covered by the",
"tools framework.");

			}
		}

		if ($state == SCST_COND && $shellword eq "cd") {
			$line->log_error("The Solaris /bin/sh cannot handle \"cd\" inside conditionals.");
			$line->explain_error(
"When the Solaris shell is in \"set -e\" mode and \"cd\" fails, the",
"shell will exit, no matter if it is protected by an \"if\" or the",
"\"||\" operator.");
		}

		if (($state == SCST_INSTALL_D || $state == SCST_MKDIR) && $shellword =~ m"^(?:\$\{DESTDIR\})?\$\{PREFIX(?:|:Q)\}/") {
			$line->log_warning("Please use AUTO_MKDIRS instead of "
				. (($state == SCST_MKDIR) ? "\${MKDIR}" : "\${INSTALL} -d")
				. ".");
			$line->explain_warning(
"Setting AUTO_MKDIRS=yes automatically creates all directories that are",
"mentioned in the PLIST. If you need additional directories, specify",
"them in INSTALLATION_DIRS, which is a list of directories relative to",
"\${PREFIX}.");
		}

		if (($state == SCST_INSTALL_DIR || $state == SCST_INSTALL_DIR2) && $shellword !~ regex_mk_shellvaruse && $shellword =~ m"^(?:\$\{DESTDIR\})?\$\{PREFIX(?:|:Q)\}/(.*)") {
			my ($dirname) = ($1);

			$line->log_note("You can use AUTO_MKDIRS=yes or INSTALLATION_DIRS+= ${dirname} instead of this command.");
			$line->explain_note(
"This saves you some typing. You also don't have to think about which of",
"the many INSTALL_*_DIR macros is appropriate, since INSTALLATION_DIRS",
"takes care of that.",
"",
"Note that you should only do this if the package creates _all_",
"directories it needs before trying to install files into them.",
"",
"Many packages include a list of all needed directories in their PLIST",
"file. In that case, you can just set AUTO_MKDIRS=yes and be done.");
		}

		if ($state == SCST_INSTALL_DIR2 && $shellword =~ m"^\$") {
			$line->log_warning("The INSTALL_*_DIR commands can only handle one directory at a time.");
			$line->explain_warning(
"Many implementations of install(1) can handle more, but pkgsrc aims at",
"maximum portability.");
		}

		if ($state == SCST_PAX && $shellword eq "-pe") {
			$line->log_warning("Please use the -pp option to pax(1) instead of -pe.");
			$line->explain_warning(
"The -pe option tells pax to preserve the ownership of the files, which",
"means that the installed files will belong to the user that has built",
"the package. That's a Bad Thing.");
		}

		if ($state == SCST_PAX_S || $state == SCST_SED_E) {
			if (false && $shellword !~ m"^[\"\'].*[\"\']$") {
				$line->log_warning("Substitution commands like \"${shellword}\" should always be quoted.");
				$line->explain_warning(
"Usually these substitution commands contain characters like '*' or",
"other shell metacharacters that might lead to lookup of matching",
"filenames and then expand to more than one word.");
			}
		}

		if ($state == SCST_ECHO && $shellword eq "-n") {
			$line->log_warning("Please use \${ECHO_N} instead of \"echo -n\".");
		}

		if ($opt_warn_extra && $state != SCST_CASE_LABEL_CONT && $shellword eq "|") {
			$line->log_warning("The exitcode of the left-hand-side command of the pipe operator is ignored.");
			$line->explain_warning(
"If you need to detect the failure of the left-hand-side command, use",
"temporary files to save the output of the command.");
		}

		if ($opt_warn_extra && $shellword eq ";" && $state != SCST_COND_CONT && $state != SCST_FOR_CONT && !$set_e_mode) {
			$line->log_warning("Please switch to \"set -e\" mode before using a semicolon to separate commands.");
			$line->explain_warning(
"Older versions of the NetBSD make(1) had run the shell commands using",
"the \"-e\" option of /bin/sh. In 2004, this behavior has been changed to",
"follow the POSIX conventions, which is to not use the \"-e\" option.",
"The consequence of this change is that shell programs don't terminate",
"as soon as an error occurs, but try to continue with the next command.",
"Imagine what would happen for these commands:",
"    cd \"\$HOME\"; cd /nonexistent; rm -rf *",
"To fix this warning, either insert \"set -e\" at the beginning of this",
"line or use the \"&&\" operator instead of the semicolon.");
		}

		#
		# State transition.
		#

		if ($state == SCST_SET && $shellword =~ m"^-.*e") {
			$set_e_mode = true;
		}
		if ($state == SCST_START && $shellword eq "\${RUN}") {
			$set_e_mode = true;
		}

		$state =  ($shellword eq ";;") ? SCST_CASE_LABEL
			# Note: The order of the following two lines is important.
			: ($state == SCST_CASE_LABEL_CONT && $shellword eq "|") ? SCST_CASE_LABEL
			: ($shellword =~ m"^[;&\|]+$") ? SCST_START
			: ($state == SCST_START) ? (
				  ($shellword eq "\${INSTALL}") ? SCST_INSTALL
				: ($shellword eq "\${MKDIR}") ? SCST_MKDIR
				: ($shellword eq "\${PAX}") ? SCST_PAX
				: ($shellword eq "\${SED}") ? SCST_SED
				: ($shellword eq "\${ECHO}") ? SCST_ECHO
				: ($shellword eq "\${RUN}") ? SCST_START
				: ($shellword eq "echo") ? SCST_ECHO
				: ($shellword eq "set") ? SCST_SET
				: ($shellword =~ m"^(?:if|elif|while)$") ? SCST_COND
				: ($shellword =~ m"^(?:then|else|do)$") ? SCST_START
				: ($shellword eq "case") ? SCST_CASE
				: ($shellword eq "for") ? SCST_FOR
				: ($shellword eq "(") ? SCST_START
				: ($shellword =~ m"^\$\{INSTALL_[A-Z]+_DIR\}$") ? SCST_INSTALL_DIR
				: ($shellword =~ regex_sh_varassign) ? SCST_START
				: SCST_CONT)
			: ($state == SCST_MKDIR) ? SCST_MKDIR
			: ($state == SCST_INSTALL && $shellword eq "-d") ? SCST_INSTALL_D
			: ($state == SCST_INSTALL || $state == SCST_INSTALL_D) ? (
				  ($shellword =~ m"^-[ogm]$") ? SCST_CONT
				: $state)
			: ($state == SCST_INSTALL_DIR) ? (
				  ($shellword =~ m"^-") ? SCST_CONT
				: ($shellword =~ m"^\$") ? SCST_INSTALL_DIR2
				: $state)
			: ($state == SCST_INSTALL_DIR2) ? $state
			: ($state == SCST_PAX) ? (
				  ($shellword eq "-s") ? SCST_PAX_S
				: ($shellword =~ m"^-") ? SCST_PAX
				: SCST_CONT)
			: ($state == SCST_PAX_S) ? SCST_PAX
			: ($state == SCST_SED) ? (
				  ($shellword eq "-e") ? SCST_SED_E
				: ($shellword =~ m"^-") ? SCST_SED
				: SCST_CONT)
			: ($state == SCST_SED_E) ? SCST_SED
			: ($state == SCST_SET) ? SCST_SET_CONT
			: ($state == SCST_SET_CONT) ? SCST_SET_CONT
			: ($state == SCST_CASE) ? SCST_CASE_IN
			: ($state == SCST_CASE_IN && $shellword eq "in") ? SCST_CASE_LABEL
			: ($state == SCST_CASE_LABEL && $shellword eq "esac") ? SCST_CONT
			: ($state == SCST_CASE_LABEL) ? SCST_CASE_LABEL_CONT
			: ($state == SCST_CASE_LABEL_CONT && $shellword eq ")") ? SCST_START
			: ($state == SCST_CONT) ? SCST_CONT
			: ($state == SCST_COND) ? SCST_COND_CONT
			: ($state == SCST_COND_CONT) ? SCST_COND_CONT
			: ($state == SCST_FOR) ? SCST_FOR_IN
			: ($state == SCST_FOR_IN && $shellword eq "in") ? SCST_FOR_CONT
			: ($state == SCST_FOR_CONT) ? SCST_FOR_CONT
			: ($state == SCST_ECHO) ? SCST_CONT
			: do {
				$line->log_warning("[" . scst_statename->[$state] . " ${shellword}] Keeping the current state.");
				$state;
			};
	}

	if ($rest !~ m"^\s*$") {
		$line->log_error("Internal pkglint error: " . scst_statename->[$state] . ": rest=${rest}");
	}
}

sub checkline_mk_shellcmd($$) {
	my ($line, $shellcmd) = @_;

	checkline_mk_text($line, $shellcmd);
	checkline_mk_shelltext($line, $shellcmd);
}

