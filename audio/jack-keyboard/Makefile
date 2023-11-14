# $NetBSD: Makefile,v 1.11 2023/11/14 14:01:23 wiz Exp $

DISTNAME=	jack-keyboard-2.7.2
PKGREVISION=	9
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=jack-keyboard/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jack-keyboard.sourceforge.net/
COMMENT=	Virtual MIDI keyboard for JACK applications
LICENSE=	2-clause-bsd

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DLashEnable=OFF

.include "../../devel/cmake/build.mk"
.include "../../audio/jack/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
