# $NetBSD: check-files.mk,v 1.34 2017/06/01 02:15:10 jlam Exp $
#
# This file checks that the list of installed files matches the PLIST.
# For that purpose it records the file list of LOCALBASE before and
# after the installation of the package and compares these lists with
# the PLIST.
#
# User-settable variables:
#
# CHECK_FILES
#	"yes" to enable the check, "no" to disable it.
#
#	Default value: "yes" for PKG_DEVELOPERs, "no" otherwise.
#
# CHECK_FILES_STRICT
#	When set to "yes", VARBASE and PKG_SYSCONFDIR are checked in
#	addition to LOCALBASE.
#
# Package-settable variables:
#
# CHECK_FILES_SKIP
#	A list of regular expressions (FIXME: all other checks use shell
#	patterns) that names files to be skipped. This is useful to
#	avoid getting errors triggered by changes in directories not
#	really handled by pkgsrc.
#

_VARGROUPS+=		check-files
_USER_VARS.check-files=	CHECK_FILES CHECK_FILES_STRICT
_PKG_VARS.check-files=	CHECK_FILES_SKIP

.if ${PKG_DEVELOPER:Uno} != "no"
CHECK_FILES?=		yes
.else
CHECK_FILES?=		no
.endif
CHECK_FILES_STRICT?=	no

# Info index files updated when a new info file is added.
.if defined(INFO_FILES)
CHECK_FILES_SKIP+=	${PREFIX}/.*/dir
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

CHECK_FILES_SKIP+=	${PKG_DBDIR}/.*

# We don't care about what's under linux/proc and linux32/proc in Linux 
# emulation, which just holds run-time generated data.
#
CHECK_FILES_SKIP+=	${PREFIX}/emul/linux/proc.*
CHECK_FILES_SKIP+=	${PREFIX}/emul/linux32/proc.*

# The reference-count meta-data directory used by the {de,}install scripts.
CHECK_FILES_SKIP+=	${PKG_DBDIR}.refcount.*

# Some people have their distfiles and binary packages below ${LOCALBASE}.
CHECK_FILES_SKIP+=	${PACKAGES}/.*
CHECK_FILES_SKIP+=	${DISTDIR}/.*

# For unprivileged builds, VARBASE is below LOCALBASE.
.if !empty(CHECK_FILES_STRICT:M[Nn][Oo])
CHECK_FILES_SKIP+=	${VARBASE}/.*
.endif

