#	$NetBSD: plist.mk,v 1.1.2.3 2005/02/25 14:46:51 tv Exp $
#
# PLIST generation logic, invoked from the "install" target in bsd.pkg.mk.
# This file should only be ".include"d from bsd.pkg.mk.
#
# The following variables should be set before this is included:
#
## _PLIST_IGNORE_FILES (optional) - files to filter from final PLIST
## GENERATE_PLIST (optional) - commands to generate static PLIST fragments
## PKG_INSTALLATION_TYPE - "pkgviews" or "overwrite"
## PLIST - filename for final PLIST
## PLIST_SRC - source files for final PLIST
## PLIST_SUBST - substitutions that should be made when transforming
## PLIST_TYPE - "dynamic" or "static"
## SHLIB_HANDLING - "YES" or "NO"
## USE_LANGUAGES - if non-empty, implies shlib handling
#
# Targets defined:
#
## ${PLIST}
## do-shlib-handling (internal only)
## plist (convenience form of ${PLIST})
## print-PLIST (user only)
## show-shlib-type (user only)
#

.if ${PKG_INSTALLATION_TYPE} == "pkgviews"
#
# _PLIST_IGNORE_FILES basically mirrors the list of ignored files found
# in pkg_views(1).  It's used by the dynamic PLIST generator to skip
# adding the named files to the PLIST.
#
_PLIST_IGNORE_FILES=	+*			# package metadata files
_PLIST_IGNORE_FILES+=	info/dir
.  if defined(INFO_DIR) && empty(INFO_DIR:Minfo)
_PLIST_IGNORE_FILES+=	${INFO_DIR}/dir
.  endif
_PLIST_IGNORE_FILES+=	*[~\#] *.OLD *.orig *,v # scratch config files
_PLIST_IGNORE_FILES+=	${PLIST_IGNORE_FILES}

PKG_ARGS_INSTALL+=	-U	# don't update the pkgdb.byfile.db
PKG_ARGS_BINPKG+=	-E	# create an empty views file in the binpkg
.endif # PKG_INSTALLATION_TYPE

BUILD_DEFS_FIXED+=	_PLIST_IGNORE_FILES

# Macro to print out the actual shared library type.
.if !empty(USE_LANGUAGES)
.  if ${_OPSYS_SHLIB_TYPE} == "ELF/a.out"
.    if (${OBJECT_FMT} == "ELF" || ${OBJECT_FMT} == "a.out")
_GET_SHLIB_TYPE=	${ECHO} '${OBJECT_FMT}' # speedup if already known
.    else
_GET_SHLIB_TYPE=\
	@cd ${WRKDIR} &&						\
	sotype=none;							\
	if [ "X${MKPIC}" != "Xno" -a "X${NOPIC}" = "X" ]; then		\
		${ECHO} "int main() { return(0); }" > a.$$$$.c;		\
		${SETENV} PATH=${PATH}					\
		${CC} ${CFLAGS} a.$$$$.c -o a.$$$$.out;			\
		case `${FILE_CMD} a.$$$$.out` in			\
		*ELF*dynamically*)					\
			sotype=ELF ;;					\
		*shared*library*|*dynamically*)				\
			sotype="a.out" ;;				\
		esac;							\
	fi;								\
	${ECHO} "$$sotype";						\
	${RM} -f a.$$$$.c a.$$$$.out
.    endif
.  else
_GET_SHLIB_TYPE=	${ECHO} '${_OPSYS_SHLIB_TYPE}'
.  endif
.endif
_GET_SHLIB_TYPE?=	${ECHO} none

# Not to be used by pkgsrc; available for human inspection only.
show-shlib-type:
	@${_GET_SHLIB_TYPE}

