# $NetBSD: Makefile,v 1.16 2025/08/13 11:07:29 pho Exp $

DISTNAME=	cmark-gfm-0.2.6
PKGREVISION=	5
CATEGORIES=	textproc

MAINTAINER=	pho@cielonegro.org
COMMENT=	Fast, accurate GitHub Flavored Markdown parser and renderer
LICENSE=	modified-bsd

USE_TOOLS+=		pkg-config
CONFIGURE_ARGS+=	-fpkgconfig

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	bytestring \
	text

.include "../../textproc/cmark-gfm/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