# File that are outside of ${PREFIX} in directories we already know we'll
# be using for mutable data.
#
.for d in ${MAKE_DIRS} ${OWN_DIRS}
CHECK_FILES_SKIP+=	${d:C/^([^\/])/${PREFIX}\/\1/}.*
.endfor
.for _var_ in MAKE_DIRS_PERMS OWN_DIRS_PERMS
.  if empty(${_var_}) || empty(${_var_}:C/.*/4/:M*:S/4 4 4 4//gW)
.    for d o g m in ${${_var_}}
CHECK_FILES_SKIP+=	${d:C/^([^\/])/${PREFIX}\/\1/}.*
.    endfor
.  endif
.endfor

# Mutable X11 font database files
.if (defined(FONTS_DIRS.x11) && !empty(FONTS_DIRS.x11:M*))
CHECK_FILES_SKIP+=	${PREFIX}/.*/encodings.dir
CHECK_FILES_SKIP+=	${PREFIX}/.*/fonts.dir
.endif
.if (defined(FONTS_DIRS.ttf) && !empty(FONTS_DIRS.ttf:M*)) || \
    (defined(FONTS_DIRS.type1) && !empty(FONTS_DIRS.type1:M*))
CHECK_FILES_SKIP+=	${PREFIX}/.*/fonts.scale
.endif
.if (defined(FONTS_DIRS.ttf) && !empty(FONTS_DIRS.ttf:M*)) || \
    (defined(FONTS_DIRS.type1) && !empty(FONTS_DIRS.type1:M*)) || \
    (defined(FONTS_DIRS.x11) && !empty(FONTS_DIRS.x11:M*))
CHECK_FILES_SKIP+=	${PREFIX}/.*/fonts.cache-1
.endif

# Mutable charset.alias file
CHECK_FILES_SKIP+=	${PREFIX}/lib/charset.alias

# Mutable locale.alias file
CHECK_FILES_SKIP+=	${PREFIX}/share/locale/locale.alias

_CHECK_FILES_SKIP_FILTER=	${GREP} -vx ${CHECK_FILES_SKIP:@f@-e ${DESTDIR:Q}${f:Q}@}

###########################################################################
# These are the files generated and used by the check-files implementation
# used across several check-files targets.
#
#    _CHECK_FILES_ERRMSG.* are the files that contain the error
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
_CHECK_FILES_ERRMSG.prefix=	${ERROR_DIR}/check-files-prefix
_CHECK_FILES_PRE.prefix=	${WRKDIR}/.prefix.pre
_CHECK_FILES_POST.prefix=	${WRKDIR}/.prefix.post

_CHECK_FILES_ERRMSG.sysconfdir=	${ERROR_DIR}/.check-files-sysconfdir
_CHECK_FILES_PRE.sysconfdir=	${WRKDIR}/.sysconfdir.pre
_CHECK_FILES_POST.sysconfdir=	${WRKDIR}/.sysconfdir.post

_CHECK_FILES_ERRMSG.varbase=	${ERROR_DIR}/.check-files-varbase
_CHECK_FILES_PRE.varbase=	${WRKDIR}/.varbase.pre
_CHECK_FILES_POST.varbase=	${WRKDIR}/.varbase.post

_CHECK_FILES_ERRMSGS=		# empty
_CHECK_FILES_ERRMSGS+=		${_CHECK_FILES_ERRMSG.prefix}
.if empty(CHECK_FILES_STRICT:M[nN][oO])
_CHECK_FILES_ERRMSGS+=		${_CHECK_FILES_ERRMSG.sysconfdir}
_CHECK_FILES_ERRMSGS+=		${_CHECK_FILES_ERRMSG.varbase}
.endif

###########################################################################
# _CHECK_FILES_PRE holds the list of targets that are built as part of
# building the check-files-pre target.  These targets should cause the
# "pre" file lists to be generated.
#
_CHECK_FILES_PRE=		#
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
_CHECK_FILES_POST=		#
_CHECK_FILES_POST+=		${_CHECK_FILES_POST.prefix}
.if empty(CHECK_FILES_STRICT:M[nN][oO])
_CHECK_FILES_POST+=		${_CHECK_FILES_POST.sysconfdir}
_CHECK_FILES_POST+=		${_CHECK_FILES_POST.varbase}
.endif

.if empty(CHECK_FILES:M[nN][oO])
privileged-install-hook: check-files
.endif

###########################################################################
# check-files-pre and check-files-post targets and subtargets
#
.PHONY: check-files-pre check-files-post
check-files-pre: check-files-pre-message ${_CHECK_FILES_PRE}
check-files-post: check-files-post-message ${_CHECK_FILES_POST}

.PHONY: check-files-pre-message check-files-post-message
check-files-pre-message:
	@${STEP_MSG} "Generating pre-install file lists"

check-files-post-message:
	@${STEP_MSG} "Generating post-install file lists"

${_CHECK_FILES_PRE.prefix} ${_CHECK_FILES_POST.prefix}:
	${RUN}					\
	${FIND} ${DESTDIR}${PREFIX}/. \( -type f -o -type l \) -print 2>/dev/null \
		| ${SED} -e 's,/\./,/,'					\
		| ${_CHECK_FILES_SKIP_FILTER}				\
		| ${SORT} > ${.TARGET}					\
                || ${TRUE}

${_CHECK_FILES_PRE.sysconfdir} ${_CHECK_FILES_POST.sysconfdir}:
	${RUN}					\
	${FIND} ${DESTDIR}${PKG_SYSCONFDIR}/. -print 2>/dev/null	\
		| ${SED} -e 's,/\./,/,'					\
		| ${_CHECK_FILES_SKIP_FILTER} 				\
		| ${SORT} > ${.TARGET}					\
		|| ${TRUE}

${_CHECK_FILES_PRE.varbase} ${_CHECK_FILES_POST.varbase}:
	${RUN}					\
	${FIND} ${DESTDIR}${VARBASE}/. -print 2>/dev/null		\
		| ${SED} -e 's,/\./,/,'					\
		| ${_CHECK_FILES_SKIP_FILTER} 				\
		| ${SORT} > ${.TARGET}					\
		|| ${TRUE}

###########################################################################
# check-files targets and subtargets
#
.PHONY: check-files-prefix check-files-sysconfdir check-files-varbase
check-files-prefix: ${_CHECK_FILES_ERRMSG.prefix}
check-files-sysconfdir: ${_CHECK_FILES_ERRMSG.sysconfdir}
check-files-varbase: ${_CHECK_FILES_ERRMSG.varbase}

# The check-files target looks at the cookie files generated by the
# check-files-* subtargets, and if they are non-empty, then they
# contain the error messages collected during the build of each
# subtarget.
#
.PHONY: check-files
.if !empty(CHECK_FILES_SUPPORTED:M[nN][oO])
check-files:
	@${DO_NADA}
.else
check-files: check-files-message ${_CHECK_FILES_ERRMSGS} error-check
.endif

.PHONY: check-files-message
check-files-message:
	@${STEP_MSG} "Checking file-check results for ${PKGNAME}"

# Check ${PREFIX} for files which are not listed in the generated ${PLIST}
# and vice-versa.
#
_CHECK_FILES_DIFF=		${WRKDIR}/.check_files_diff
_CHECK_FILES_ADDED=		${WRKDIR}/.check_files_added
_CHECK_FILES_DELETED=		${WRKDIR}/.check_files_deleted
_CHECK_FILES_EXPECTED=		${WRKDIR}/.check_files_expected
_CHECK_FILES_MISSING=		${WRKDIR}/.check_files_missing
_CHECK_FILES_MISSING_SKIP=	${WRKDIR}/.check_files_missing_skip
_CHECK_FILES_MISSING_REAL=	${WRKDIR}/.check_files_missing_real
_CHECK_FILES_EXTRA=		${WRKDIR}/.check_files_extra

${_CHECK_FILES_DIFF}: ${_CHECK_FILES_PRE.prefix} ${_CHECK_FILES_POST.prefix}
	${RUN}					\
	${DIFF} -u ${_CHECK_FILES_PRE.prefix}				\
		  ${_CHECK_FILES_POST.prefix}				\
		> ${.TARGET} || ${TRUE}

${_CHECK_FILES_ADDED}: ${_CHECK_FILES_DIFF}
	${RUN}					\
	${GREP} '^+/' ${_CHECK_FILES_DIFF} | ${SED} "s|^+||" | ${SORT}	\
		> ${.TARGET}

${_CHECK_FILES_DELETED}: ${_CHECK_FILES_DIFF}
	${RUN}					\
	${GREP} '^-/' ${_CHECK_FILES_DIFF} | ${SED} "s|^-||" | ${SORT}	\
		> ${.TARGET}

${_CHECK_FILES_EXPECTED}: plist
	${RUN}					\
	${GREP} '^[^@]' ${PLIST} | ${SED} "s|^|${DESTDIR}${PREFIX}/|" | ${SORT}	\
		> ${.TARGET}

${_CHECK_FILES_MISSING}: ${_CHECK_FILES_EXPECTED} ${_CHECK_FILES_ADDED}
	${RUN}					\
	${DIFF} -u ${_CHECK_FILES_EXPECTED} ${_CHECK_FILES_ADDED} |	\
	${GREP} '^-[^-]' | ${SED} "s|^-||" |				\
	while read file; do						\
		${TEST} -f "$$file" -o -h "$$file" || ${ECHO} "$$file";	\
	done > ${.TARGET}

${_CHECK_FILES_MISSING_REAL}: ${_CHECK_FILES_MISSING}
	${RUN}					\
	${CAT} ${_CHECK_FILES_MISSING} | ${_CHECK_FILES_SKIP_FILTER}	\
		> ${.TARGET} || ${TRUE}

${_CHECK_FILES_MISSING_SKIP}:						\
		${_CHECK_FILES_MISSING}					\
		${_CHECK_FILES_MISSING_REAL}
	${RUN}					\
	${DIFF} -u ${_CHECK_FILES_MISSING}				\
		   ${_CHECK_FILES_MISSING_REAL} |			\
	${GREP} '^-[^-]' | ${SED} "s|^-||"				\
		> ${.TARGET}

${_CHECK_FILES_EXTRA}: ${_CHECK_FILES_EXPECTED} ${_CHECK_FILES_ADDED}
	${RUN}					\
	${DIFF} -u  ${_CHECK_FILES_EXPECTED} ${_CHECK_FILES_ADDED} |	\
	${GREP} '^+[^+]' | ${SED} "s|^+||" |				\
	while read file; do						\
		${TEST} ! -f "$$file" -a ! -h "$$file" || ${ECHO} "$$file"; \
	done > ${.TARGET}

${_CHECK_FILES_ERRMSG.prefix}:						\
		${_CHECK_FILES_DELETED}					\
		${_CHECK_FILES_MISSING}					\
		${_CHECK_FILES_MISSING_REAL}				\
		${_CHECK_FILES_MISSING_SKIP}				\
		${_CHECK_FILES_EXTRA}
	${RUN}${RM} -f ${.TARGET}
	${RUN}					\
	if ${_NONZERO_FILESIZE_P} ${_CHECK_FILES_DELETED}; then		\
		${ECHO} "The following files have been deleted"		\
			"from ${PREFIX}!";				\
		${SED} "s|^|        |" ${_CHECK_FILES_DELETED};		\
	fi >> ${.TARGET}
	${RUN}					\
	if ${_NONZERO_FILESIZE_P} ${_CHECK_FILES_MISSING_REAL}; then	\
		${ECHO} "************************************************************"; \
		${ECHO} "The following files are in the"		\
			"PLIST but not in ${DESTDIR}${PREFIX}:";			\
		${SED} "s|^|        |" ${_CHECK_FILES_MISSING_REAL};	\
	fi >> ${.TARGET}
	${RUN}					\
	if ${_NONZERO_FILESIZE_P} ${_CHECK_FILES_EXTRA}; then		\
		${ECHO} "************************************************************"; \
		${ECHO} "The following files are in"			\
			"${DESTDIR}${PREFIX} but not in the PLIST:";		\
		${SED} "s|^|        |" ${_CHECK_FILES_EXTRA};		\
	fi >> ${.TARGET}
	${RUN}					\
	if ${_NONZERO_FILESIZE_P} ${_CHECK_FILES_MISSING_SKIP}; then	\
		${ECHO} "************************************************************"; \
		${ECHO} "The following files are in both the"		\
			"PLIST and CHECK_FILES_SKIP:";			\
		${SED} "s|^|        |" ${_CHECK_FILES_MISSING_SKIP};	\
	fi >> ${.TARGET}

# Check ${PKG_SYSCONFDIR} for files which are not in the PLIST and are
# also not copied into place by the INSTALL scripts. 
#
${_CHECK_FILES_ERRMSG.sysconfdir}:					\
		${_CHECK_FILES_PRE.sysconfdir}				\
		${_CHECK_FILES_POST.sysconfdir}
	${RUN}					\
	if ${CMP} -s ${_CHECK_FILES_PRE.sysconfdir}			\
		     ${_CHECK_FILES_POST.sysconfdir}; then		\
		${DO_NADA};						\
	else								\
		${ECHO} "************************************************************"; \
		${ECHO} "The package has modified ${PKG_SYSCONFDIR}"	\
			"contents directly!";				\
		${ECHO} "    The offending files/directories are:";	\
		${DIFF} -u ${_CHECK_FILES_PRE.sysconfdir}		\
			   ${_CHECK_FILES_POST.sysconfdir} |		\
		${GREP} '^+[^+]' | ${SED} "s|^+|	|";		\
	fi > ${.TARGET}

# Check ${VARBASE} for files which are not in the PLIST and are also
# not created by the INSTALL scripts.
#
${_CHECK_FILES_ERRMSG.varbase}:						\
		${_CHECK_FILES_PRE.varbase}				\
		${_CHECK_FILES_POST.varbase}
	${RUN}					\
	if ${CMP} -s ${_CHECK_FILES_PRE.varbase}			\
		       ${_CHECK_FILES_POST.varbase}; then		\
		${DO_NADA};						\
	else								\
		${ECHO} "************************************************************"; \
		${ECHO} "The package has modified ${VARBASE}"		\
			"contents directly!";				\
		${ECHO} "    The offending files/directories are:";	\
		${DIFF} -u ${_CHECK_FILES_PRE.varbase}			\
			   ${_CHECK_FILES_POST.varbase}	|		\
		${GREP} '^+[^+]' | ${SED} "s|^+|	|";		\
	fi > ${.TARGET}

###########################################################################
# check-files-clean removes the state files related to the "check-files"
# target so that the check-files-{pre,post} targets may be re-run.
#
.PHONY: check-files-clean
check-clean: check-files-clean
check-files-clean:
	${RUN}					\
	${RM} -f ${_CHECK_FILES_ERRMSGS}				\
		${_CHECK_FILES_PRE} ${_CHECK_FILES_POST}		\
		${_CHECK_FILES_DIFF} ${_CHECK_FILES_ADDED}		\
		${_CHECK_FILES_DELETED} ${_CHECK_FILES_EXPECTED}	\
		${_CHECK_FILES_MISSING} ${_CHECK_FILES_MISSING_SKIP}	\
		${_CHECK_FILES_MISSING_REAL} ${_CHECK_FILES_EXTRA}
