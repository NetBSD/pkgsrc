# $NetBSD: Makefile,v 1.1.1.1 2002/04/02 11:51:25 uebayasi Exp $
# FreeBSD Id: ports/print/ttftot42/Makefile,v 1.2 2001/07/25 17:36:26 steve Exp

DISTNAME=	ttftot42-0.3.1
CATEGORIES=	print fonts
MASTER_SITES=	http://www.giga.or.at/pub/nih/ttftot42/

MAINTAINER=	rxg@ms25.url.com.tw
HOMEPAGE=	http://ftp.giga.or.at/pub/nih/ttftot42/
COMMENT=	TrueType font to Type 42 converter

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${BUILDLINK_DIR}/include/freetype

.include "../../graphics/freetype-lib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
