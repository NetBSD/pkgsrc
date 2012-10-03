# $NetBSD: Makefile,v 1.43.2.1 2012/10/03 12:08:52 spz Exp $
#

DISTNAME=	DVDStyler-2.1
PKGREVISION=	6
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dvdstyler/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.dvdstyler.de/
COMMENT=	Crossplatform DVD Authoring System
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

DEPENDS+=	dvdauthor>=0.6.10:../../multimedia/dvdauthor
DEPENDS+=	dvd+rw-tools-[0-9]*:../../sysutils/dvd+rw-tools
DEPENDS+=	mpgtx-[0-9]*:../../graphics/mpgtx
# uses mplex (optionally)
DEPENDS+=	mjpegtools-[0-9]*:../../multimedia/mjpegtools
BUILD_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config msgfmt zip
GNU_CONFIGURE=		yes
LDFLAGS+=		-ljpeg

post-install:
	cd ${WRKSRC}/templates && ${SETENV} ${INSTALL_ENV} ${GMAKE} install

.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/netpbm/buildlink3.mk"
.include "../../graphics/wxsvg/buildlink3.mk"
.include "../../multimedia/ffmpeg/buildlink3.mk"
# needs mediactrl
BUILDLINK_API_DEPENDS.wxGTK28+= wxGTK28>=2.8.10nb14
.include "../../x11/wxGTK28/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
