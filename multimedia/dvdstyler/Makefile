# $NetBSD: Makefile,v 1.21 2009/08/26 19:58:04 sno Exp $
#

DISTNAME=	DVDStyler-1.7.3
PKGREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dvdstyler/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.dvdstyler.de/
COMMENT=	Crossplatform DVD Authoring System

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	dvdauthor>=0.6.10:../../multimedia/dvdauthor
DEPENDS+=	dvd+rw-tools-[0-9]*:../../sysutils/dvd+rw-tools
DEPENDS+=	mpgtx-[0-9]*:../../graphics/mpgtx
BUILD_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto
BUILD_DEPENDS+=	zip-[0-9]*:../../archivers/zip

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config msgfmt
GNU_CONFIGURE=		yes

.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/netpbm/buildlink3.mk"
.include "../../graphics/wxsvg/buildlink3.mk"
.include "../../multimedia/ffmpeg/buildlink3.mk"
.include "../../multimedia/mjpegtools/buildlink3.mk"
.include "../../x11/wxGTK28/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
