# $NetBSD: Makefile,v 1.1 2015/01/18 23:09:25 jmcneill Exp $

DISTNAME=	omxplayer-20150118
CATEGORIES=	multimedia
MASTER_SITES=	http://www.invisible.ca/packages/distfiles/
EXTRACT_SUFX=	.zip

MAINTAINER=	port-arm@NetBSD.org
HOMEPAGE=	https://github.com/popcornmix/omxplayer
COMMENT=	Raspberry Pi video player
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/omxplayer-master
USE_LANGUAGES=	c++
USE_TOOLS+=	gmake bash:build
BUILD_TARGET=	omxplayer.bin
INSTALLATION_DIRS+= bin share/docs/omxplayer
REPLACE_BASH=	omxplayer

ONLY_FOR_PLATFORM=	NetBSD-*-earm*hf

CFLAGS+=	-DPREFIX=\"${PREFIX}\"
CFLAGS+=	-Dfopen64=fopen -Dfseeko64=fseeko -Dftello64=ftello

# Remove this when raspberrypi-userland is updated with anaglyph support
CFLAGS+=	-DOLD_RASPBERRYPI_USERLAND

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/omxplayer.bin ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/omxplayer ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${PREFIX}/share/docs/omxplayer
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/docs/omxplayer/README

DEPENDS+=	freefont-ttf-[0-9]*:../../fonts/freefont-ttf
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../misc/raspberrypi-userland/buildlink3.mk"
.include "../../multimedia/ffmpeg2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
