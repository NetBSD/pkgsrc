# $NetBSD: Makefile,v 1.1 2023/10/27 11:58:38 pho Exp $

DISTNAME=	digits-0.3.1
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
