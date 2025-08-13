# $NetBSD: Makefile,v 1.18 2025/08/13 11:07:08 pho Exp $

DISTNAME=	pointfree-1.1.1.12
PKGNAME=	${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Convert Haskell expressions to pointfree form
LICENSE=	mit

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base

.include "../../devel/hs-haskell-src-exts/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
