# $NetBSD: bsd.pkg.patch.mk,v 1.7 2005/05/17 06:31:00 jlam Exp $
#
# This Makefile fragment is included by bsd.pkg.mk and defines the
# relevant variables and targets for the "patch" phase.
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
#    PATCHFILES is a list of distribution patches relative to
#	${_DISTDIR} that are applied first to the package.
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
#    LOCALPATCHES is the location of local patches that are maintained
#	in a directory tree reflecting the same hierarchy as the pkgsrc
#	tree, e.g., local patches for www/apache would be found in
#	${LOCALPATCHES}/www/apache.  These patches are applied after
#	the patches in ${PATCHDIR}.
#
# The following targets are defined by bsd.pkg.patch.mk:
#
#    do-patch is the target that causes the actual patching of the
#	extracted sources to occur during the "patch" phase.
#

.if (defined(PATCHFILES) && !empty(PATCHFILES)) || \
    (defined(PATCHDIR) && exists(${PATCHDIR})) || \
    (defined(LOCALPATCHES) && exists(${LOCALPATCHES}/${PKGPATH}))
.  if empty(_USE_NEW_TOOLS:M[yY][eE][sS])
USE_GNU_TOOLS+=		patch
.  else
PKGSRC_USE_TOOLS+=	patch
.  endif
.endif

# These tools are used to output the contents of the distribution patches
# to stdout.
#
.if defined(PATCHFILES)
PKGSRC_USE_TOOLS+=	cat
.  if !empty(PATCHFILES:M*.Z) || !empty(PATCHFILES:M*.gz)
PKGSRC_USE_TOOLS+=	gzcat
.  endif
.  if !empty(PATCHFILES:M*.bz2)
.    if !empty(_USE_NEW_TOOLS:M[yY][eE][sS])
PKGSRC_USE_TOOLS+=	bzcat
.    elif exists(/usr/bin/bzcat)
BZCAT=			/usr/bin/bzcat
.    else
BZCAT=			${LOCALBASE}/bin/bzcat
BUILD_DEPENDS+=		bzip2>=0.9.0b:../../archivers/bzip2
.    endif
.  endif
.endif

.if defined(PATCH_DEBUG) || defined(PKG_VERBOSE)
_PATCH_DEBUG=		yes
ECHO_PATCH_MSG?=	${ECHO_MSG}
.else
_PATCH_DEBUG=		no
ECHO_PATCH_MSG?=	${TRUE}
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

# The following variables control how "distribution" patches are extracted
# and applied to the package sources.
#
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

_PKGSRC_PATCH_TARGETS=	uptodate-digest
.if defined(PATCHFILES)
_PKGSRC_PATCH_TARGETS+=	apply-distribution-patches
.endif
.if (defined(PATCHDIR) && exists(${PATCHDIR})) || \
    (defined(LOCALPATCHES) && exists(${LOCALPATCHES}/${PKGPATH}))
_PKGSRC_PATCH_TARGETS+=	apply-pkgsrc-patches
.endif

.PHONY: do-patch
.if !target(do-patch)
.ORDER: ${_PKGSRC_PATCH_TARGETS}
do-patch: ${_PKGSRC_PATCH_TARGETS}
.endif

_PKGSRC_PATCH_FAIL=							\
if ${TEST} -n ${PKG_OPTIONS:Q}"" ||					\
   ${TEST} -n ${LOCALPATCHES:Q}"" -a -d ${LOCALPATCHES:Q}/${PKGPATH:Q}; then \
	${ECHO} "=========================================================================="; \
	${ECHO};							\
	${ECHO} "Some of the selected build options and/or local patches may be incompatible."; \
	${ECHO} "Please try building with fewer options or patches.";	\
	${ECHO};							\
	${ECHO} "=========================================================================="; \
fi; exit 1

_PATCH_COOKIE_TMP=	${PATCH_COOKIE}.tmp
_GENERATE_PATCH_COOKIE=	\
	if ${TEST} -f ${_PATCH_COOKIE_TMP:Q}; then			\
		${CAT} ${_PATCH_COOKIE_TMP:Q} >> ${PATCH_COOKIE:Q};	\
		${RM} -f ${_PATCH_COOKIE_TMP:Q};			\
	else								\
		${TOUCH} ${TOUCH_FLAGS} ${PATCH_COOKIE:Q};		\
	fi

apply-distribution-patches:
	@${ECHO_MSG} "${_PKGSRC_IN}> Applying distribution patches for ${PKGNAME}"
