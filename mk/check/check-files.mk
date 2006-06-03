# $NetBSD: check-files.mk,v 1.1 2006/06/03 23:11:42 jlam Exp $

.if defined(PKG_DEVELOPER)
CHECK_FILES?=		yes
.endif

CHECK_FILES?=		no
CHECK_FILES_STRICT?=	no

###########################################################################
# CHECK_FILES_SKIP is a list of file names that will be skipped when
# analyzing file lists in the check-files target.  This is useful to
# avoid getting errors triggered by changes in directories not really
# handled by pkgsrc.

# Info index files updated when a new info file is added.
.if defined(INFO_FILES)
CHECK_FILES_SKIP+=	${PREFIX}/.*/dir$$$$
.endif

# Perl's perllocal.pod index that is regenerated when a local module
# is added.
#
CHECK_FILES_SKIP+=	${PERL5_INSTALLARCHLIB}/perllocal.pod

# R's index files that are regenerated when a local module
# is added.
#
CHECK_FILES_SKIP+=	${PREFIX}/lib/R/doc/html/packages.html
CHECK_FILES_SKIP+=	${PREFIX}/lib/R/doc/html/search/index.txt

# We don't care about what's under /proc in Linux emulation, which is
# just holds run-time generated data.
#
CHECK_FILES_SKIP+=	${PREFIX}/emul/linux/proc.*

# The reference-count meta-data directory used by the pkginstall framework.
CHECK_FILES_SKIP+=	${PKG_DBDIR}.refcount.*

# File that are outside of ${PREFIX} in directories we already know we'll
# be using for mutable data.
#
.for d in ${MAKE_DIRS} ${OWN_DIRS}
CHECK_FILES_SKIP+=	${d:C/^([^\/])/${PREFIX}\/\1/}.*
.endfor
.for d o g m in ${MAKE_DIRS_PERMS} ${OWN_DIRS_PERMS}
CHECK_FILES_SKIP+=	${d:C/^([^\/])/${PREFIX}\/\1/}.*
.endfor

# Mutable X11 font database files
.if (defined(FONTS_DIRS.ttf) && !empty(FONTS_DIRS.ttf:M*)) || \
    (defined(FONTS_DIRS.type1) && !empty(FONTS_DIRS.type1:M*)) || \
    (defined(FONTS_DIRS.x11) && !empty(FONTS_DIRS.x11:M*))
CHECK_FILES_SKIP+=	${PREFIX}/.*/fonts.alias
CHECK_FILES_SKIP+=	${PREFIX}/.*/fonts.dir
CHECK_FILES_SKIP+=	${PREFIX}/.*/fonts.scale
.endif

# Mutable charset.alias file
CHECK_FILES_SKIP+=	${PREFIX}/lib/charset.alias

_CHECK_FILES_SKIP_FILTER=	${GREP} -vx ${CHECK_FILES_SKIP:@f@-e ${f:Q}@}

###########################################################################
# These are the files generated and used by the check-files implementation
# used across several check-files targets.
#
#    _CHECK_FILES_COOKIE.* are the cookie files that contain the error
#	messages discovered during each stage of file-checking.
#
#    _CHECK_FILES_PRE.* are the file lists generated before any files
#	from the package are installed.
#
#    _CHECK_FILES_POST.* are the file lists generated after all files
#	from the package are installed.
#
# The "pre" and "post" file lists are compared against each other to
# determine if the package is installing files where it shouldn't be.
#
_CHECK_FILES_COOKIE.prefix=	${WRKDIR}/.check_files_prefix_cookie
_CHECK_FILES_PRE.prefix=	${WRKDIR}/.prefix.pre
_CHECK_FILES_POST.prefix=	${WRKDIR}/.prefix.post

_CHECK_FILES_COOKIE.sysconfdir=	${WRKDIR}/.check_files_sysconfdir_cookie
_CHECK_FILES_PRE.sysconfdir=	${WRKDIR}/.sysconfdir.pre
_CHECK_FILES_POST.sysconfdir=	${WRKDIR}/.sysconfdir.post

