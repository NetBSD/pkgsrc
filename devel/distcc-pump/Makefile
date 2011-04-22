# $NetBSD: Makefile,v 1.4 2011/04/22 13:45:18 obache Exp $

PKGNAME=	${DISTNAME:S/-/-pump-/}
PKGREVISION=	3
COMMENT=	Accelerated remote compilation with distcc

.include "../../devel/distcc/Makefile.common"

PY_PATCHPLIST=		yes

# check patch-ae for build and install targets
BUILD_TARGET=		pump include-server
INSTALL_TARGET=		install-include-server

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
