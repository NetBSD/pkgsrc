# $NetBSD: Makefile,v 1.2 2009/02/09 22:56:22 joerg Exp $

PKGNAME=	${DISTNAME:S/-/-pump-/}
PKGREVISION=	1
COMMENT=	Accelerated remote compilation with distcc

.include "../../devel/distcc/Makefile.common"

PY_PATCHPLIST=		yes

# check patch-ae for build and install targets
BUILD_TARGET=		pump include-server
INSTALL_TARGET=		install-include-server

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
