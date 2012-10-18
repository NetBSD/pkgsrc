# $NetBSD: mk-c.mk,v 1.2 2012/10/18 16:16:54 cheusov Exp $

MAKE_PROGRAM=	mkcmake
MAKE_ENV+=	MANDIR=${PREFIX}/${PKGMANDIR} INSTALL=${INSTALL:Q}
MAKE_ENV+=	SYSCONFDIR=${PKG_SYSCONFDIR}

do-configure:
	set -e; cd ${WRKSRC}; \
	env ${MAKE_ENV} \
	    ${MAKE_PROGRAM} ${MAKE_FLAGS} ${BUILD_MAKE_FLAGS} \
		-f ${MAKE_FILE} errorcheck
