# $NetBSD: Makefile,v 1.95 2019/07/01 04:08:20 ryoon Exp $

DISTNAME=	feh-3.1.3
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	https://feh.finalrewind.org/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://feh.finalrewind.org/
COMMENT=	Imlib2 based image viewer
LICENSE=	mit

USE_LANGUAGES=	c99

USE_TOOLS+=	gmake

# for alphasort(3)
CFLAGS.NetBSD+=		-D_NETBSD_SOURCE
# for undefined reference error from strverscmp(3)
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD"
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
