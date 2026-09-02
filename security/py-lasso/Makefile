# $NetBSD: Makefile,v 1.61 2026/09/02 19:04:20 wiz Exp $

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	3
COMMENT=	Liberty Alliance Single Sign On binding for Python

CONFIGURE_ARGS+=	--disable-php5
CONFIGURE_ARGS+=	--disable-php7
CONFIGURE_ARGS+=	--disable-perl

INSTALL_DIRS=	bindings/python

PY_PATCHPLIST=	yes

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} > 311
# needs distutils
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
.endif

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/extension.mk"
.include "../../security/lasso/buildlink3.mk"
.include "../../security/lasso/Makefile.common"
.include "../../mk/bsd.pkg.mk"
