# $NetBSD: Makefile,v 1.3 2021/12/08 16:02:26 adam Exp $

PKGREVISION= 1
.include "../../net/avahi/Makefile.common"

PKGNAME=	${DISTNAME:S/avahi-/avahi-ui-/g}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Facilitate service discovery on a local network (GUI)

BUILD_DIRS+=	avahi-common avahi-client avahi-glib avahi-ui
INSTALL_DIRS+=	avahi-ui

CONFIGURE_ARGS+=	--enable-gtk3

INSTALLATION_DIRS+=	lib/pkgconfig

PKGCONFIG_OVERRIDE_STAGE=	pre-install
PKGCONFIG_OVERRIDE+=		avahi-ui-gtk3.pc

pre-install:
	cd ${WRKSRC} && ${MAKE_ENV} ${GMAKE} avahi-ui-gtk3.pc

post-install:
	${INSTALL_DATA} ${WRKSRC}/avahi-ui-gtk3.pc \
	    ${DESTDIR}${PREFIX}/lib/pkgconfig

.include "../../net/avahi/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
