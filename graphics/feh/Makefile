# $NetBSD: Makefile,v 1.133 2024/05/16 06:15:01 wiz Exp $

DISTNAME=	feh-3.10.2
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	https://feh.finalrewind.org/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://feh.finalrewind.org/
COMMENT=	Imlib2 based image viewer
LICENSE=	mit

USE_LANGUAGES=	c99

USE_TOOLS+=	gmake

CFLAGS+=	-DHAVE_STRING_H=1

# for alphasort(3)
CFLAGS.NetBSD+=		-D_NETBSD_SOURCE
CFLAGS.SunOS+=		-D__EXTENSIONS__

# for undefined reference error from strverscmp(3)
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "Linux"
BUILD_MAKE_FLAGS+=	verscmp=0
.endif

LDFLAGS.SunOS+=		-lnsl -lsocket

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
