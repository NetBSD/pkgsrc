# $NetBSD: Makefile,v 1.9 2026/11/13 14:39:20 pho Exp $

DISTNAME=	tasty-quickcheck-0.11.1
PKGREVISION=	4
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	QuickCheck support for the Tasty test framework
LICENSE=	mit

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	random

.include "../../devel/hs-optparse-applicative/buildlink3.mk"
.include "../../devel/hs-QuickCheck/buildlink3.mk"
.include "../../devel/hs-random/buildlink3.mk"
.include "../../devel/hs-tagged/buildlink3.mk"
.include "../../devel/hs-tasty/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
