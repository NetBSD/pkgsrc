# $NetBSD: Makefile,v 1.7 2026/11/09 14:10:34 pho Exp $

DISTNAME=	relude-1.2.2.0
PKGREVISION=	3
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Alternative Haskell standard library
LICENSE=	mit

HASKELL_UNRESTRICT_DEPENDENCIES+=	ghc-prim

.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
