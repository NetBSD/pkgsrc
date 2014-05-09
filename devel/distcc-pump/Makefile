# $NetBSD: Makefile,v 1.8 2014/05/09 07:36:59 wiz Exp $

PKGNAME=	${DISTNAME:S/-/-pump-/:S/rc1//}
COMMENT=	Accelerated remote compilation with distcc

.include "../../devel/distcc/Makefile.common"

PY_PATCHPLIST=		yes
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 3.1

# check patch-ae for build and install targets
BUILD_TARGET=		pump include-server
INSTALL_TARGET=		install-include-server

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
