# $NetBSD: Makefile,v 1.3 2024/05/09 01:32:25 pho Exp $

DISTNAME=	digits-0.3.1
PKGREVISION=	2
CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Converts integers to lists of digits and back
LICENSE=	modified-bsd

HASKELL_ENABLE_TESTS=	yes

# Its Setup.lhs is outdated, not compiling, and not needed anymore.
post-extract:
	${RM} -f ${WRKSRC}/Setup.lhs

.include "../../devel/hs-QuickCheck/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
