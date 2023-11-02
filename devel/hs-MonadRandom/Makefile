# $NetBSD: Makefile,v 1.15 2023/11/02 06:36:16 pho Exp $

DISTNAME=	MonadRandom-0.6
PKGREVISION=	3
CATEGORIES=	devel

MAINTAINER=	szptvlfn@NetBSD.org
COMMENT=	Random-number generation monad
LICENSE=	2-clause-bsd
# http://www.haskell.org/haskellwiki/HaskellWiki:Copyrights

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	primitive

.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../devel/hs-random/buildlink3.mk"
.include "../../devel/hs-transformers-compat/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
