# $NetBSD: plugin.mk,v 1.1 2023/01/09 00:14:06 sekiya Exp $
#

INSTALLATION_DIRS+=	libexec/nagios

do-build:
	cd ${WRKSRC}/lib && ${SETENV} ${MAKE_ENV} \
	${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKE_FILE}
	cd ${WRKSRC}/gl && ${SETENV} ${MAKE_ENV} \
	${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKE_FILE}
.if ${BINARY_TARGET:D1}
	cd ${WRKSRC}/plugins && ${SETENV} ${MAKE_ENV}	\
	${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKE_FILE} ${BINARY_TARGET}
.endif
.if ${SCRIPT_TARGET:D1}
	cd ${WRKSRC}/plugins-scripts && ${SETENV} ${MAKE_ENV}	\
	${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKE_FILE} ${SCRIPT_TARGET}
.endif

do-install:
.if ${BINARY_TARGET:D1}
	for PROG in ${BINARY_TARGET}; do	\
		${INSTALL_PROGRAM} ${WRKSRC}/plugins/$${PROG}	\
		${DESTDIR}${PREFIX}/libexec/nagios;	\
	done
.endif
.if ${SCRIPT_TARGET:D1}
	for PROG in ${SCRIPT_TARGET}; do	\
		${INSTALL_SCRIPT} ${WRKSRC}/plugins-scripts/$${PROG}	\
		${DESTDIR}${PREFIX}/libexec/nagios;	\
	done
.endif
