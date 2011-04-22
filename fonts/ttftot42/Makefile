# $NetBSD: Makefile,v 1.10 2011/04/22 13:43:32 obache Exp $
#

DISTNAME=	ttftot42-0.3.1
PKGREVISION=	3
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
