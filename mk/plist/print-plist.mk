# $NetBSD: print-plist.mk,v 1.35 2020/04/18 10:54:21 rillig Exp $
#
# Automatic PLIST generation
#  - files & symlinks first
#  - empty directories are handled properly
#  - dirs from mtree files are excluded
#  - substitute for platform or package specifics substrings
#
# Usage:
#  - make install
#  - make print-PLIST | brain >PLIST
#
# Keywords: plist print-plist

_PRINT_PLIST_AWK_SUBST={
_PRINT_PLIST_AWK_SUBST+=						\
	gsub(/${PKGNAME_NOREV}/, "$${PKGNAME}");			\
	gsub(/${PKGVERSION:S/./\./g:C/nb[0-9]*$$//}/, "$${PKGVERSION}");\
	gsub(/^${PKGLOCALEDIR}\/locale/, "share/locale");		\
	gsub("^${PKGGNUDIR:S/\/$$//}/", "gnu/");			\
	gsub("^${PKGINFODIR}/", "info/");				\
	gsub("^${PKGMANDIR}/", "man/");

_PRINT_PLIST_AWK_SUBST+=}

_PRINT_PLIST_AWK_IGNORE=	($$0 ~ /^${PKG_DBDIR:S|^${PREFIX}/||:S|/|\\/|g}\//)
_PRINT_PLIST_AWK_IGNORE+=	|| ($$0 ~ /emul\/linux\/proc/)
.if defined(INFO_FILES)
_PRINT_PLIST_AWK_IGNORE+=	|| ($$0 ~ /^${PKGINFODIR:S|/|\\/|g}\/dir$$/)
_PRINT_PLIST_AWK_IGNORE+=	|| ($$0 ~ /^${PKGINFODIR:S|/|\\/|g}\/[^\/]+(-[0-9]+)(\.gz)?$$/)
_PRINT_PLIST_AWK_IGNORE+=	|| ($$0 ~ /^([^\/]*\/)*(info\/[^\/]+|[^\/]+\.info)(-[0-9]+)(\.gz)?$$/)
.endif
.if (defined(FONTS_DIRS.x11) && !empty(FONTS_DIRS.x11:M*))
_PRINT_PLIST_AWK_IGNORE+=	|| ($$0 ~ /^.*\/encodings\.dir/)
_PRINT_PLIST_AWK_IGNORE+=	|| ($$0 ~ /^.*\/fonts\.dir/)
.endif
.if (defined(FONTS_DIRS.ttf) && !empty(FONTS_DIRS.ttf:M*)) || \
    (defined(FONTS_DIRS.type1) && !empty(FONTS_DIRS.type1:M*))
_PRINT_PLIST_AWK_IGNORE+=	|| ($$0 ~ /^.*\/fonts\.scale/)
.endif
.if (defined(FONTS_DIRS.ttf) && !empty(FONTS_DIRS.ttf:M*)) || \
    (defined(FONTS_DIRS.type1) && !empty(FONTS_DIRS.type1:M*)) || \
    (defined(FONTS_DIRS.x11) && !empty(FONTS_DIRS.x11:M*))
_PRINT_PLIST_AWK_IGNORE+=	|| ($$0 ~ /^.*\/fonts\.cache-1/)
.endif
.if defined(ICON_THEMES)
_PRINT_PLIST_AWK_IGNORE+=	|| ($$0 ~ /^share\/icons\/*\/icon-theme\.cache$$/)
.endif

# List the content of $PREFIX and emit "@pkgdir " statements for
# empty directories.
_PRINT_PLIST_FILES_CMD=	\
	${FIND} ${DESTDIR}${PREFIX}/. \! -type d -print
_PRINT_PLIST_DIRS_CMD=	\
	${FIND} ${DESTDIR}${PREFIX}/. -type d -print

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
	${RUN} ${ECHO} '@comment $$'NetBSD'$$'
	${RUN} ${ALL_ENV};						\
	shlib_type=${SHLIB_TYPE:Q};					\
	case $$shlib_type in 						\
	"a.out")	genlinks=1 ;;					\
	*)		genlinks=0 ;;					\
	esac;								\
	${_PRINT_PLIST_FILES_CMD}					\
	 | ${_PRINT_PLIST_LIBTOOLIZE_FILTER}				\
	 | ${SORT}							\
	 | ${AWK} '							\
		{ sub("${DESTDIR:S|+|\\\\+|g}${PREFIX}/\\./", ""); }	\
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
		/^man\// { sub("\\.gz$$", ""); }			\
		{ print $$0; }'
	${RUN}\
	for i in `${_PRINT_PLIST_DIRS_CMD}				\
			| ${SORT} -r					\
			| ${AWK} '					\
				/emul\/linux\/proc/ { next; }		\
				/${DESTDIR:S|/|\\/|g:S/+/\\\\+/g}${PREFIX:S|/|\\/|g}\/\.$$/ { next; }	\
				/${PKG_DBDIR:S|/|\\/|g}\// { next; }	\
				{ sub("${DESTDIR:S/+/\\\\\\+/g}${PREFIX}/\\\\./", ""); }	\
				{ sub("^${PKGINFODIR}/", "info/"); }	\
				{ sub("^${PKGMANDIR}/", "man/"); }	\
				/^${PKG_DBDIR:S|^${PREFIX}/||:S|/|\\/|g}(\/|$$)/ { next; } \
				/^${PKGINFODIR:S|/|\\/|g}$$/ { next; }	\
				{ print $$0; }'` ;			\
	do								\
		if [ `${LS} -la ${DESTDIR}${PREFIX}/$$i | ${WC} -l` = 3 ]; then	\
			${ECHO} @pkgdir $$i | ${AWK} '			\
			${PRINT_PLIST_AWK}				\
			{ print $$0; }' ;				\
		fi ;							\
	done								\
	| ${AWK} '${_PRINT_PLIST_AWK_SUBST} { print $$0; }'
.endif # target(print-PLIST)

_VARGROUPS+=		print-PLIST
_PKG_VARS.print-PLIST=	\
	PKGNAME_NOREV PKGVERSION \
	PKGLOCALEDIR PKGGNUDIR PKGINFODIR PKGMANDIR PKG_DBDIR \
	FONTS_DIRS.x11 FONTS_DIRS.ttf FONTS_DIRS.type1 \
	INFO_FILES ICON_THEMES PRINT_PLIST_AWK
_SYS_VARS.print-PLIST=	\
	PREFIX DESTDIR LIBTOOLIZE_PLIST SHLIB_TYPE WRKDIR
_USE_VARS.print-PLIST=	ALL_ENV
_IGN_VARS.print-PLIST=	_*
_LISTED_VARS.print-PLIST= \
	*_SUBST *_AWK
_SORTED_VARS.print-PLIST= \
	*_ENV
