# $NetBSD: Makefile,v 1.20 2023/08/14 05:24:06 wiz Exp $

PKGNAME=	${DISTNAME:S/-/-pump-/}
PKGREVISION=	2
COMMENT=	Accelerated remote compilation with distcc

.include "../../devel/distcc/Makefile.common"

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

PY_PATCHPLIST=		yes
PLIST_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX}
PYTHON_VERSIONS_INCOMPATIBLE=	27

# check patch-Makefile.in for build and install targets
BUILD_TARGET=		pump include-server
INSTALL_TARGET=		install-include-server

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
