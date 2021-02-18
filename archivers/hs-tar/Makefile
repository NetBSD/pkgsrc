# $NetBSD: Makefile,v 1.3 2021/02/18 15:07:28 mef Exp $

DISTNAME=	tar-0.5.1.1
CATEGORIES=	archivers

MAINTAINER=	pho@cielonegro.org
COMMENT=	Reading, writing, and manipulating ".tar" archive files
LICENSE=	modified-bsd

BUILDLINK_API_DEPENDS.ghc+=	ghc<8.10
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
