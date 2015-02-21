# $NetBSD: Makefile,v 1.1 2015/02/21 19:44:55 jmcneill Exp $

DISTNAME=	upower-0.99.2
CATEGORIES=	sysutils
MASTER_SITES=	http://upower.freedesktop.org/releases/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://upower.freedesktop.org
COMMENT=	Power management system message bus service
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config intltool

CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

PKG_SYSCONFSUBDIR=	UPower
INSTALL_MAKE_FLAGS+=	configdir=${EGDIR} dbusconfdir=${EGDIR}
EGDIR=			${PREFIX}/share/examples/upower
CONF_FILES+=		${EGDIR}/UPower.conf ${PKG_SYSCONFDIR}/UPower.conf
CONF_FILES+=		${EGDIR}/org.freedesktop.UPower.conf \
			${PKG_SYSCONFBASE}/dbus-1/system.d/org.freedesktop.UPower.conf

PKGCONFIG_OVERRIDE+=	upower-glib.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
