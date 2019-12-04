# $NetBSD: Makefile,v 1.1 2019/12/04 13:31:43 nros Exp $

.include "../../math/libixion/Makefile.common"

PKGNAME= 	${PYPKGPREFIX}-${DISTNAME}

USE_TOOLS+=	aclocal autoconf automake
BUILD_DIRS=	src/python
PY_PATCHPLIST=	yes

pre-configure:
	${LN} -s ${BUILDLINK_DIR}/lib/pkgconfig/python-${PYVERSSUFFIX}.pc \
		${BUILDLINK_DIR}/lib/pkgconfig/python3.pc
	set -e; cd ${WRKSRC}; \
		aclocal; automake -a --foreign -i; autoconf

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/mdds/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../math/libixion/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
