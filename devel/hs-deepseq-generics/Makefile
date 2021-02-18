# $NetBSD: Makefile,v 1.4 2021/02/18 15:07:28 mef Exp $

DISTNAME=	deepseq-generics-0.2.0.0
CATEGORIES=	devel

MAINTAINER=	szptvlfn@NetBSD.org
COMMENT=	GHC.Generics-based Control.DeepSeq.rnf implementation
LICENSE=	modified-bsd

BUILDLINK_API_DEPENDS.ghc+=	ghc<8.10
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
