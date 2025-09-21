# $NetBSD: Makefile,v 1.23 2025/09/21 18:15:09 wiz Exp $

PKGREVISION= 1
.include "../../math/libixion/Makefile.common"

PKGNAME= 	${PYPKGPREFIX}-${DISTNAME}

USE_TOOLS+=	aclocal autoconf automake
BUILD_DIRS=	src/python
PY_PATCHPLIST=	yes

PYTHON_VERSIONS_INCOMPATIBLE= 27

CONFIGURE_ARGS+=	--with-boost=${BUILDLINK_DIR.boost-libs}

pre-configure:
	set -e; cd ${WRKSRC}; \
		aclocal; automake -a --foreign -i; autoconf

.include "../../lang/python/extension.mk"

BUILDLINK_FNAME_TRANSFORM.${PYPACKAGE}+= -e "s|-${PYVERSSUFFIX}.pc|3.pc|g"

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/mdds/buildlink3.mk"
.include "../../math/libixion/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
