# $NetBSD: Makefile,v 1.11 2025/05/06 12:07:34 wiz Exp $

.include "../../net/freeradius/Makefile.module"

PKGNAME=	${DISTNAME:S/-server/-python/}
COMMENT=	Free RADIUS rlm_python module

CONFIGURE_ARGS+=	--with-modules=rlm_python3

PYTHON_VERSIONS_INCOMPATIBLE=	27

pre-configure:
	cd ${BUILDLINK_DIR}/bin && ${LN} -s ${PREFIX}/bin/python${PYVERSSUFFIX}-config python3-config

do-install:
	${INSTALL_LIB} ${WRKSRC}/build/lib/.libs/rlm_python3.${SHLIB_EXT} \
		${DESTDIR}${PREFIX}/lib

.include "../../lang/python/pyversion.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
