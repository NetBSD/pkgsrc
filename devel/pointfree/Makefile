# $NetBSD: Makefile,v 1.9 2023/02/07 01:40:56 pho Exp $

DISTNAME=	pointfree-1.1.1.9
PKGNAME=	${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Convert Haskell expressions to pointfree form
LICENSE=	mit

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base

.include "../../devel/hs-haskell-src-exts/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
