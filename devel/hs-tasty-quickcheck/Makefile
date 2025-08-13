# $NetBSD: Makefile,v 1.8 2025/08/13 11:07:01 pho Exp $

DISTNAME=	tasty-quickcheck-0.11.1
PKGREVISION=	3
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
