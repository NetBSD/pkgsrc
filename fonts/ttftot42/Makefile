# $NetBSD: Makefile,v 1.3 2004/04/25 08:57:48 snj Exp $
#

DISTNAME=	ttftot42-0.3.1
CATEGORIES=	fonts print
MASTER_SITES=	http://www.giga.or.at/pub/nih/ttftot42/

MAINTAINER=	rxg@ms25.url.com.tw
HOMEPAGE=	http://ftp.giga.or.at/pub/nih/ttftot42/
COMMENT=	TrueType font to Type 42 converter

GNU_CONFIGURE=	yes
USE_BUILDLINK3=	yes
CPPFLAGS+=	-I${BUILDLINK_DIR}/include/freetype

.include "../../graphics/freetype-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
