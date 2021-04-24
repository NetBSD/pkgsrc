# $NetBSD: Makefile,v 1.2 2021/04/24 14:40:31 pho Exp $

DISTNAME=	cmark-gfm-0.2.2
CATEGORIES=	textproc

MAINTAINER=	pho@cielonegro.org
COMMENT=	Fast, accurate GitHub Flavored Markdown parser and renderer
LICENSE=	modified-bsd

USE_TOOLS+=		pkg-config
CONFIGURE_ARGS+=	-fpkgconfig

.include "../../textproc/cmark-gfm/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
