# $NetBSD: Makefile,v 1.10 2025/03/05 03:38:59 pho Exp $

DISTNAME=	cabal-fmt-0.1.12
PKGNAME=	${DISTNAME}
PKGREVISION=	2
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
