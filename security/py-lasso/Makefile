# $NetBSD: Makefile,v 1.54 2024/11/01 00:53:32 wiz Exp $

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	22
COMMENT=	Liberty Alliance Single Sign On binding for Python

CONFIGURE_ARGS+=	--disable-php4
CONFIGURE_ARGS+=	--disable-perl

INSTALL_DIRS=	bindings/python

PY_PATCHPLIST=	yes
PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 2.4.1

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/extension.mk"

.include "../../security/lasso/buildlink3.mk"

.include "../../security/lasso/Makefile.common"
