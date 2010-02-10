# $NetBSD: Makefile,v 1.3 2010/02/10 19:17:35 joerg Exp $

PKGNAME=	${DISTNAME:S/-/-pump-/}
PKGREVISION=	2
COMMENT=	Accelerated remote compilation with distcc

.include "../../devel/distcc/Makefile.common"

PY_PATCHPLIST=		yes

# check patch-ae for build and install targets
BUILD_TARGET=		pump include-server
INSTALL_TARGET=		install-include-server

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
