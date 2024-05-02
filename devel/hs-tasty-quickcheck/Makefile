# $NetBSD: Makefile,v 1.3 2024/05/02 04:03:46 pho Exp $

DISTNAME=	tasty-quickcheck-0.10.3
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	QuickCheck support for the Tasty test framework
LICENSE=	mit

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	QuickCheck

.include "../../devel/hs-optparse-applicative/buildlink3.mk"
.include "../../devel/hs-QuickCheck/buildlink3.mk"
.include "../../devel/hs-random/buildlink3.mk"
.include "../../devel/hs-tagged/buildlink3.mk"
.include "../../devel/hs-tasty/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