# Do handling of shared libs for two cases:
#
# SHLIB_PLIST_MODE=1: when first called via the ${PLIST} target,
#                     update the PLIST to contain ELF symlink, run
#                     ldconfig on a.out,  etc. (used when called via
#                     the ${PLIST} target). Will update ${PLIST}.
# SHLIB_PLIST_MODE=0: when called via the real-su-install target,
#                     actually generate symlinks for ELF, run ldconfig
#                     for a.out, etc. Will not modify ${PLIST}.
#
# XXX This target could need some cleanup after it was ripped out of
#     real-su-install
#
_AOUT_AWK = \
	BEGIN { linkc = 1 }			\
	/^@/ { lines[NR] = $$0; next }		\
	function libtool_release(lib) {		\
		if (gsub("-[^-]+\\.so\\.", ".so.", lib)) { \
			if (system("${TEST} -h ${PREFIX}/" lib) == 0) { \
				rels[NR] = lib; \
			}			\
		}				\
	}					\
	/.*\/lib[^\/]+\.so\.[0-9]+\.[0-9]+\.[0-9]+$$/ { \
		libtool_release($$0);		\
		lines[NR] = $$0;		\
		sub("\\.[0-9]+$$", "");		\
		links[linkc++] = $$0;		\
		sub("\\.[0-9]+$$", "");		\
		links[linkc++] = $$0;		\
		sub("\\.[0-9]+$$", "");		\
		links[linkc++] = $$0;		\
		if (sub("-[^-]+\\.so$$", ".so")) { \
			links[linkc++] = $$0;	\
		}				\
		next				\
	}					\
	/.*\/lib[^\/]+\.so\.[0-9]+\.[0-9]+$$/ {	\
		libtool_release($$0);		\
		lines[NR] = $$0;		\
		sub("\\.[0-9]+$$", "");		\
		links[linkc++] = $$0;		\
		sub("\\.[0-9]+$$", "");		\
		links[linkc++] = $$0;		\
		if (sub("-[^-]+\\.so$$", ".so")) { \
			links[linkc++] = $$0;	\
		}				\
		next				\
	}					\
	{ lines[NR] = $$0 }			\
	END {					\
		for (i = 0 ; i <= linkc ; i++)	\
			for (j = 1 ; j < NR ; j++) \
				if (lines[j] == links[i]) \
					lines[j] = "@comment " lines[j]; \
		if (${SHLIB_PLIST_MODE}) 	\
			for (i = 1 ; i <= NR ; i++) { \
				print lines[i]; \
				if (rels[i] != "") \
					print rels[i]; \
			}			\
	}

_DYLIB_AWK= \
	/^@/ { lines[NR] = $$0; next }		\
		function libtool_release(lib) {		\
		if (gsub("\\.so\\.", ".", lib) || gsub("\\.so$$", "", lib)) { \
			lib = lib ".dylib"; \
			if (system("${TEST} -h ${PREFIX}/" lib) == 0) { \
				rels[NR] = lib; \
			}			\
		}				\
	}					\
	/.*\/lib[^\/]+\.so\.[0-9]+\.[0-9]+\.[0-9]+$$/ { \
		libtool_release($$0);		\
		lines[NR] = $$0;		\
		links[linkc++] = $$0;		\
		sub("\\.[0-9]+$$", "");		\
		links[linkc++] = $$0;		\
		sub("\\.[0-9]+$$", "");		\
		links[linkc++] = $$0;		\
		sub("\\.[0-9]+$$", "");		\
		links[linkc++] = $$0;		\
		if (sub("-[^-]+\\.so$$", ".so")) { \
			links[linkc++] = $$0;	\
		}				\
		next				\
	}					\
	/.*\/lib[^\/]+\.so\.[0-9]+\.[0-9]+$$/ {	\
		libtool_release($$0);		\
		lines[NR] = $$0;		\
		links[linkc++] = $$0;		\
		sub("\\.[0-9]+$$", "");		\
		links[linkc++] = $$0;		\
		sub("\\.[0-9]+$$", "");		\
		links[linkc++] = $$0;		\
		if (sub("-[^-]+\\.so$$", ".so")) { \
			links[linkc++] = $$0;	\
		}				\
		next				\
	}					\
	/.*\/lib[^\/]+\.so\.[0-9]+$$/ {		\
		libtool_release($$0);		\
		lines[NR] = $$0;		\
		links[linkc++] = $$0;		\
		sub("\\.[0-9]+$$", "");		\
		links[linkc++] = $$0;		\
		if (sub("-[^-]+\\.so$$", ".so")) { \
			links[linkc++] = $$0;	\
		}				\
		next				\
	}					\
	/.*\/lib[^\/]+\.so$$/ {			\
		lines[NR] = $$0;		\
		if (system("${TEST} -f ${PREFIX}/" $$0) == 0) { \
			next;			\
		}				\
		libtool_release($$0);		\
		links[linkc++] = $$0;		\
		if (sub("-[^-]+\\.so$$", ".so")) { \
			links[linkc++] = $$0;	\
		}				\
		next				\
	}					\
	{ lines[NR] = $$0 }			\
	END {					\
		for (i = 0 ; i <= linkc ; i++)	\
			for (j = 1 ; j <= NR ; j++) \
				if (lines[j] == links[i]) \
					lines[j] = "@comment " lines[j]; \
		if (${SHLIB_PLIST_MODE}) 	\
			for (i = 1 ; i <= NR ; i++) { \
				print lines[i]; \
				if (rels[i] != "") { \
					print rels[i]; \
					cmd = "${LS} -l ${PREFIX}/" rels[i]; \
					cmd | getline tgt; \
					close(cmd); \
					gsub(".* ", "", tgt); \
					if (tgts[tgt] == "") { \
						tgts[tgt] = tgt; \
						if (index(tgt, "/") == 1) \
							print tgt; \
						else { \
							prefix=""; \
							if (match(rels[i], ".*/") != 0) \
								prefix=substr(rels[i],1,RLENGTH); \
							print prefix tgt; \
						} \
					}	\
				}		\
			}			\
	}

