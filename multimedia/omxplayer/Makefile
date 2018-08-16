# $NetBSD: Makefile,v 1.19 2018/08/16 18:55:05 adam Exp $

DISTNAME=	omxplayer-20170112
PKGREVISION=	8
CATEGORIES=	multimedia
MASTER_SITES=   ${MASTER_SITE_GITHUB:=popcornmix/}
GITHUB_PROJECT= omxplayer
GITHUB_TAG=     12b472eaa75bce25dc63ec61d9233aadb996f3a4

MAINTAINER=	port-arm@NetBSD.org
HOMEPAGE=	https://github.com/popcornmix/omxplayer
COMMENT=	Raspberry Pi video player
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c++
USE_TOOLS+=	gmake bash:build
BUILD_TARGET=	omxplayer.bin
INSTALLATION_DIRS+= bin share/docs/omxplayer
REPLACE_BASH=	omxplayer

EXTRACT_USING=	bsdtar

ONLY_FOR_PLATFORM=	NetBSD-*-earm*hf

CFLAGS+=	-DPREFIX=\"${PREFIX}\"
CFLAGS+=	-Dfopen64=fopen -Dfseeko64=fseeko -Dftello64=ftello

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
.include "../../multimedia/ffmpeg3/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
