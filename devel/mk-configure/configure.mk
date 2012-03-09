# $NetBSD: configure.mk,v 1.4 2012/03/09 18:56:22 cheusov Exp $

MAKE_ENV+=	MANDIR=${PREFIX}/${PKGMANDIR} INSTALL=${INSTALL:Q}

do-configure:
	set -e; cd ${WRKSRC}; \
	env ${MAKE_ENV} \
	    ${MAKE_PROGRAM} ${MAKE_FLAGS} ${BUILD_MAKE_FLAGS} \
		-f ${MAKE_FILE} errorcheck
