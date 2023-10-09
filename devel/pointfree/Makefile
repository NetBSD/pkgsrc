# $NetBSD: Makefile,v 1.10 2023/10/09 04:54:36 pho Exp $

DISTNAME=	pointfree-1.1.1.9
PKGNAME=	${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Convert Haskell expressions to pointfree form
LICENSE=	mit

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base

.include "../../devel/hs-haskell-src-exts/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
