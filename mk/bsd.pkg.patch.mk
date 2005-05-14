# $NetBSD: bsd.pkg.patch.mk,v 1.3 2005/05/14 22:31:04 jlam Exp $
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
    (defined(PATCHDIR) && exists(${PATCHDIR}))
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
PATCH_DEBUG_TMP=	yes
.else
PATCH_DEBUG_TMP=	no
.endif

PATCH_STRIP?=		-p0
.if ${PATCH_DEBUG_TMP} == "yes"
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
.  elif ${PATCH_DEBUG_TMP} == "yes"
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

.if empty(PKGSRC_SHOW_PATCH_ERRORMSG:M[yY][eE][sS])
PKGSRC_PATCH_FAIL=	exit 1
.else
PKGSRC_PATCH_FAIL=							\
if [ -n "${PKG_OPTIONS}" ] || [ -n "${_LOCALPATCHFILES}" ]; then	\
	${ECHO} "=========================================================================="; \
	${ECHO};							\
	${ECHO} "Some of the selected build options and/or local patches may be incompatible."; \
	${ECHO} "Please try building with fewer options or patches.";	\
	${ECHO};							\
	${ECHO} "=========================================================================="; \
fi; exit 1
.endif

# Patch

# LOCALPATCHES contains the location of local patches to packages
#	that are maintained in a directory tree reflecting the same
#	hierarchy as the pkgsrc tree, i.e. local patches for www/apache
#	would be found as ${LOCALPATCHES}/www/apache/*.
#
.if defined(LOCALPATCHES)
_DFLT_LOCALPATCHFILES=	${LOCALPATCHES}/${PKGPATH}/*
_LOCALPATCHFILES=	${_DFLT_LOCALPATCHFILES}
.endif

.PHONY: do-patch
.if !target(do-patch)
do-patch: uptodate-digest
.  if defined(PATCHFILES)
	@${ECHO_MSG} "${_PKGSRC_IN}> Applying distribution patches for ${PKGNAME}"
.    for i in ${PATCHFILES}
	${_PKG_SILENT}${_PKG_DEBUG}cd ${_DISTDIR};			\
	if [ ${PATCH_DEBUG_TMP} = yes ]; then				\
		${ECHO_MSG} "${_PKGSRC_IN}> Applying distribution patch ${i}"; \
	fi;								\
	${PATCH_DIST_CAT.${i:S/=/--/}} |				\
	${PATCH} ${PATCH_DIST_ARGS.${i:S/=/--/}}			\
		|| { ${ECHO} "Patch ${i} failed"; ${PKGSRC_PATCH_FAIL}; }
.    endfor
.  endif
	${_PKG_SILENT}${_PKG_DEBUG}					\
	patchlist="";							\
	if [ -d ${PATCHDIR} ]; then					\
		if [ "`${ECHO} ${PATCHDIR}/patch-*`" = "${PATCHDIR}/patch-*" ]; then \
			${ECHO_MSG} "${_PKGSRC_IN}> Ignoring empty patch directory"; \
			if [ -d ${PATCHDIR}/CVS ]; then			\
				${ECHO_MSG} "${_PKGSRC_IN}> Perhaps you forgot the -P flag to 'cvs checkout' or 'cvs update'?"; \
			fi;						\
		else							\
			patchlist=`${ECHO} ${PATCHDIR}/patch-*`;	\
		fi;							\
	fi;								\
	if [ "X${_LOCALPATCHFILES}" = "X${_DFLT_LOCALPATCHFILES}" ]; then \
		localpatchfiles="`${ECHO} ${_LOCALPATCHFILES}`";	\
		if [ "$${localpatchfiles}" != "${_LOCALPATCHFILES}" ]; then \
			patchlist="$${patchlist} $${localpatchfiles}";	\
		fi;							\
	else								\
		patchlist=`${ECHO} $${patchlist} ${_LOCALPATCHFILES}`;	\
	fi;								\
	if [ -n "$${patchlist}" ]; then					\
		${ECHO_MSG} "${_PKGSRC_IN}> Applying pkgsrc patches for ${PKGNAME}" ; \
		fail="";						\
		for i in $${patchlist}; do				\
			if [ ! -f "$$i" ]; then				\
				${ECHO_MSG} "${_PKGSRC_IN}> $$i is not a valid patch file - skipping"; \
				continue; 				\
			fi;						\
			case $$i in					\
			*.orig|*.rej|*~)				\
				${ECHO_MSG} "${_PKGSRC_IN}> Ignoring patchfile $$i"; \
				continue;				\
				;;					\
			${PATCHDIR}/patch-local-*) 			\
				;;					\
			${PATCHDIR}/patch-*)	 			\
				if [ -f ${DISTINFO_FILE} ]; then	\
					filename=`expr $$i : '.*/\(.*\)'`; \
					algsum=`${AWK} 'NF == 4 && $$2 == "('$$filename')" && $$3 == "=" {print $$1 " " $$4}' ${DISTINFO_FILE} || ${TRUE}`; \
					if [ "X$$algsum" != "X" ]; then	\
						alg=`${ECHO} $$algsum | ${AWK} '{ print $$1 }'`; \
						recorded=`${ECHO} $$algsum | ${AWK} '{ print $$2 }'`; \
						calcsum=`${SED} -e '/\$$NetBSD.*/d' $$i | ${DIGEST} $$alg`; \
						if [ ${PATCH_DEBUG_TMP} = yes ]; then \
							${ECHO_MSG} "=> Verifying $$filename (using digest algorithm $$alg)"; \
						fi;			\
					fi;				\
					if [ "X$$algsum" = "X" -o "X$$recorded" = "X" ]; then \
						${ECHO_MSG} "**************************************"; \
						${ECHO_MSG} "Ignoring unknown patch file: $$i"; \
						${ECHO_MSG} "**************************************"; \
						continue;		\
					fi;				\
					if [ "X$$calcsum" != "X$$recorded" ]; then \
						${ECHO_MSG} "**************************************"; \
						${ECHO_MSG} "Patch file $$i has been modified"; \
						${ECHO_MSG} "**************************************"; \
						fail="$$fail $$filename"; \
						continue;		\
					fi;				\
				else					\
					${ECHO_MSG} "**************************************"; \
					${ECHO_MSG} "Ignoring unknown patch file: $$i"; \
					${ECHO_MSG} "**************************************"; \
					continue;			\
				fi;					\
				;;					\
			esac;						\
			if [ ${PATCH_DEBUG_TMP} = yes ]; then		\
				${ECHO_MSG} "${_PKGSRC_IN}> Applying pkgsrc patch $$i" ; \
			fi;						\
			fuzz="";					\
			${PATCH} -v > /dev/null 2>&1 && fuzz="${PATCH_FUZZ_FACTOR}"; \
			${PATCH} $$fuzz ${PATCH_ARGS} < $$i ||		\
				{ ${ECHO} Patch $$i failed ; ${PKGSRC_PATCH_FAIL}; }; \
		done;							\
		if [ "X$$fail" != "X" ]; then				\
			${ECHO_MSG} "Patching failed due to modified patch file(s): $$fail"; \
			${PKGSRC_PATCH_FAIL};				\
		fi;							\
	fi
.endif
