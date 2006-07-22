# $NetBSD: Makefile,v 1.12 2006/07/22 04:46:16 rillig Exp $

DISTNAME=	celestia-1.4.1
PKGREVISION=	1
CATEGORIES=	misc x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=celestia/}

MAINTAINER=	cesar_catrian@yahoo.com
HOMEPAGE=	http://www.shatters.net/celestia/
COMMENT=	Free real-time 3D space simulator

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

.if exists(${X11BASE}/include/X11/extensions/Xinerama.h)
CONFIGURE_ARGS+=	--with-xinerama
.endif

.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "none")
CONFIGURE_ARGS+=	--disable-threading
.endif

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/celestia.cfg ${EGDIR}/celestia.cfg.default

.include "options.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
