# $NetBSD: Makefile,v 1.1 2017/08/26 10:07:29 fhajny Exp $

.include "../../net/freeradius/Makefile.module"

PKGNAME=		${DISTNAME:S/-server/-python/}
COMMENT=		Free RADIUS rlm_python module
CATEGORIES=		net

PYTHON_VERSIONS_ACCEPTED=	27

CONFIGURE_ARGS+=    --with-rlm_python

do-install:
	${INSTALL_LIB} ${WRKSRC}/build/lib/.libs/rlm_python.so ${DESTDIR}${PREFIX}/lib

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
