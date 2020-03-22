# $NetBSD: replace-interpreter.mk,v 1.18 2020/03/22 21:31:21 rillig Exp $

# This file provides common templates for replacing #! interpreters
# in script files.
#
# The following variables may be set by a package:
#
# REPLACE_AWK
# REPLACE_BASH
# REPLACE_CSH
# REPLACE_KSH
# REPLACE_PERL
# REPLACE_PERL6
# REPLACE_SH
#	Lists of files relative to WRKSRC in which the #! interpreter
#	should be replaced by the pkgsrc one. If any directories
#	appear in the lists, they are silenty skipped, assuming that
#	they result from shell globbing expressions.
#
#	Use REPLACE_SH for shell programs that don't need any
#	special features from bash, and REPLACE_BASH for the
#	others.
#
#	Note that in all the above cases, you have to add the needed
#	tools manually to USE_TOOLS, since there is no way to detect
#	automatically whether a tool should be a build-time or a
#	run-time dependency.
#
# Packages may also add their own interpreter replacements, which should
# just look like the examples below. For the REPLACE_INTERPRETER
# variable, all identifiers starting with "sys-" are reserved for the
# pkgsrc infrastructure. All others may be used freely.
#
# Keywords: replace_interpreter interpreter interp hashbang #!
# Keywords: awk bash csh ksh perl sh

######################################################################
### replace-interpreter (PRIVATE)
######################################################################
### replace-interpreter replaces paths to interpreters in scripts with
### the paths to the pkgsrc-managed interpreters.
###
do-configure-pre-hook: replace-interpreter

REPLACE_INTERPRETER?=	# none
REPLACE_AWK?=	# none
REPLACE_BASH?=	# none
REPLACE_CSH?=	# none
REPLACE_KSH?=	# none
REPLACE_PERL?=	# none
REPLACE_SH?=	# none

.if !empty(REPLACE_AWK:M*)
REPLACE_INTERPRETER+=	sys-AWK
REPLACE.sys-AWK.old=	.*awk
REPLACE.sys-AWK.new=	${AWK}
REPLACE_FILES.sys-AWK=	${REPLACE_AWK}
.endif

.if !empty(REPLACE_BASH:M*)
REPLACE_INTERPRETER+=	sys-bash
REPLACE.sys-bash.old=	.*sh
REPLACE.sys-bash.new=	${BASH}
REPLACE_FILES.sys-bash=	${REPLACE_BASH}
.endif

.if !empty(REPLACE_CSH:M*)
REPLACE_INTERPRETER+=	sys-csh
REPLACE.sys-csh.old=	.*csh
REPLACE.sys-csh.new=	${CSH}
REPLACE_FILES.sys-csh=	${REPLACE_CSH}
.endif

.if !empty(REPLACE_KSH:M*)
REPLACE_INTERPRETER+=	sys-ksh
REPLACE.sys-ksh.old=	[^[:space:]]*sh
REPLACE.sys-ksh.new=	${TOOLS_PATH.ksh}
REPLACE_FILES.sys-ksh=	${REPLACE_KSH}
.endif

.if !empty(REPLACE_PERL:M*)
REPLACE_INTERPRETER+=	sys-Perl
REPLACE.sys-Perl.old=	.*perl[^[:space:]]*
REPLACE.sys-Perl.new=	${PERL5}
REPLACE_FILES.sys-Perl=	${REPLACE_PERL}
.endif

.if !empty(REPLACE_PERL6:M*)
PERL6?=			${PREFIX}/bin/perl6
REPLACE_INTERPRETER+=	sys-Perl6
REPLACE.sys-Perl6.old=	.*perl6[^[:space:]]*
REPLACE.sys-Perl6.new=	${PERL6}
REPLACE_FILES.sys-Perl6=${REPLACE_PERL6}
.endif

.if !empty(REPLACE_SH:M*)
REPLACE_INTERPRETER+=	sys-sh
REPLACE.sys-sh.old=	[^[:space:]]*sh
REPLACE.sys-sh.new=	${SH}
REPLACE_FILES.sys-sh=	${REPLACE_SH}
.endif

# sed regexp to match optional "/usr/bin/env" followed by one or more spaces
REPLACE.optional-env-space= \(/usr/bin/env[[:space:]][[:space:]]*\)\{0,1\}

.PHONY: replace-interpreter
replace-interpreter:
.for _lang_ in ${REPLACE_INTERPRETER}
.  if defined(REPLACE_FILES.${_lang_}) && !empty(REPLACE_FILES.${_lang_}:M*)
	@${STEP_MSG} "Replacing ${_lang_:S/^sys-//} interpreter in "${REPLACE_FILES.${_lang_}:M*:Q}"."
	${RUN} set -u; \
	cd ${WRKSRC};							\
	for f in ${REPLACE_FILES.${_lang_}}; do				\
		if [ -f "$${f}" ]; then					\
			${SED} -e '1s|^#![[:space:]]*${REPLACE.optional-env-space}${REPLACE.${_lang_}.old}|#!${REPLACE.${_lang_}.new}|' \
			< "$${f}" > "$${f}.new";			\
			if [ -x "$${f}" ]; then				\
				${CHMOD} a+x "$${f}.new";		\
			fi;						\
			if ${CMP} -s "$${f}.new" "$${f}"; then		\
				${INFO_MSG} "[replace-interpreter] Nothing changed in $${f}."; \
				${RM} -f "$${f}.new";			\
			else						\
				${MV} -f "$${f}.new" "$${f}";		\
			fi;						\
		elif [ -d "$$f" ]; then					\
			${SHCOMMENT} "Ignore it, most probably comes from shell globs"; \
		else							\
			${WARNING_MSG} "[replace-interpreter] Skipping non-existent file \"$$f\"."; \
		fi;							\
	done
.  else
	@${WARNING_MSG} "[replace-interpreter] Empty list of files for ${_lang_}."
.  endif
.endfor

_VARGROUPS+=		interp
.for varname in REPLACE_AWK REPLACE_BASH REPLACE_CSH REPLACE_KSH REPLACE_PERL REPLACE_PERL6 REPLACE_SH
_PKG_VARS.interp+=	${varname}
.endfor
_PKG_VARS.interp+=	REPLACE_INTERPRETER
.for interp in ${REPLACE_INTERPRETER}
_DEF_VARS.interp+=	REPLACE.${interp}.old REPLACE.${interp}.new REPLACE_FILES.${interp}
.endfor