# Turn lib*.so.*, lib*.so into lib*.so.  Drop duplicates.
_AIXLIB_AWK= \
	/^@/ { lines[NR] = $$0; next }		\
	/.*\/lib[^\/]+\.so(\.[0-9]+)*$$/ {	\
		sub("(\\.[0-9]+)*$$", "");	\
		sub("\\.so$$", ".so");       	\
		lines[NR] = $$0;     		\
		next				\
	}					\
	{ lines[NR] = $$0 }			\
	END {					\
		nlibs = 0;			\
		for (i = 1; i <= NR; i++) {	\
			for (j = 0; j < nlibs; j++) { \
				if (libs[j] == lines[i]) \
					break;	\
			}			\
			if (j >= nlibs)		\
				print lines[i];	\
			if (match(lines[i], ".*/lib[^/]+\\.a$$")) { \
				libs[nlibs] = lines[i]; \
				nlibs++;	\
			}			\
		}				\
	}

# XXX tv: should somehow be a variable, not a recursive target
.PHONY: do-shlib-handling
do-shlib-handling:
.if ${SHLIB_HANDLING} == "YES"
	${_PKG_SILENT}${_PKG_DEBUG}					\
	sos=`${EGREP} -h '^.*/lib[^/]+\.so$$' ${PLIST} || ${TRUE}`;	\
	if [ "$$sos" != "" ]; then					\
		shlib_type=`${_GET_SHLIB_TYPE}`;			\
		if [ "${SHLIB_PLIST_MODE}" = "0" ]; then 		\
			${ECHO_MSG} "${_PKGSRC_IN}> [Automatic $$shlib_type shared object handling]"; \
		fi;  							\
		case "$$shlib_type" in					\
		ELF) 	;;						\
		"a.out") 						\
			${AWK} '${_AOUT_AWK}' <${PLIST} >${PLIST}.tmp ;	\
			if [ "${SHLIB_PLIST_MODE}" = "1" ]; then	\
				${MV} ${PLIST}.tmp ${PLIST};		\
			else 						\
				${RM} ${PLIST}.tmp ;			\
			fi ; 						\
			cnt=`${EGREP} -c '^@exec[ 	]*${LDCONFIG}$$' ${PLIST} || ${TRUE}`; \
			if [ "${SHLIB_PLIST_MODE}" = "1" ]; then 	\
				if [ $$cnt -eq 0 ]; then		\
					${ECHO} "@exec ${LDCONFIG}" >> ${PLIST}; \
					${ECHO} "@unexec ${LDCONFIG}" >> ${PLIST}; \
				fi					\
			fi;						\
			if [ "${SHLIB_PLIST_MODE}" = "0" ]; then	\
				if [ "${PKG_VERBOSE}" != "" ]; then	\
					${ECHO_MSG} "$$sos";		\
					${ECHO_MSG} "Running ${LDCONFIG}"; \
				fi;					\
				${LDCONFIG} || ${TRUE};			\
			fi						\
			;;						\
		"dylib")						\
			${AWK} '${_DYLIB_AWK}' <${PLIST} >${PLIST}.tmp && \
			if [ "${SHLIB_PLIST_MODE}" = "1" ]; then	\
				${MV} ${PLIST}.tmp ${PLIST};		\
			else						\
				${RM} ${PLIST}.tmp ;			\
			fi ;						\
			;;						\
		"aixlib")						\
			${AWK} '${_AIXLIB_AWK}' <${PLIST} >${PLIST}.tmp && \
			${MV} ${PLIST}.tmp ${PLIST};			\
			;;						\
		"*")							\
			if [ "${SHLIB_PLIST_MODE}" = "0" ]; then 	\
				${ECHO_MSG} "No shared libraries for ${MACHINE_ARCH}"; \
			fi ; 						\
			if [ "${SHLIB_PLIST_MODE}" = "1" ]; then	\
				for so in $$sos; do			\
					if [ X"${PKG_VERBOSE}" != X"" ]; then \
						${ECHO_MSG} >&2 "Ignoring $$so"; \
					fi;				\
					${SED} -e "s;^$$so$$;@comment No shared objects - &;" \
						${PLIST} >${PLIST}.tmp && ${MV} ${PLIST}.tmp ${PLIST};	\
				done;					\
			fi ;						\
			;;						\
		esac;							\
	fi
