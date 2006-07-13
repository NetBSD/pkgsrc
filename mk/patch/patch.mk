# $NetBSD: patch.mk,v 1.9 2006/07/13 14:02:34 jlam Exp $
#
# The following variables may be set in a package Makefile and control
# how pkgsrc patches are applied.
#
#    PATCH_STRIP is a patch(1) argument that sets the pathname strip
#	count to help find the correct files to patch.  See the patch(1)
#	man page for more details.  Defaults to "-p0".
#
#    PATCH_ARGS is the base set of arguments passed to patch(1).
#	The default set of arguments will apply the patches to the
#	files in ${WRKSRC} with any ${PATCH_STRIP} arguments set.
#
# The following variables may be set in a package Makefile and control
# how "distribution" patches are applied.
#
#    PATCH_DIST_STRIP is a patch(1) argument that sets the pathname
#	strip count to help find the correct files to patch.  See the
#	patch(1) man page for more details.  Defaults to "-p0".
#
#    PATCH_DIST_ARGS is the base set of arguments passed to patch(1).
#	The default set of arguments will apply the patches to the
#	files in ${WRKSRC} with any ${PATCH_DIST_STRIP} arguments set.
#
#    PATCH_DIST_CAT is the command that outputs the contents of the
#	"$patchfile" to stdout.  The default value is a command that
#	can output gzipped, bzipped, or plain patches to stdout.
#
#    PATCH_DIST_STRIP.<patchfile>
#    PATCH_DIST_ARGS.<patchfile>
#    PATCH_DIST_CAT.<patchfile>
#	These are versions of the previous three variables which allow
#	for customization of their values for specific patchfiles.
#
# The following variables may be set by the user and affect how patching
# occurs:
#
#    PATCH_DEBUG, if defined, causes the the patch process to be more
#	verbose.
#
#    PATCH_FUZZ_FACTOR is a patch(1) argument that specifies how much
#	fuzz to accept when applying pkgsrc patches.  See the patch(1)
#	man page for more details.  Defaults to "-F0" for zero fuzz.
#

_PATCH_APPLIED_FILE=	${WRKDIR}/.patch
_COOKIE.patch=		${WRKDIR}/.patch_done

######################################################################
### patch (PUBLIC)
######################################################################
### patch is a public target to apply the distribution and pkgsrc
### patches to the extracted sources for the package.
###
_PATCH_TARGETS+=	check-vulnerable
_PATCH_TARGETS+=	extract
_PATCH_TARGETS+=	acquire-patch-lock
_PATCH_TARGETS+=	${_COOKIE.patch}
_PATCH_TARGETS+=	release-patch-lock

.PHONY: patch
.if !target(patch)
.  if exists(${_COOKIE.patch})
patch:
	@${DO_NADA}
.  else
patch: ${_PATCH_TARGETS}
.  endif
.endif

.PHONY: acquire-patch-lock release-patch-lock
acquire-patch-lock: acquire-lock
release-patch-lock: release-lock

.if exists(${_COOKIE.patch})
${_COOKIE.patch}:
	@${DO_NADA}
.else
${_COOKIE.patch}: real-patch
.endif

######################################################################
### real-patch (PRIVATE)
######################################################################
### real-patch is a helper target onto which one can hook all of the
### targets that do the actual patching work.
###
_REAL_PATCH_TARGETS+=	patch-message
_REAL_PATCH_TARGETS+=	patch-vars
_REAL_PATCH_TARGETS+=	pre-patch
_REAL_PATCH_TARGETS+=	do-patch
_REAL_PATCH_TARGETS+=	post-patch
_REAL_PATCH_TARGETS+=	patch-cookie
_REAL_PATCH_TARGETS+=	error-check

.PHONY: real-patch
real-patch: ${_REAL_PATCH_TARGETS}

.PHONY: patch-message
patch-message:
	@${PHASE_MSG} "Patching for ${PKGNAME}"

######################################################################
### patch-cookie (PRIVATE)
######################################################################
### patch-cookie creates the "patch" cookie file.  The contents are
### the paths to the patches that were applied (if any).
###
.PHONY: patch-cookie
patch-cookie:
	${_PKG_SILENT}${_PKG_DEBUG}${TEST} ! -f ${_COOKIE.patch} || ${FALSE}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if ${TEST} -f ${_PATCH_APPLIED_FILE:Q}; then			\
		${MV} -f ${_PATCH_APPLIED_FILE:Q} ${_COOKIE.patch:Q};	\
	else								\
		${TOUCH} ${TOUCH_FLAGS} ${_COOKIE.patch:Q};		\
	fi

######################################################################
### pre-patch, do-patch, post-patch (PUBLIC, override)
######################################################################
### {pre,do,post}-patch are the heart of the package-customizable
### patch targets, and may be overridden within a package Makefile.
###
.PHONY: pre-patch do-patch post-patch

