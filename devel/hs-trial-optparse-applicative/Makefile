# $NetBSD: Makefile,v 1.5 2025/08/13 11:07:03 pho Exp $

DISTNAME=	trial-optparse-applicative-0.0.0.0
PKGREVISION=	4
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Trial helper functions for optparse-applicative
LICENSE=	mpl-2.0

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base	\
	optparse-applicative

.include "../../devel/hs-optparse-applicative/buildlink3.mk"
.include "../../devel/hs-trial/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
