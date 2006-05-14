# $NetBSD: print-plist.mk,v 1.8 2006/05/14 14:27:41 seb Exp $

###
### Automatic PLIST generation
###  - files & symlinks first
###  - @dirrm statements last
###  - empty directories are handled properly
###  - dirs from mtree files are excluded
###  - substitute for platform or package specifics substrings
###
### Usage:
###  - make install
###  - make print-PLIST | brain >PLIST
###

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
	gsub(/^${PKGLOCALEDIR}\/locale/, "share/locale");		\
	gsub(/^@dirrm ${PKGLOCALEDIR}\/locale/, "@dirrm share/locale");	\
	gsub("^${PKGINFODIR}\/", "info/");				\
	gsub("^${PKGMANDIR}\/", "man/");				\
}

_PRINT_PLIST_AWK_IGNORE=	($$0 ~ /^${PKG_DBDIR:S|^${PREFIX}/||:S|/|\\/|g}\//)
_PRINT_PLIST_AWK_IGNORE+=	|| ($$0 ~ /emul\/linux\/proc/)
.if defined(INFO_FILES)
_PRINT_PLIST_AWK_IGNORE+=	|| ($$0 ~ /^${PKGINFODIR:S|/|\\/|g}\/dir$$/)
_PRINT_PLIST_AWK_IGNORE+=	|| ($$0 ~ /^${PKGINFODIR:S|/|\\/|g}\/[^\/]+(-[0-9]+)(\.gz)?$$/)
_PRINT_PLIST_AWK_IGNORE+=	|| ($$0 ~ /^([^\/]*\/)*(info\/[^\/]+|[^\/]+\.info)(-[0-9]+)(\.gz)?$$/)
.endif

# Common (system) directories not to generate @dirrm statements for
# Reads MTREE_FILE and generate awk statements that will
# sort out which directories NOT to include into the PLIST @dirrm list
.if make(print-PLIST)
_PRINT_PLIST_COMMON_DIRS!=	${AWK} 'BEGIN {				\
			i=0;						\
			stack[i]="${PREFIX}" ;				\
			cwd="";						\
		}							\
		! ( /^\// || /^\#/ || /^$$/ ) {				\
			if ( $$1 == ".." ){				\
				i=i-1;					\
				cwd = stack[i];				\
			} else if ( $$1 == "." ){			\
			} else {					\
				stack[i] = cwd ;			\
				if ( i == 0 ){				\
					cwd = $$1 ;			\
				} else {				\
					cwd = cwd "\\/" $$1 ;		\
				}					\
				print "/^" cwd "$$$$/ { next; }";	\
				i=i+1 ;					\
			}						\
		}							\
		END { print "{ print $$$$0; }"; }			\
	' <${MTREE_FILE}
.endif

# scan $PREFIX for any files/dirs modified since the package was extracted
# will emit "@exec mkdir"-statements for empty directories
# XXX will fail for data files that were copied using tar (e.g. emacs)!
# XXX should check $LOCALBASE and $X11BASE, and add @cwd statements

_PRINT_PLIST_FILES_CMD=	\
	${FIND} ${PREFIX}/. -xdev -newer ${_EXTRACT_COOKIE} \! -type d -print
_PRINT_PLIST_DIRS_CMD=	\
	${FIND} ${PREFIX}/. -xdev -newer ${_EXTRACT_COOKIE} -type d -print

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
			${_LIBTOOL_EXPAND} $$file >> $$libslist;	\
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
.if !target(print-PLIST)
print-PLIST:
	${_PKG_SILENT}${_PKG_DEBUG}\
	${ECHO} '@comment $$'NetBSD'$$'
	${_PKG_SILENT}${_PKG_DEBUG}\
	shlib_type=${SHLIB_TYPE:Q};					\
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
		${PRINT_PLIST_AWK}					\
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
		{ print $$0; }'
	${_PKG_SILENT}${_PKG_DEBUG}\
	for i in `${_PRINT_PLIST_DIRS_CMD}				\
			| ${SORT} -r					\
			| ${AWK} '					\
				/emul\/linux\/proc/ { next; }		\
				/${PREFIX:S|/|\\/|g}\/\.$$/ { next; }	\
				/${PKG_DBDIR:S|/|\\/|g}\// { next; }	\
				{ sub("${PREFIX}/\\\\./", ""); }	\
				{ sub("^${PKGINFODIR}/", "info/"); }	\
				{ sub("^${PKGMANDIR}/", "man/"); }	\
				/^${PKG_DBDIR:S|^${PREFIX}/||:S|/|\\/|g}(\/|$$)/ { next; } \
				/^${PKGINFODIR:S|/|\\/|g}$$/ { next; }	\
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
.endif # target(print-PLIST)
