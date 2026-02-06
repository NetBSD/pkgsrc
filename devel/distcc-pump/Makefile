# $NetBSD: Makefile,v 1.21 2026/02/06 07:48:29 adam Exp $

PKGNAME=	${DISTNAME:S/-/-pump-/}
PKGREVISION=	2
COMMENT=	Accelerated remote compilation with distcc

.include "../../devel/distcc/Makefile.common"

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

PY_PATCHPLIST=		yes
PLIST_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX}

# check patch-Makefile.in for build and install targets
BUILD_TARGET=		pump include-server
INSTALL_TARGET=		install-include-server

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
