# $NetBSD: Makefile,v 1.49 2023/06/06 12:42:16 riastradh Exp $

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	17
COMMENT=	Liberty Alliance Single Sign On binding for Python

TOOL_DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

CONFIGURE_ARGS+=	--disable-php4
CONFIGURE_ARGS+=	--disable-perl

INSTALL_DIRS=	bindings/python

PY_PATCHPLIST=	yes
PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 2.4.1

.include "../../lang/python/extension.mk"

.include "../../security/lasso/buildlink3.mk"

.include "../../security/lasso/Makefile.common"
