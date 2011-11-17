MAKE_ENV+=	MANDIR=${PREFIX}/${PKGMANDIR} INSTALL=${INSTALL}

do-configure:
	set -e; cd ${WRKSRC}; \
	env ${MAKE_ENV} \
	    ${MAKE_PROGRAM} ${MAKE_FLAGS} ${BUILD_MAKE_FLAGS} \
		-f ${MAKE_FILE} errorcheck