.endif # SHLIB_HANDLING == "YES"

#
# print-PLIST: Automatic PLIST generation
#  - files & symlinks first
#  - @dirrm statements last
#  - empty directories are handled properly
#  - dirs from mtree files are excluded
#  - substitute for platform or package specifics substrings
#
# Usage:
#  - make install
#  - make print-PLIST | brain >PLIST
#

_PRINT_PLIST_AWK_SUBST={						\
	gsub(/${OPSYS}/, "$${OPSYS}");					\
	gsub(/${OS_VERSION:S/./\./g}/, "$${OS_VERSION}");		\
	gsub(/${MACHINE_GNU_PLATFORM}/, "$${MACHINE_GNU_PLATFORM}");	\
	gsub(/${MACHINE_ARCH}/, "$${MACHINE_ARCH}");			\
	gsub(/${MACHINE_GNU_ARCH}/, "$${MACHINE_GNU_ARCH}");
.if !empty(LOWER_VENDOR)
_PRINT_PLIST_AWK_SUBST+=	gsub(/${LOWER_VENDOR}/, "$${LOWER_VENDOR}");
.endif
_PRINT_PLIST_AWK_SUBST+=						\
	gsub(/${LOWER_OS_VERSION:S/./\./g}/, "$${LOWER_OS_VERSION}");	\
	gsub(/${LOWER_OPSYS}/, "$${LOWER_OPSYS}");			\
	gsub(/${PKGNAME_NOREV}/, "$${PKGNAME}");			\
	gsub(/${PKGVERSION:S/./\./g:C/nb[0-9]*$$//}/, "$${PKGVERSION}");\
	gsub(/${PKGLOCALEDIR}\/locale/, "$${PKGLOCALEDIR}/locale");	\
}

_PRINT_PLIST_AWK_IGNORE=	($$0 ~ /emul\/linux\/proc/)
_PRINT_PLIST_AWK_IGNORE+=	|| ($$0 ~ /^info\/dir$$/)
.if defined(INFO_DIR) && empty(INFO_DIR:Minfo)
_PRINT_PLIST_AWK_IGNORE+=	|| ($$0 ~ /^${INFO_DIR:S|/|\\/|g}\/dir$$/)
.endif
.if !empty(INFO_FILES)
.  for _f_ in ${INFO_FILES}
_PRINT_PLIST_AWK_IGNORE+=      || ($$0 ~ /^${INFO_DIR:S|/|\\/|g}\/${_f_:S|+|\+|g}(-[0-9]+)?(\.gz)?$$/)
.  endfor
.endif

# Common (system) directories not to generate @dirrm statements for
# Reads MTREE_FILE and generate awk statements that will
# sort out which directories NOT to include into the PLIST @dirrm list
.if make(print-PLIST)
_PRINT_PLIST_COMMON_DIRS!= 	${AWK} 'BEGIN  {			\
			i=0; 						\
			stack[i]="${PREFIX}" ; 				\
			cwd=""; 					\
		} 							\
		! ( /^\// || /^\#/ || /^$$/ ) { 			\
			if ( $$1 == ".." ){ 				\
				i=i-1;					\
				cwd = stack[i];				\
			} else if ( $$1 == "." ){ 			\
			} else {					\
				stack[i] = cwd ;			\
				if ( i == 0 ){ 				\
					cwd = $$1 ; 			\
				} else {				\
					cwd = cwd "\\/" $$1 ; 	\
				} 					\
				print "/^" cwd "$$$$/ { next; }";	\
				i=i+1 ; 				\
			} 						\
		} 							\
		END { print "{ print $$$$0; }"; }			\
	' <${MTREE_FILE}
.endif

# scan $PREFIX for any files/dirs modified since the package was extracted
# will emit "@exec mkdir"-statements for empty directories
# XXX will fail for data files that were copied using tar (e.g. emacs)!
# XXX should check $LOCALBASE and $X11BASE, and add @cwd statements

_PRINT_PLIST_FILES_CMD=	\
	${FIND} ${PREFIX}/. -xdev -newer ${extract_COOKIE} \! -type d -print
_PRINT_PLIST_DIRS_CMD=	\
	${FIND} ${PREFIX}/. -xdev -newer ${extract_COOKIE} -type d -print
_PRINT_LA_LIBNAMES=	${SETENV} ECHO=${ECHO:Q} GREP=${GREP:Q} SORT=${SORT:Q} \
			${SH} ${.CURDIR}/../../mk/scripts/print-la-libnames

.if !empty(LIBTOOLIZE_PLIST:M[yY][eE][sS])
_PRINT_PLIST_LIBTOOLIZE_FILTER?=					\
	(								\
	  if ${TEST} -d ${WRKDIR}; then					\
	  	tmpdir="${WRKDIR}";					\
	  else								\
	  	tmpdir="$${TMPDIR-/tmp}";				\
	  fi;								\
	  fileslist="$$tmpdir/print.plist.files.$$$$";			\
	  libslist="$$tmpdir/print.plist.libs.$$$$";			\
	  while read file; do						\
		case $$file in						\
		*.la)							\
			${_PRINT_LA_LIBNAMES} $$file >> $$libslist;	\
			;;						\
		esac;							\
		${ECHO} "$$file";					\
	  done > $$fileslist;						\
	  if ${TEST} -f "$$libslist"; then				\
	  	${GREP} -hvxF "`${SORT} -u $$libslist`" "$$fileslist";	\
	  else								\
	  	${CAT} "$$fileslist";					\
	  fi;								\
	  ${RM} -f "$$fileslist" "$$libslist";				\
	)
.else
_PRINT_PLIST_LIBTOOLIZE_FILTER?=	${CAT}
.endif

.PHONY: print-PLIST
print-PLIST:
	${_PKG_SILENT}${_PKG_DEBUG}\
	${ECHO} '@comment $$'NetBSD'$$'
	${_PKG_SILENT}${_PKG_DEBUG}\
	shlib_type=`${_GET_SHLIB_TYPE}`;				\
	case $$shlib_type in 						\
	"a.out")	genlinks=1 ;;					\
	*)		genlinks=0 ;;					\
	esac;								\
	${_PRINT_PLIST_FILES_CMD}					\
	 | ${_PRINT_PLIST_LIBTOOLIZE_FILTER}				\
	 | ${SORT}							\
	 | ${AWK} '							\
		{ sub("${PREFIX}/\\./", ""); }				\
		${_PRINT_PLIST_AWK_IGNORE} { next; } 			\
		${_PRINT_PLIST_AWK_SUBST}				\
		/^@/ { print $$0; next }				\
		/.*\/lib[^\/]+\.so\.[0-9]+\.[0-9]+\.[0-9]+$$/ { 	\
			print $$0;					\
			sub("\\.[0-9]+$$", "");				\
			if ('$$genlinks') print $$0;			\
			sub("\\.[0-9]+$$", "");				\
			if ('$$genlinks') print $$0;			\
			sub("\\.[0-9]+$$", "");				\
			if ('$$genlinks') print $$0;			\
			next;						\
		}							\
		/.*\/lib[^\/]+\.so\.[0-9]+\.[0-9]+$$/ { 		\
			print $$0;					\
			sub("\\.[0-9]+$$", "");				\
			if ('$$genlinks') print $$0;			\
			sub("\\.[0-9]+$$", "");				\
			if ('$$genlinks') print $$0;			\
			next;						\
		}							\
		${PRINT_PLIST_AWK}					\
		{ print $$0; }'
	${_PKG_SILENT}${_PKG_DEBUG}\
	for i in `${_PRINT_PLIST_DIRS_CMD}				\
			| ${SORT} -r					\
			| ${AWK} '					\
				/emul\/linux\/proc/ { next; }		\
				/${PREFIX:S|/|\\/|g}\/\.$$/ { next; }	\
				{ sub("${PREFIX}/\\\\./", ""); }	\
				${_PRINT_PLIST_COMMON_DIRS}'` ;		\
	do								\
		if [ `${LS} -la ${PREFIX}/$$i | ${WC} -l` = 3 ]; then	\
			${ECHO} @exec \$${MKDIR} %D/$$i | ${AWK} '	\
			${PRINT_PLIST_AWK}				\
			{ print $$0; }' ;				\
		fi ;							\
		${ECHO} @dirrm $$i | ${AWK} '				\
			${PRINT_PLIST_AWK}				\
			{ print $$0; }' ;				\
	done								\
	| ${AWK} '${_PRINT_PLIST_AWK_SUBST} { print $$0; }'

