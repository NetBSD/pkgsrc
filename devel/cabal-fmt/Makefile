# $NetBSD: Makefile,v 1.7 2024/05/09 01:31:42 pho Exp $

# NOTE: Cannot update to >=0.1.12 because the require GHC 10.
DISTNAME=	cabal-fmt-0.1.11
PKGNAME=	${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Format .cabal files
LICENSE=	gnu-gpl-v3 AND modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base		\
	bytestring

.include "../../devel/hs-optparse-applicative/application.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
