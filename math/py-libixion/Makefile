# $NetBSD: Makefile,v 1.2 2019/12/04 18:58:47 nros Exp $

.include "../../math/libixion/Makefile.common"

PKGNAME= 	${PYPKGPREFIX}-${DISTNAME}

USE_TOOLS+=	aclocal autoconf automake
BUILD_DIRS=	src/python
PY_PATCHPLIST=	yes

PYTHON_VERSIONS_INCOMPATIBLE= 27

pre-configure:
	set -e; cd ${WRKSRC}; \
		aclocal; automake -a --foreign -i; autoconf

.include "../../lang/python/extension.mk"

BUILDLINK_FNAME_TRANSFORM.${PYPACKAGE}+= -e "s|-${PYVERSSUFFIX}.pc|3.pc|g"

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/mdds/buildlink3.mk"
.include "../../math/libixion/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
