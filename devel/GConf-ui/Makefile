# $NetBSD: Makefile,v 1.39 2018/03/12 11:15:26 wiz Exp $

PKGREVISION= 1
.include "../../devel/GConf/Makefile.common"

PKGNAME=	GConf-ui-${GCONF_VERSION}

BUILDLINK_API_DEPENDS.GConf+=	GConf>=${GCONF_VERSION}

CONFIGURE_ARGS+=	--enable-gtk
CONFIGURE_ARGS+=	--with-gtk=2.0
CONFIGURE_ARGS+=	--disable-defaults-service

BUILD_DIRS=	gconf
BUILD_TARGET=	gconfmarshal.h gconfmarshal.c GConfX.h gconf-sanity-check-2

INSTALLATION_DIRS=	libexec

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gconf/.libs/gconf-sanity-check-2 \
		${DESTDIR}${PREFIX}/libexec

.include "../../devel/GConf/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
