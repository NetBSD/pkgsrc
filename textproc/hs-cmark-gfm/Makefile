# $NetBSD: Makefile,v 1.11 2023/11/02 06:37:29 pho Exp $

DISTNAME=	cmark-gfm-0.2.6
PKGREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	pho@cielonegro.org
COMMENT=	Fast, accurate GitHub Flavored Markdown parser and renderer
LICENSE=	modified-bsd

USE_TOOLS+=		pkg-config
CONFIGURE_ARGS+=	-fpkgconfig

.include "../../textproc/cmark-gfm/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