.if defined(PATCHFILES)
_PKGSRC_PATCH_TARGETS+=	distribution-patch-message
_PKGSRC_PATCH_TARGETS+=	do-distribution-patch
.endif
.if (defined(PATCHDIR) && exists(${PATCHDIR})) || \
    (defined(LOCALPATCHES) && exists(${LOCALPATCHES}/${PKGPATH}))
_PKGSRC_PATCH_TARGETS+=	pkgsrc-patch-message
_PKGSRC_PATCH_TARGETS+=	do-pkgsrc-patch
.endif

.PHONY: do-patch
.if !target(do-patch)
do-patch: ${_PKGSRC_PATCH_TARGETS}
.endif

.if !target(pre-patch)
pre-patch:
	@${DO_NADA}
.endif
.if !target(post-patch)
post-patch:
	@${DO_NADA}
.endif

######################################################################

.if defined(PATCH_DEBUG) || defined(PKG_VERBOSE)
_PATCH_DEBUG=		yes
ECHO_PATCH_MSG?=	${STEP_MSG}
.else
_PATCH_DEBUG=		no
ECHO_PATCH_MSG?=	${SHCOMMENT}
.endif

PATCH_STRIP?=		-p0
.if !empty(_PATCH_DEBUG:M[yY][eE][sS])
PATCH_ARGS?=		-d ${WRKSRC} -E ${PATCH_STRIP}
.else
PATCH_ARGS?=		-d ${WRKSRC} --forward --quiet -E ${PATCH_STRIP}
.endif
.if defined(BATCH)
PATCH_ARGS+=		--batch
.endif
.if defined(_PATCH_CAN_BACKUP) && (${_PATCH_CAN_BACKUP} == "yes")
PATCH_ARGS+=		${_PATCH_BACKUP_ARG} .orig
.endif
PATCH_FUZZ_FACTOR?=	-F0	# Default to zero fuzz

_PKGSRC_PATCH_FAIL=							\
if ${TEST} -n ${PKG_OPTIONS:Q}"" ||					\
   ${TEST} -n ${LOCALPATCHES:Q}"" -a -d ${LOCALPATCHES:Q}/${PKGPATH:Q}; then \
	${ERROR_MSG} "=========================================================================="; \
	${ERROR_MSG};							\
	${ERROR_MSG} "Some of the selected build options and/or local patches may be incompatible."; \
	${ERROR_MSG} "Please try building with fewer options or patches."; \
	${ERROR_MSG};							\
	${ERROR_MSG} "=========================================================================="; \
fi; exit 1

######################################################################
### do-distribution-patch (PRIVATE)
######################################################################
### do-distribution-patch applies the distribution patches (specified
### in PATCHFILES) to the extracted sources.
###
.PHONY: distribution-patch-message do-distribution-patch

# PATCH_DIST_STRIP is a patch option that sets the pathname strip count.
# PATCH_DIST_ARGS is the list of arguments to pass to the patch command.
# PATCH_DIST_CAT is the command that outputs the patch to stdout.
#
# For each of these variables, there is a patch-specific variant that
# may be set, i.e. PATCH_DIST_STRIP.<patch>, PATCH_DIST_ARGS.<patch>,
# PATCH_DIST_CAT.<patch>.
#
PATCH_DIST_STRIP?=		-p0
.for i in ${PATCHFILES}
PATCH_DIST_STRIP.${i:S/=/--/}?=	${PATCH_DIST_STRIP}
.  if defined(PATCH_DIST_ARGS)
PATCH_DIST_ARGS.${i:S/=/--/}?=	${PATCH_DIST_ARGS}
.  elif !empty(_PATCH_DEBUG:M[yY][eE][sS])
PATCH_DIST_ARGS.${i:S/=/--/}?=	-d ${WRKSRC} -E ${PATCH_DIST_STRIP.${i:S/=/--/}}
.  else
PATCH_DIST_ARGS.${i:S/=/--/}?=	-d ${WRKSRC} --forward --quiet -E ${PATCH_DIST_STRIP.${i:S/=/--/}}
.  endif
.endfor
.if defined(BATCH)
PATCH_DIST_ARGS+=		--batch
.  for i in ${PATCHFILES}
PATCH_DIST_ARGS.${i:S/=/--/}+=	--batch
.  endfor
.endif
.if defined(_PATCH_CAN_BACKUP) && (${_PATCH_CAN_BACKUP} == "yes")
PATCH_DIST_ARGS+=		${_PATCH_BACKUP_ARG} .orig_dist
.  for i in ${PATCHFILES}
PATCH_DIST_ARGS.${i:S/=/--/}+=	${_PATCH_BACKUP_ARG} .orig_dist
.  endfor
.endif
PATCH_DIST_CAT?=	{ case $$patchfile in				\
			  *.Z|*.gz) ${GZCAT} $$patchfile ;;		\
			  *.bz2)    ${BZCAT} $$patchfile ;;		\
			  *)	    ${CAT} $$patchfile ;;		\
			  esac; }
