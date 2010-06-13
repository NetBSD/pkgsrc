# $NetBSD: Makefile,v 1.15 2010/06/13 22:44:46 wiz Exp $
#

DISTNAME=	wxsvg-1.0.4
PKGNAME=	wxsvg-1.0.4
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wxsvg/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wxsvg.sourceforge.net/
COMMENT=	C++ library to create, manipulate and render SVG files

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config autoconf automake

pre-configure:
	(cd ${WRKSRC} && ./autogen.sh)

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
.include "../../multimedia/ffmpeg/buildlink3.mk"
.include "../../x11/wxGTK28/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
