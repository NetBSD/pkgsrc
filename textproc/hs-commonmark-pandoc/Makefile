# $NetBSD: Makefile,v 1.3 2022/01/18 02:48:25 pho Exp $

DISTNAME=	commonmark-pandoc-0.2.0.1
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