.for i in ${PATCHFILES}
PATCH_DIST_CAT.${i:S/=/--/}?=	{ patchfile=${i}; ${PATCH_DIST_CAT}; }
.endfor

distribution-patch-message:
	@${STEP_MSG} "Applying distribution patches for ${PKGNAME}"

do-distribution-patch:
.for i in ${PATCHFILES}
	@${ECHO_PATCH_MSG} "Applying distribution patch ${i}"
	${_PKG_SILENT}${_PKG_DEBUG}cd ${_DISTDIR};			\
	${PATCH_DIST_CAT.${i:S/=/--/}} |				\
	${PATCH} ${PATCH_DIST_ARGS.${i:S/=/--/}} ||			\
		{ ${ERROR_MSG} "Patch ${i} failed"; ${_PKGSRC_PATCH_FAIL}; }
	${_PKG_SILENT}${_PKG_DEBUG}${ECHO} ${_DISTDIR:Q}/${i:Q} >> ${_PATCH_APPLIED_FILE:Q}
.endfor

######################################################################
### do-pkgsrc-patch (PRIVATE)
######################################################################
### do-pkgsrc-patch applies the pkgsrc patches to the extracted
### sources.
###
.PHONY: pkgsrc-patch-message do-pkgsrc-patch

.if defined(PATCHDIR) && exists(${PATCHDIR})
_PKGSRC_PATCHES+=	${PATCHDIR}/patch-*
.endif
.if defined(LOCALPATCHES) && exists(${LOCALPATCHES}/${PKGPATH})
_PKGSRC_PATCHES+=	${LOCALPATCHES}/${PKGPATH}/*
.endif

pkgsrc-patch-message:
	@${STEP_MSG} "Applying pkgsrc patches for ${PKGNAME}"

do-pkgsrc-patch:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	fail=;								\
	patches=${_PKGSRC_PATCHES:Q};					\
	patch_warning() {						\
		${ECHO_MSG} "**************************************";	\
		${ECHO_MSG} "$$1";					\
		${ECHO_MSG} "**************************************";	\
	};								\
	for i in $$patches; do						\
		${TEST} -f "$$i" || continue;				\
		case "$$i" in						\
		*.orig|*.rej|*~)					\
			${STEP_MSG} "Ignoring patchfile $$i";		\
			continue;					\
			;;						\
		${PATCHDIR}/patch-local-*) 				\
			;;						\
		${PATCHDIR}/patch-*) 					\
			if ${TEST} ! -f ${DISTINFO_FILE:Q}; then	\
				patch_warning "Ignoring patch file $$i: distinfo not found"; \
				continue;				\
			fi;						\
			filename=`${BASENAME} $$i`;			\
			algsum=`${AWK} '(NF == 4) && ($$2 == "('$$filename')") && ($$3 == "=") {print $$1 " " $$4}' ${DISTINFO_FILE} || ${TRUE}`; \
			if ${TEST} -z "$$algsum"; then			\
				patch_warning "Ignoring patch file $$i: no checksum found"; \
				continue;				\
			fi;						\
			set -- $$algsum;				\
			alg="$$1";					\
			recorded="$$2";					\
			calcsum=`${SED} -e '/\$$NetBSD.*/d' $$i | ${TOOLS_DIGEST} $$alg`; \
			${ECHO_PATCH_MSG} "Verifying $$filename (using digest algorithm $$alg)"; \
			if ${TEST} "$$calcsum" != "$$recorded"; then	\
				patch_warning "Ignoring patch file $$i: invalid checksum"; \
				fail="$$fail $$i";			\
				continue;				\
			fi;						\
			;;						\
		esac;							\
		${ECHO_PATCH_MSG} "Applying pkgsrc patch $$i";		\
		fuzz_flags=;						\
		if ${PATCH} -v >/dev/null 2>&1; then			\
			fuzz_flags=${PATCH_FUZZ_FACTOR:Q};		\
		fi;							\
		if ${PATCH} $$fuzz_flags ${PATCH_ARGS} < $$i; then	\
			${ECHO} "$$i" >> ${_PATCH_APPLIED_FILE:Q};	\
		else							\
			${ECHO_MSG} "Patch $$i failed";			\
			fail="$$fail $$i";				\
		fi;							\
	done;								\
	if ${TEST} -n "$$fail"; then					\
		${ERROR_MSG} "Patching failed due to modified or broken patch file(s):"; \
		for i in $$fail; do					\
			${ERROR_MSG} "	$$i";				\
		done;							\
		${_PKGSRC_PATCH_FAIL};					\
	fi
