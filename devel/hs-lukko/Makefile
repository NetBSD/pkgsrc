# $NetBSD: Makefile,v 1.3 2021/02/18 15:07:28 mef Exp $

DISTNAME=	lukko-0.1.1.1
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	File locking
LICENSE=	gnu-gpl-v2 AND modified-bsd

BUILDLINK_API_DEPENDS.ghc+=	ghc<8.10
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
