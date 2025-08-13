# $NetBSD: Makefile,v 1.11 2025/08/13 11:06:26 pho Exp $

DISTNAME=	cabal-fmt-0.1.12
PKGNAME=	${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Format .cabal files
LICENSE=	gnu-gpl-v3 AND modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base	\
	containers	\
	filepath

.include "../../devel/hs-optparse-applicative/application.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
