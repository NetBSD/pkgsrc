# $NetBSD: Makefile,v 1.7 2014/04/25 16:13:32 adam Exp $

PKGNAME=	${DISTNAME:S/-/-pump-/:S/rc1//}
COMMENT=	Accelerated remote compilation with distcc

.include "../../devel/distcc/Makefile.common"

PY_PATCHPLIST=		yes
PYTHON_VERSIONS_INCOMPATIBLE=	33 # not yet ported as of 3.1

# check patch-ae for build and install targets
BUILD_TARGET=		pump include-server
INSTALL_TARGET=		install-include-server

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
