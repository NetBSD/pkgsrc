# $NetBSD: Makefile,v 1.8 2025/01/31 15:56:11 pho Exp $

DISTNAME=	atomic-write-0.2.1.0
CATEGORIES=	devel # XXX: Should be moved to sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Atomically write to a file
LICENSE=	mit

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	filepath

.include "../../sysutils/hs-temporary/buildlink3.mk"
.include "../../devel/hs-unix-compat/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
