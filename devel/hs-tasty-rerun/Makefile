# $NetBSD: Makefile,v 1.9 2026/11/13 14:39:20 pho Exp $

DISTNAME=	tasty-rerun-1.1.19
PKGREVISION=	6
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Rerun only tests which failed in a previous test run
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base	\
	containers

.include "../../devel/hs-optparse-applicative/buildlink3.mk"
.include "../../devel/hs-split/buildlink3.mk"
.include "../../devel/hs-tagged/buildlink3.mk"
.include "../../devel/hs-tasty/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
