# $NetBSD: distclean.mk,v 1.3 2006/07/18 22:41:06 jlam Exp $

.PHONY: pre-distclean
.if !target(pre-distclean)
pre-distclean:
	@${DO_NADA}
.endif

.PHONY: distclean
.if !target(distclean)
distclean: pre-distclean clean
	@${PHASE_MSG} "Dist cleaning for ${PKGNAME}"
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${TEST} -d ${_DISTDIR} || exit 0;				\
	cd ${_DISTDIR};							\
	${RM} -f ${ALLFILES};						\
	${RM} -f ${ALLFILES:S/$/.pkgsrc.resume/}
.  if defined(DIST_SUBDIR)
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${TEST} ! -d ${_DISTDIR}					\
	|| ${RMDIR} ${_DISTDIR} 2>/dev/null				\
	|| ${TRUE}
.  endif
	${_PKG_SILENT}${_PKG_DEBUG}${RM} -f README.html
.endif
