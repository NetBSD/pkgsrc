# $NetBSD: Makefile,v 1.9 2023/02/07 01:41:09 pho Exp $

DISTNAME=	commonmark-pandoc-0.2.1.3
PKGREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	pho@cielonegro.org
COMMENT=	Bridge between commonmark and pandoc AST
LICENSE=	modified-bsd

.include "../../textproc/hs-commonmark/buildlink3.mk"
.include "../../textproc/hs-commonmark-extensions/buildlink3.mk"
.include "../../textproc/hs-pandoc-types/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
