# $NetBSD: Makefile,v 1.15 2020/12/04 20:45:08 nia Exp $

PKGNAME=	${DISTNAME:S/-/-pump-/:S/rc1//}
PKGREVISION=	2
COMMENT=	Accelerated remote compilation with distcc

.include "../../devel/distcc/Makefile.common"

PY_PATCHPLIST=		yes
PYTHON_VERSIONS_INCOMPATIBLE=	27

# check patch-ae for build and install targets
BUILD_TARGET=		pump include-server
INSTALL_TARGET=		install-include-server

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
