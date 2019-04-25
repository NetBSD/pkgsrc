# $NetBSD: Makefile,v 1.3 2019/04/25 07:33:10 maya Exp $

PKGREVISION= 1
.include "../../net/freeradius/Makefile.module"

PKGNAME=		${DISTNAME:S/-server/-python/}
COMMENT=		Free RADIUS rlm_python module
CATEGORIES=		net

PYTHON_VERSIONS_ACCEPTED=	27

CONFIGURE_ARGS+=    --with-rlm_python
CONFIGURE_ARGS+=    --without-rlm_ldap

do-install:
	${INSTALL_LIB} ${WRKSRC}/build/lib/.libs/rlm_python.so ${DESTDIR}${PREFIX}/lib

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
