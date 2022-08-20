# $NetBSD: Makefile,v 1.7 2022/08/20 08:08:22 wiz Exp $

DISTNAME=	commonmark-pandoc-0.2.1.2
PKGREVISION=	3
CATEGORIES=	textproc

MAINTAINER=	pho@cielonegro.org
COMMENT=	Bridge between commonmark and pandoc AST
LICENSE=	modified-bsd

.include "../../textproc/hs-commonmark/buildlink3.mk"
.include "../../textproc/hs-commonmark-extensions/buildlink3.mk"
.include "../../textproc/hs-pandoc-types/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
