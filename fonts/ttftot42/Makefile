# $NetBSD: Makefile,v 1.8 2007/11/25 11:55:57 wiz Exp $
#

DISTNAME=	ttftot42-0.3.1
PKGREVISION=	2
CATEGORIES=	fonts print
MASTER_SITES=	http://www.nih.at/ttftot42/

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://www.nih.at/ttftot42/index.html
COMMENT=	TrueType font to Type 42 converter

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${BUILDLINK_DIR}/include/freetype

.include "../../graphics/freetype-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
