# $NetBSD: Makefile,v 1.17 2025/03/05 03:39:37 pho Exp $

DISTNAME=	pointfree-1.1.1.12
PKGNAME=	${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Convert Haskell expressions to pointfree form
LICENSE=	mit

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base

.include "../../devel/hs-haskell-src-exts/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