#
# generate ${PLIST} from ${PLIST_SRC} by:
# - substituting for PLIST_SUBST entries
# - fixing list of man-pages according to MANZ, MANINSTALL.
# - adding symlinks for shared libs (ELF) or ldconfig calls (a.out).
#

# plist awk pattern-action statement to handle MANINSTALL
_PLIST_AWK_MANINSTALL=							\
{									\
	if (!"${MANINSTALL:Mmaninstall}" &&				\
		match($$0, "^([^/]*/)*man/([^/]*/)?man[1-9ln]") ) {	\
			next;						\
	}								\
	if (!"${MANINSTALL:Mcatinstall}" &&				\
		match($$0, "^([^/]*/)*man/([^/]*/)?cat[1-9ln]") ) {	\
			next;						\
	}								\
}

# plist awk pattern-action statement to strip '.gz' from man
# entries
_PLIST_AWK_STRIP_MANZ=							\
/^([^\/]*\/)*man\/([^\/]*\/)?(man[1-9ln]\/.*[1-9ln]|cat[1-9ln]\/.*0)\.gz$$/ { \
	$$0 = substr($$0, 1, length($$0) - 3);				\
}

# plist awk pattern-action statement to add '.gz' to man entries
_PLIST_AWK_ADD_MANZ=							\
/^([^\/]*\/)*man\/([^\/]*\/)?(man[1-9ln]\/.*[1-9ln]|cat[1-9ln]\/.*0)$$/ { \
	$$0 = $$0 ".gz";						\
}

