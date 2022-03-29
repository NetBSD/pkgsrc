# $NetBSD: Makefile,v 1.16 2022/03/29 18:16:25 wiz Exp $

PKGNAME=	${DISTNAME:S/-/-pump-/:S/rc1//}
PKGREVISION=	3
COMMENT=	Accelerated remote compilation with distcc

.include "../../devel/distcc/Makefile.common"

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

PY_PATCHPLIST=		yes
PLIST_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX}
PYTHON_VERSIONS_INCOMPATIBLE=	27

# check patch-ae for build and install targets
BUILD_TARGET=		pump include-server
INSTALL_TARGET=		install-include-server

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