_CHECK_FILES_COOKIE.varbase=	${WRKDIR}/.check_files_varbase_cookie
_CHECK_FILES_PRE.varbase=	${WRKDIR}/.varbase.pre
_CHECK_FILES_POST.varbase=	${WRKDIR}/.varbase.post

_CHECK_FILES_COOKIES=		# empty
_CHECK_FILES_COOKIES+=		${_CHECK_FILES_COOKIE.prefix}
.if empty(CHECK_FILES_STRICT:M[nN][oO])
_CHECK_FILES_COOKIES+=		${_CHECK_FILES_COOKIE.sysconfdir}
_CHECK_FILES_COOKIES+=		${_CHECK_FILES_COOKIE.varbase}
.endif

###########################################################################
# _CHECK_FILES_PRE holds the list of targets that are built as part of
# building the check-files-pre target.  These targets should cause the
# "pre" file lists to be generated.
#
_CHECK_FILES_PRE=		check-files-pre-message
_CHECK_FILES_PRE+=		${_CHECK_FILES_PRE.prefix}
.if empty(CHECK_FILES_STRICT:M[nN][oO])
_CHECK_FILES_PRE+=		${_CHECK_FILES_PRE.sysconfdir}
_CHECK_FILES_PRE+=		${_CHECK_FILES_PRE.varbase}
.endif

###########################################################################
# _CHECK_FILES_POST holds the list of targets that are built as part of
# building the check-files-post target.  These targets should cause the
# "post" file lists to be generated.
#
_CHECK_FILES_POST=		check-files-post-message
_CHECK_FILES_POST+=		${_CHECK_FILES_POST.prefix}
.if empty(CHECK_FILES_STRICT:M[nN][oO])
_CHECK_FILES_POST+=		${_CHECK_FILES_POST.sysconfdir}
_CHECK_FILES_POST+=		${_CHECK_FILES_POST.varbase}
.endif

###########################################################################
# check-files-pre and check-files-post targets and subtargets
#
.PHONY: check-files-pre check-files-post
check-files-pre: ${_CHECK_FILES_PRE}
check-files-post: ${_CHECK_FILES_POST}

.PHONY: check-files-pre-message check-files-post-message
check-files-pre-message:
	${_PKG_SILENT}${_PKG_DEBUG}${STEP_MSG}				\
		"Generating pre-install file lists"

check-files-post-message:
	${_PKG_SILENT}${_PKG_DEBUG}${STEP_MSG}				\
		"Generating post-install file lists"

${_CHECK_FILES_PRE.prefix} ${_CHECK_FILES_POST.prefix}:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${FIND} ${PREFIX}/. \( -type f -o -type l \) -print 2>/dev/null \
		| ${SED} -e 's,/\./,/,'					\
		| ${_CHECK_FILES_SKIP_FILTER} > ${.TARGET}		\
                || ${TRUE}

${_CHECK_FILES_PRE.sysconfdir} ${_CHECK_FILES_POST.sysconfdir}:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${FIND} ${PKG_SYSCONFDIR}/. -print 2>/dev/null			\
		| ${SED} -e 's,/\./,/,'					\
		| ${_CHECK_FILES_SKIP_FILTER} > ${.TARGET}		\
		|| ${TRUE}

${_CHECK_FILES_PRE.varbase} ${_CHECK_FILES_POST.varbase}:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${FIND} ${VARBASE}/. -print 2>/dev/null				\
		| ${SED} -e 's,/\./,/,'					\
		| ${_CHECK_FILES_SKIP_FILTER} > ${.TARGET}		\
		|| ${TRUE}

###########################################################################
# check-files targets and subtargets
#
.PHONY: check-files-prefix check-files-sysconfdir check-files-varbase
check-files-prefix: ${_CHECK_FILES_COOKIE.prefix}
check-files-sysconfdir: ${_CHECK_FILES_COOKIE.sysconfdir}
check-files-varbase: ${_CHECK_FILES_COOKIE.varbase}