# plist awk pattern-action statement to handle PLIST_SUBST substitutions
# BEWARE: the awk script quote is closed and reopened around the
# string argument of gsub() calls so historic quoting semantic of
# PLIST_SUBST is preserved.
# XXX `_str_quote_{start,end}_' is a gross hack to work around weird word
# splitting.
_PLIST_AWK_SUBST= { ${PLIST_SUBST:S|=|\\}/,_str_quote_start_|:S|$|_str_quote_end_);|:S|^|gsub(/\\\$\\{|:S|_str_quote_start_|"'|g:S|_str_quote_end_|'"|g} }

# plist awk pattern-action statement to rewrite "imake installed" catman pages
# as plain manpages.
_PLIST_AWK_IMAKE_MAN=							\
/^([^\/]*\/)*man\/([^\/]*\/)?cat[1-9ln]\/.*0$$/ {			\
	n = match($$0, "/cat[1-9ln]");					\
	sect = sprintf(".%s", substr($$0, n + 4, 1));			\
	sub("/cat", "/man");						\
	sub("\\.0$$", sect);						\
}

# plist awk pattern-action statement to handle info files:
# generate list of files matching
# ${PREFIX}/${INFO_DIR}/filename(-[0-9]+)?(.gz)?
# for `filename' being each word of INFO_FILES in turn.
# Notes:
# - first the filenames matching ${PREFIX}/${INFO_DIR}/filename*
# are generated with ls then they are filtered by the exact pattern.
# - ${PREFIX}/${INFO_DIR}/filename is single quoted and single quote
# escaped
# XXX When all info file entries will be removed from PLIST files
# the non-BEGIN pattern-action statements generated below will be retired.
_PLIST_AWK_INFO=
.if ${PLIST_TYPE} == "static"
.  if !empty(INFO_FILES)
.    for _f_ in ${INFO_FILES}
_PLIST_AWK_INFO+=							\
BEGIN {									\
	cmd="${_f_}"; gsub("'\''", "\\'\''", cmd);			\
	sub("^", "${LS} '\''${PREFIX}/${INFO_DIR}/", cmd);		\
	sub("$$", "'\''*", cmd);					\
	while ((cmd | getline l) > 0) {					\
		if (match(l, ".*/${_f_:S|+|\\\+|g}(-[0-9]+)?(\\.gz)?$$")) { \
			sub("^${PREFIX}/", "", l);			\
			print l;					\
		}							\
	}								\
	close(cmd);							\
}									\
/^${INFO_DIR:S|/|\\/|g}\/${_f_}(-[0-9]+)?$$/ { next; }
.    endfor
.  endif
.endif

