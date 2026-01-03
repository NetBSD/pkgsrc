# $NetBSD: Makefile,v 1.135 2026/01/03 16:34:05 nia Exp $

DISTNAME=		xine-ui-0.99.14
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=xine/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.xine-project.org/home
COMMENT=		Skinned xlib-based xine GUI
LICENSE=		gnu-gpl-v2

USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		pkg-config gmake perl
USE_TOOLS+=		msgfmt msgmerge xgettext
USE_TOOLS+=		autoconf automake autoreconf autopoint
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-lirc
CONFIGURE_ARGS+=	--without-aalib

# libedit is not good enough, need rl_kill_full_line(3)
# PR lib/59883
CONFIGURE_ARGS+=	--with-readline=${BUILDLINK_PREFIX.readline}

pre-configure:
	cd ${WRKSRC} && autoreconf -vif

BUILDLINK_DEPMETHOD.libXt?=	build

LIBS.SunOS+=	-lsocket -lnsl

PTHREAD_AUTO_VARS=	yes

.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../multimedia/xine-lib/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
