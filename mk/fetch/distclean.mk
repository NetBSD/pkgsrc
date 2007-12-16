# $NetBSD: distclean.mk,v 1.5 2007/12/16 02:51:24 obache Exp $
#
# === make targets for pkgsrc users ===
#
# distclean:
#	Removes the distfiles of the current package.
#

.PHONY: pre-distclean
.if !target(pre-distclean)
pre-distclean:
	@${DO_NADA}
.endif

.PHONY: distclean
.if !target(distclean)
distclean: pre-distclean clean
	@${PHASE_MSG} "Dist cleaning for ${PKGNAME}"
	${RUN} [ -d ${_DISTDIR} ] || exit 0;				\
	cd ${_DISTDIR};							\
	${RM} -f ${ALLFILES} ${ALLFILES:S/$/.pkgsrc.resume/}
.  if defined(DIST_SUBDIR)
	${RUN} ${RMDIR} ${_DISTDIR} 2>/dev/null || ${TRUE}
.  endif
	${RUN} ${RM} -f README.html
.endif
