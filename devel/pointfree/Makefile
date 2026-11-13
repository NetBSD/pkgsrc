# $NetBSD: Makefile,v 1.19 2026/11/13 14:39:27 pho Exp $

DISTNAME=	pointfree-1.1.1.12
PKGNAME=	${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Convert Haskell expressions to pointfree form
LICENSE=	mit

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base

.include "../../devel/hs-haskell-src-exts/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
