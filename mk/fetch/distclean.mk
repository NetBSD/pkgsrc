# $NetBSD: distclean.mk,v 1.1 2006/06/06 03:05:48 jlam Exp $

.PHONY: pre-distclean
.if !target(pre-distclean)
pre-distclean:
	@${DO_NADA}
.endif

.PHONY: distclean
.if !target(distclean)
distclean: pre-distclean clean
	@${PHASE_MSG} "Dist cleaning for ${PKGNAME}"
	${_PKG_SILENT}${_PKG_DEBUG}if [ -d ${_DISTDIR} ]; then		\
		cd ${_DISTDIR} &&					\
		${TEST} -z "${DISTFILES}" || ${RM} -f ${DISTFILES};	\
                if [ "${PKG_RESUME_TRANSFERS:M[Yy][Ee][Ss]}" ]; then    \
                    ${TEST} -z "${DISTFILES}.temp" || ${RM} -f ${DISTFILES}.temp;    \
                fi;                                                     \
		${TEST} -z "${PATCHFILES}" || ${RM} -f ${PATCHFILES};	\
	fi
.  if defined(DIST_SUBDIR)
	-${_PKG_SILENT}${_PKG_DEBUG}					\
	${TEST} ! -d ${_DISTDIR} || ${RMDIR} ${_DISTDIR} 2>/dev/null
.  endif
	${_PKG_SILENT}${_PKG_DEBUG}${RM} -f README.html
.endif
