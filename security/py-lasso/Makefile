# $NetBSD: Makefile,v 1.23 2014/05/29 23:37:26 wiz Exp $

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	13
COMMENT=	Liberty Alliance Single Sign On binding for Python

BUILD_DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

CONFIGURE_ARGS+=	--disable-php4
CONFIGURE_ARGS+=	--disable-perl

INSTALL_DIRS=	bindings/python

PY_PATCHPLIST=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 2.3.6

.include "../../lang/python/extension.mk"

.include "../../security/lasso/buildlink3.mk"

.include "../../security/lasso/Makefile.common"