.for i in ${PATCHFILES}
	@${ECHO_PATCH_MSG} "${_PKGSRC_IN}> Applying distribution patch ${i}"
	${_PKG_SILENT}${_PKG_DEBUG}cd ${_DISTDIR};			\
	${PATCH_DIST_CAT.${i:S/=/--/}} |				\
	${PATCH} ${PATCH_DIST_ARGS.${i:S/=/--/}}			\
		|| { ${ECHO} "Patch ${i} failed"; ${_PKGSRC_PATCH_FAIL}; }
	${_PKG_SILENT}${_PKG_DEBUG}${ECHO} ${i:Q} >> ${_PATCH_COOKIE_TMP:Q}
.endfor

_PKGSRC_PATCHES=	# empty
.if defined(PATCHDIR) && exists(${PATCHDIR})
_PKGSRC_PATCHES+=	${PATCHDIR}/patch-*
.endif
.if defined(LOCALPATCHES) && exists(${LOCALPATCHES}/${PKGPATH})
_PKGSRC_PATCHES+=	${LOCALPATCHES}/${PKGPATH}/patch-*
.endif

apply-pkgsrc-patches:
	@${ECHO_MSG} "${_PKGSRC_IN}> Applying pkgsrc patches for ${PKGNAME}"
	${_PKG_SILENT}${_PKG_DEBUG}					\
	set -- `${ECHO} ${_PKGSRC_PATCHES:Q}`;				\
	fail=;								\
	while ${TEST} $$# -gt 0; do					\
		i="$$1"; shift;						\
		${TEST} -f "$$i" || continue;				\
		case "$$i" in						\
		*.orig|*.rej|*~)					\
			${ECHO_MSG} "${_PKGSRC_IN}> Ignoring patchfile $$i"; \
			continue;					\
			;;						\
		${PATCHDIR}/patch-local-*) 				\
			;;						\
		${PATCHDIR}/patch-*) 					\
			if ${TEST} ! -f ${DISTINFO_FILE:Q}; then	\
				${ECHO_MSG} "**************************************"; \
				${ECHO_MSG} "Ignoring unknown patch file: $$i";	\
				${ECHO_MSG} "**************************************"; \
				continue;				\
			fi;						\
			filename=`${BASENAME} $$i`;			\
			algsum=`${AWK} '(NF == 4) && ($$2 == "('$$filename')") && ($$3 == "=") {print $$1 " " $$4}' ${DISTINFO_FILE} || ${TRUE}`; \
			if ${TEST} -z "$$algsum"; then			\
				${ECHO_MSG} "**************************************"; \
				${ECHO_MSG} "Ignoring unknown patch file: $$i"; \
				${ECHO_MSG} "**************************************"; \
				continue;				\
			fi;						\
			${ECHO} "$$algsum" |				\
			{ read alg recorded;				\
			  calcsum=`${SED} -e '/\$$NetBSD.*/d' $$i | ${DIGEST} $$alg`; \
			  ${ECHO_PATCH_MSG} "=> Verifying $$filename (using digest algorithm $$alg)"; \
			  if ${TEST} -z "$$recorded"; then		\
				${ECHO_MSG} "**************************************"; \
				${ECHO_MSG} "Ignoring unknown patch file: $$i"; \
				${ECHO_MSG} "**************************************"; \
				continue;				\
			  fi;						\
			  if ${TEST} "$$calcsum" != "$$recorded"; then	\
				${ECHO_MSG} "**************************************"; \
				${ECHO_MSG} "Patch file $$i has been modified"; \
				${ECHO_MSG} "**************************************"; \
				fail="$$fail $$filename";		\
				continue;				\
			  fi; };					\
			;;						\
		esac;							\
		${ECHO_PATCH_MSG} "${_PKGSRC_IN}> Applying pkgsrc patch $$i"; \
		fuzz=;							\
		${PATCH} -v >/dev/null 2>&1 && fuzz=${PATCH_FUZZ_FACTOR:Q}; \
		${PATCH} $$fuzz ${PATCH_ARGS} < $$i ||			\
			${ECHO_MSG} "Patch $$i failed";			\
		${ECHO} "$$i" >> ${_PATCH_COOKIE_TMP:Q};		\
	done;								\
	if ${TEST} -n "$$fail"; then					\
		${ECHO_MSG} "Patching failed due to modified patch file(s): $$fail"; \
		${_PKGSRC_PATCH_FAIL};					\
	fi
