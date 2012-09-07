# $NetBSD: Makefile,v 1.38 2012/09/07 19:17:07 adam Exp $

DISTNAME=	celestia-1.4.1
PKGREVISION=	23
CATEGORIES=	misc x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=celestia/}

MAINTAINER=	cesar_catrian@yahoo.com
HOMEPAGE=	http://www.shatters.net/celestia/
COMMENT=	Free real-time 3D space simulator

PKG_DESTDIR_SUPPORT=	user-destdir

DISTINFO_FILE=	${.CURDIR}/../../misc/celestia/distinfo
PATCHDIR=	${.CURDIR}/../../misc/celestia/patches

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-lua

GCC_REQD+=		3.0
CXXFLAGS+=	-DPKG_SYSCONFDIR="\"${PKG_SYSCONFDIR}\""

EGDIR=		${PREFIX}/share/examples/celestia
CONF_FILES=	${EGDIR}/celestia.cfg.default ${PKG_SYSCONFDIR}/celestia.cfg

.include "../../mk/bsd.prefs.mk"

.if exists(${X11BASE}/include/X11/extensions/Xinerama.h) || ${X11_TYPE} != "native"
.include "../../x11/libXinerama/buildlink3.mk"
CONFIGURE_ARGS+=	--with-xinerama
.endif

.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "none")
CONFIGURE_ARGS+=	--disable-threading
.endif

INSTALLATION_DIRS=	${EGDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/celestia.cfg ${DESTDIR}${EGDIR}/celestia.cfg.default

.include "options.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
