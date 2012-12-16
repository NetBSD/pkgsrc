# $NetBSD: Makefile,v 1.14 2012/12/16 01:52:34 obache Exp $
#

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	8
COMMENT=	Libery Alliance Single Sign On binding for Python

.include "../../lang/python/pyversion.mk"

BUILD_DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

CONFIGURE_ARGS+=	--disable-php4
CONFIGURE_ARGS+=	--disable-perl

INSTALL_DIRS=	bindings/python

PY_PATCHPLIST=	yes
.include "../../lang/python/extension.mk"

.include "../../security/lasso/buildlink3.mk"

.include "../../security/lasso/Makefile.common"

