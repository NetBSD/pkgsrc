# $NetBSD: Makefile,v 1.6 2022/02/26 03:58:26 pho Exp $

DISTNAME=	commonmark-pandoc-0.2.1.2
PKGREVISION=	2
CATEGORIES=	textproc

MAINTAINER=	pho@cielonegro.org
COMMENT=	Bridge between commonmark and pandoc AST
LICENSE=	modified-bsd

.include "../../textproc/hs-commonmark/buildlink3.mk"
.include "../../textproc/hs-commonmark-extensions/buildlink3.mk"
.include "../../textproc/hs-pandoc-types/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
