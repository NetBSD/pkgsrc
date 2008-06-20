# $NetBSD: Makefile,v 1.9 2008/06/20 01:09:19 joerg Exp $
#

DISTNAME=	ttftot42-0.3.1
PKGREVISION=	2
CATEGORIES=	fonts print
MASTER_SITES=	http://www.nih.at/ttftot42/

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://www.nih.at/ttftot42/index.html
COMMENT=	TrueType font to Type 42 converter

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${BUILDLINK_DIR}/include/freetype

.include "../../graphics/freetype-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
