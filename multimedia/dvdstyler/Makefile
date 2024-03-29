# $NetBSD: Makefile,v 1.92 2024/01/22 13:17:00 ryoon Exp $

DISTNAME=	DVDStyler-3.1
PKGREVISION=	13
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dvdstyler/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.dvdstyler.org/
COMMENT=	Crossplatform DVD Authoring System
LICENSE=	gnu-gpl-v2

DEPENDS+=	netpbm-[0-9]*:../../graphics/netpbm

MAKE_JOBS_SAFE=		no

DEPENDS+=	dvdauthor>=0.6.10:../../multimedia/dvdauthor
DEPENDS+=	dvd+rw-tools-[0-9]*:../../sysutils/dvd+rw-tools
DEPENDS+=	mpgtx-[0-9]*:../../graphics/mpgtx
# uses mplex (optionally)
DEPENDS+=	mjpegtools-[0-9]*:../../multimedia/mjpegtools
TOOL_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake lex pkg-config msgfmt zip
GNU_CONFIGURE=		yes
LDFLAGS+=		-ljpeg
CONFIGURE_ARGS+=	FFMPEG_PATH=${BUILDLINK_PREFIX.ffmpeg4}/bin/ffmpeg4

post-install:
	cd ${WRKSRC}/templates && ${SETENV} ${INSTALL_ENV} ${GMAKE} install

#.include "../../graphics/libexif/buildlink3.mk"
BUILDLINK_API_DEPENDS.wxsvg+= wxsvg>=1.5.20
.include "../../graphics/wxsvg/buildlink3.mk"
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
