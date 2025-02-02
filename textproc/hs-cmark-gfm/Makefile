# $NetBSD: Makefile,v 1.14 2025/02/02 13:05:51 pho Exp $

DISTNAME=	cmark-gfm-0.2.6
PKGREVISION=	3
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
