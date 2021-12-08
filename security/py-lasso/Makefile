# $NetBSD: Makefile,v 1.44 2021/12/08 16:06:23 adam Exp $

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	13
COMMENT=	Liberty Alliance Single Sign On binding for Python

BUILD_DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

CONFIGURE_ARGS+=	--disable-php4
CONFIGURE_ARGS+=	--disable-perl

INSTALL_DIRS=	bindings/python

PY_PATCHPLIST=	yes
PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 2.4.1

.include "../../lang/python/extension.mk"

.include "../../security/lasso/buildlink3.mk"

.include "../../security/lasso/Makefile.common"
