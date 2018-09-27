# $NetBSD: Makefile,v 1.13 2018/09/27 21:36:12 tnn Exp $

PKGNAME=	${DISTNAME:S/-/-pump-/:S/rc1//}
COMMENT=	Accelerated remote compilation with distcc

.include "../../devel/distcc/Makefile.common"

PY_PATCHPLIST=		yes
PYTHON_VERSIONS_INCOMPATIBLE=	27

# check patch-ae for build and install targets
BUILD_TARGET=		pump include-server
INSTALL_TARGET=		install-include-server

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
