# $NetBSD: Makefile,v 1.18 2022/06/30 11:18:13 nia Exp $

PKGNAME=	${DISTNAME:S/-/-pump-/}
PKGREVISION=	1
COMMENT=	Accelerated remote compilation with distcc

.include "../../devel/distcc/Makefile.common"

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

PY_PATCHPLIST=		yes
PLIST_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX}
PYTHON_VERSIONS_INCOMPATIBLE=	27

# check patch-Makefile.in for build and install targets
BUILD_TARGET=		pump include-server
INSTALL_TARGET=		install-include-server

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