# The check-files target looks at the cookie files generated by the
# check-files-* subtargets, and if they are non-empty, then they
# contain the error messages collected during the build of each
# subtarget.
#
.PHONY: check-files
check-files: ${_CHECK_FILES_COOKIES}
	${_PKG_SILENT}${_PKG_DEBUG}${STEP_MSG}				\
		"Checking file-check results for ${PKGNAME}"
.for _cookie_ in ${_CHECK_FILES_COOKIES}
	${_PKG_SILENT}${_PKG_DEBUG}${CAT} ${_cookie_}
.endfor
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${CAT} ${_CHECK_FILES_COOKIES} | ${AWK} 'END { if (NR > 0) exit 1; }'

# Check ${PREFIX} for files which are not listed in the generated ${PLIST}
# and vice-versa.
#
${_CHECK_FILES_COOKIE.prefix}:
.if !defined(NO_PKG_REGISTER)
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if ${TEST} ! -f ${_CHECK_FILES_PRE.prefix} -o			\
		   ! -f ${_CHECK_FILES_POST.prefix};			\
	then								\
		{ exit 0; };						\
	fi;								\
	f_added=${WRKDIR}/.files.added;					\
	f_deleted=${WRKDIR}/.files.deleted;				\
	f_expected=${WRKDIR}/.files.expected;				\
	f_missing=${WRKDIR}/.files.missing;				\
	f_missing_real=${WRKDIR}/.files.missing.real;			\
	f_missing_skip=${WRKDIR}/.files.missing.skip;			\
	f_extra=${WRKDIR}/.files.extra;					\
	${DIFF} -u ${_CHECK_FILES_PRE.prefix} ${_CHECK_FILES_POST.prefix} \
		> ${WRKDIR}/.files.diff || ${TRUE};			\
	${GREP} '^+/' ${WRKDIR}/.files.diff | ${SED} "s|^+||" | ${SORT}	\
		> $$f_added;						\
	${GREP} '^-/' ${WRKDIR}/.files.diff | ${SED} "s|^-||" | ${SORT}	\
		> $$f_deleted;						\
	${GREP} '^[A-Za-z]' ${PLIST} | ${SED} "s|^|${PREFIX}/|" | ${SORT} \
		> $$f_expected;						\
	${DIFF} -u ${WRKDIR}/.files.expected ${WRKDIR}/.files.added	\
		| ${GREP} '^-[^-]' | ${SED} "s|^-||"			\
		> $$f_missing;						\
	${DIFF} -u ${WRKDIR}/.files.expected ${WRKDIR}/.files.added	\
		| ${GREP} '^+[^+]' | ${SED} "s|^+||"			\
		> $$f_extra;						\
	if ${AWK} 'END { if (NR == 0) exit 1; }' $$f_deleted; then	\
		{ ${ECHO} "*** The following files have been deleted"	\
			  "from ${PREFIX}!";				\
		  ${SED} "s|^|        |" $$f_deleted;			\
		} > ${.TARGET};						\
	fi;								\
	if ${AWK} 'END { if (NR == 0) exit 1; }' $$f_missing $$f_extra;	\
	then								\
		{ ${ECHO} "*** The PLIST does not match installed files!"; \
		  ${CAT} $$f_missing | ${_CHECK_FILES_SKIP_FILTER}	\
			> $$f_missing_real;				\
		  ${DIFF} -u $$f_missing $$f_missing_real		\
			| ${GREP} '^-[^-]' | ${SED} "s|^-||"		\
			> $$f_missing_skip;				\
		  if ${AWK} 'END { if (NR == 0) exit 1; }' $$f_missing_real; \
		  then \
		  	${ECHO} "*** The following files are in the"	\
				"PLIST but not in ${PREFIX}:";		\
			${SED} "s|^|        |" $$f_missing_real;	\
		  fi;							\
		  if ${AWK} 'END { if (NR == 0) exit 1; }' $$f_extra; then \
		  	${ECHO} "*** The following files are in"	\
				"${PREFIX} but not in the PLIST:";	\
			${SED} "s|^|        |" $$f_extra;		\
		  fi;							\
		  if ${AWK} 'END { if (NR == 0) exit 1; }' $$f_missing_skip; \
		  then \
		  	${ECHO} "*** The following files are in both"	\
				"the PLIST and CHECK_FILES_SKIP:";	\
			 ${SED} "s|^|        |" $$f_missing_skip;	\
		  fi;							\
		} >> ${.TARGET};					\
	fi;								\
	${RM} -f ${WRKDIR}/.files.diff $$f_added $$f_deleted		\
		 $$f_expected $$f_missing $$f_extra			\
		 $$f_missing_real $$f_missing_skip
