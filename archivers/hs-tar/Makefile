# $NetBSD: Makefile,v 1.2 2021/02/13 08:00:57 mef Exp $

DISTNAME=	tar-0.5.1.1
CATEGORIES=	archivers

MAINTAINER=	pho@cielonegro.org
COMMENT=	Reading, writing, and manipulating ".tar" archive files
LICENSE=	modified-bsd

BUILDLINK_API_DEPENDS.ghc+=	ghc<9.0
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
