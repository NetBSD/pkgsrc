# $NetBSD: Makefile,v 1.5 2019/09/24 10:48:45 adam Exp $

.include "../../net/freeradius/Makefile.module"

PKGNAME=	${DISTNAME:S/-server/-python/}
COMMENT=	Free RADIUS rlm_python module

CONFIGURE_ARGS+=	--with-rlm_python
CONFIGURE_ARGS+=	--with-rlm-python-bin=${PYTHONBIN}
CONFIGURE_ARGS+=	--without-rlm_ldap
CONFIGURE_ARGS+=	--without-rlm_yubikey

do-install:
	${INSTALL_LIB} ${WRKSRC}/build/lib/.libs/rlm_python.${SOEXT} \
		${DESTDIR}${PREFIX}/lib

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