.endif
	${_PKG_SILENT}${_PKG_DEBUG}${TOUCH} ${TOUCH_FLAGS} ${.TARGET}

# Check ${SYSCONFDIR} for files which are not in the PLIST and are also
# not copied into place by the INSTALL scripts.
#
${_CHECK_FILES_COOKIE.sysconfdir}:
.if !defined(NO_PKG_REGISTER)
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if ${TEST} ! -f ${_CHECK_FILES_PRE.sysconfdir} -o		\
		   ! -f ${_CHECK_FILES_POST.sysconfdir};		\
	then								\
		{ exit 0; };						\
	fi;								\
	if ! ${CMP} -s ${_CHECK_FILES_PRE.sysconfdir}			\
		       ${_CHECK_FILES_POST.sysconfdir};			\
	then								\
		{ ${ECHO} "*** The package has modified ${PKG_SYSCONFDIR}" \
			  "contents directly!";				\
		  ${ECHO} "    The offending files/directories are:";	\
		  ${DIFF} -u ${_CHECK_FILES_PRE.sysconfdir}		\
			     ${_CHECK_FILES_POST.sysconfdir}		\
			| ${GREP} '^+[^+]' | ${SED} "s|^+|	|";	\
		} > ${.TARGET};						\
	fi
.endif
	${_PKG_SILENT}${_PKG_DEBUG}${TOUCH} ${TOUCH_FLAGS} ${.TARGET}

# Check ${VARBASE} for files which are not in the PLIST and are also
# not created by the INSTALL scripts.
#
${_CHECK_FILES_COOKIE.varbase}:
.if !defined(NO_PKG_REGISTER)
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if ${TEST} ! -f ${_CHECK_FILES_PRE.varbase} -o			\
		   ! -f ${_CHECK_FILES_POST.varbase};			\
	then								\
		{ exit 0; };						\
	fi;								\
	if ! ${CMP} -s ${_CHECK_FILES_PRE.varbase}			\
		       ${_CHECK_FILES_POST.varbase};			\
	then								\
		{ ${ECHO} "*** The package has modified ${VARBASE}"	\
			  "contents directly!";				\
		  ${ECHO} "    The offending files/directories are:";	\
		  ${DIFF} -u ${_CHECK_FILES_PRE.varbase}		\
			     ${_CHECK_FILES_POST.varbase}		\
			| ${GREP} '^+[^+]' | ${SED} "s|^+|	|";	\
		} > ${.TARGET};						\
	fi
.endif
	${_PKG_SILENT}${_PKG_DEBUG}${TOUCH} ${TOUCH_FLAGS} ${.TARGET}

###########################################################################
# check-files-clean removes the state files related to the "check-files"
# target so that the check-files-{pre,post} targets may be re-run.
#
.PHONY: check-files-clean
check-clean: check-files-clean
check-files-clean:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${RM} -f ${_CHECK_FILES_COOKIES}				\
		${_CHECK_FILES_PRE} ${_CHECK_FILES_POST}
