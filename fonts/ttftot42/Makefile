# $NetBSD: Makefile,v 1.11 2012/10/03 18:28:31 asau Exp $
#

DISTNAME=	ttftot42-0.3.1
PKGREVISION=	3
CATEGORIES=	fonts print
MASTER_SITES=	http://www.nih.at/ttftot42/

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://www.nih.at/ttftot42/index.html
COMMENT=	TrueType font to Type 42 converter

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${BUILDLINK_DIR}/include/freetype

.include "../../graphics/freetype-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
