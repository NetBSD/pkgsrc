# $NetBSD: Makefile,v 1.6 2014/01/25 10:30:01 wiz Exp $

PKGNAME=	${DISTNAME:S/-/-pump-/}
PKGREVISION=	4
COMMENT=	Accelerated remote compilation with distcc

.include "../../devel/distcc/Makefile.common"

PY_PATCHPLIST=		yes
PYTHON_VERSIONS_INCOMPATIBLE=	33 # not yet ported as of 3.1

# check patch-ae for build and install targets
BUILD_TARGET=		pump include-server
INSTALL_TARGET=		install-include-server

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