# plist awk pattern-action statement to expand libtool archives into
# shared and/or static libraries.
#
.if ${PLIST_TYPE} == "dynamic"
_PLIST_AWK_LIBTOOL?=	# empty
.elif empty(LIBTOOLIZE_PLIST:M[yY][eE][sS])
BROKEN+=		"USE_LIBTOOL requires LIBTOOLIZE_PLIST=yes for proper PLIST generation"
.else
_PLIST_AWK_LIBTOOL?=							\
/^[^@].*\.la$$/ {							\
	system("cd ${PREFIX} && ${_PRINT_LA_LIBNAMES} " $$0)		\
}
.endif

# _PLIST_AWK_SCRIPT hold the complete awk script for plist target.
#
_PLIST_AWK_SCRIPT=	'
# Do the substitutions
# See comments above about _PLIST_AWK_SUBST: it contains single quotes!
# So _PLIST_AWK_SCRIPT is intended to be single quoted.
_PLIST_AWK_SCRIPT+=	${_PLIST_AWK_SUBST}
# Generated entries for info files
.if !empty(INFO_FILES)
_PLIST_AWK_SCRIPT+=	${_PLIST_AWK_INFO}
.endif
# Expand libtool archives
_PLIST_AWK_SCRIPT+=	${_PLIST_AWK_LIBTOOL}
# Strip the '.gz' suffixes on man entries
_PLIST_AWK_SCRIPT+=	${_PLIST_AWK_STRIP_MANZ}
# Deal with MANINSTALL and man entries
_PLIST_AWK_SCRIPT+=	${_PLIST_AWK_MANINSTALL}
# Deal with "imake installed" catman pages
.if defined(USE_IMAKE) && ${_PREFORMATTED_MAN_DIR} == "man"
_PLIST_AWK_SCRIPT+=	${_PLIST_AWK_IMAKE_MAN}
.endif
# Add '.gz' suffixes on man entries if needed
.if defined(MANZ)
_PLIST_AWK_SCRIPT+=	${_PLIST_AWK_ADD_MANZ}
.endif
# Print the entry
_PLIST_AWK_SCRIPT+=	{ print $$0; }
#
_PLIST_AWK_SCRIPT+=	'

# GENERATE_PLIST is a sequence of commands, terminating in a semicolon,
#	that outputs contents for a PLIST to stdout and is appended to
#	the contents of ${PLIST_SRC}.
#
GENERATE_PLIST?=	${TRUE};
.if ${PLIST_TYPE} == "dynamic"
_PLIST_IGNORE_CMD=							\
	( while read i; do						\
		ignore=no;						\
		for p in ${_PLIST_IGNORE_FILES}; do			\
	  		case "$$i" in					\
			$$p)	ignore=yes; break ;;			\
			esac;						\
		done;							\
		[ "$$ignore" = "yes" ] || ${ECHO} "$$i";		\
	  done )
_GENERATE_PLIST=							\
	${FIND} ${PREFIX} \! -type d -print | ${SORT} |			\
		${SED} -e "s|^${PREFIX}/||" | 				\
		${_PLIST_IGNORE_CMD};					\
	${FIND} ${PREFIX} -type d -print | ${SORT} -r |			\
		${GREP} -v "^${PREFIX}$$" |				\
		${_PLIST_IGNORE_CMD} |					\
		${SED} -e "s|^${PREFIX}/|@unexec ${RMDIR} -p %D/|"	\
		       -e "s,$$, 2>/dev/null || ${TRUE},";
.else
_GENERATE_PLIST=	${CAT} ${PLIST_SRC}; ${GENERATE_PLIST}
.endif

.if ${PLIST_TYPE} == "static"
${PLIST}: ${PLIST_SRC}
.endif
${PLIST}:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	{ ${_GENERATE_PLIST} } | ${AWK} ${_PLIST_AWK_SCRIPT}		\
		> ${PLIST}; 						\
	  ${MAKE} ${MAKEFLAGS} do-shlib-handling			\
		SHLIB_PLIST_MODE=1
