# $NetBSD: Makefile,v 1.12 2017/11/06 13:38:55 wiz Exp $

DISTNAME=	ttftot42-0.3.1
PKGREVISION=	3
CATEGORIES=	fonts print
MASTER_SITES=	https://www.nih.at/ttftot42/

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	https://www.nih.at/ttftot42/index.html
COMMENT=	TrueType font to Type 42 converter

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${BUILDLINK_DIR}/include/freetype

.include "../../graphics/freetype-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
