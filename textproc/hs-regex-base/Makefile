# $NetBSD: Makefile,v 1.6 2021/02/18 15:07:26 mef Exp $

DISTNAME=	regex-base-0.94.0.0
CATEGORIES=	textproc

MAINTAINER=	pho@cielonegro.org
COMMENT=	Replaces/Enhances Haskell Text.Regex
LICENSE=	modified-bsd

BUILDLINK_API_DEPENDS.ghc+=	ghc<8.10
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
