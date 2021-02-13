# $NetBSD: Makefile,v 1.5 2021/02/13 08:01:01 mef Exp $

DISTNAME=	regex-base-0.94.0.0
CATEGORIES=	textproc

MAINTAINER=	pho@cielonegro.org
COMMENT=	Replaces/Enhances Haskell Text.Regex
LICENSE=	modified-bsd

BUILDLINK_API_DEPENDS.ghc+=	ghc<9.0
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
