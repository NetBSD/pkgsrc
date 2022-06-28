# $NetBSD: Makefile,v 1.26 2022/06/28 11:35:58 wiz Exp $

DISTNAME=	lxpanel-0.10.1
PKGREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lxde/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://lxde.org/
COMMENT=	Lightweight X11 desktop panel from LXDE
LICENSE=	gnu-gpl-v2

DEPENDS+=	lxmenu-data-[0-9]*:../../sysutils/lxmenu-data

LXDE_CONF=		share/examples/lxpanel
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		intltool msgfmt perl pkg-config
CONFIGURE_ARGS+=	--with-plugins="deskno, xkb, wnckpager"
PKGCONFIG_OVERRIDE+=	lxpanel.pc.in

PKG_SYSCONFSUBDIR=	xdg

MAKE_DIRS+=	${PKG_SYSCONFDIR}/lxpanel/default/panels 	\
		${PKG_SYSCONFDIR}/lxpanel/config		\
		${PKG_SYSCONFDIR}/lxpanel/two_panels/panels

CONF_FILES=	${LXDE_CONF}/default/config				\
		${PKG_SYSCONFDIR}/lxpanel/default/config 		\
		${LXDE_CONF}/default/panels/panel  			\
		${PKG_SYSCONFDIR}/lxpanel/default/panels/panel 		\
		${LXDE_CONF}/two_panels/config 				\
		${PKG_SYSCONFDIR}/lxpanel/two_panels/config 		\
		${LXDE_CONF}/two_panels/panels/bottom		 	\
		${PKG_SYSCONFDIR}/lxpanel/two_panels/panels/bottom 	\
		${LXDE_CONF}/two_panels/panels/top 			\
		${PKG_SYSCONFDIR}/lxpanel/two_panels/panels/top

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../sysutils/menu-cache/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2-xlib/buildlink3.mk"
.include "../../sysutils/libfm/buildlink3.mk"
.include "../../sysutils/libfm-extra/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/keybinder/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
