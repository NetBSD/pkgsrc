# $NetBSD: Makefile,v 1.14 2023/10/29 10:41:58 pho Exp $

DISTNAME=	MonadRandom-0.6
PKGREVISION=	2
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
