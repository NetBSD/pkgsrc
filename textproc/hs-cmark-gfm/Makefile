# $NetBSD: Makefile,v 1.10 2023/10/24 07:58:40 pho Exp $

DISTNAME=	cmark-gfm-0.2.6
CATEGORIES=	textproc

MAINTAINER=	pho@cielonegro.org
COMMENT=	Fast, accurate GitHub Flavored Markdown parser and renderer
LICENSE=	modified-bsd

USE_TOOLS+=		pkg-config
CONFIGURE_ARGS+=	-fpkgconfig

.include "../../textproc/cmark-gfm/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
