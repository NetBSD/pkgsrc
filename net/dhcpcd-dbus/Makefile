# $NetBSD: Makefile,v 1.5 2009/06/07 20:29:58 roy Exp $
#

DISTNAME=		dhcpcd-dbus-0.4.1
CATEGORIES=		net
MASTER_SITES=		ftp://roy.marples.name/pub/dhcpcd/
MASTER_SITES+=		http://roy.aydogan.net/dhcpcd/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		roy@NetBSD.org
HOMEPAGE=		http://roy.marples.name/projects/dhcpcd/
COMMENT=		DBus binding for dhcpcd
LICENSE=		modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir
USE_LANGUAGES=		c99
USE_TOOLS+=		pkg-config

EGDIR=			${PREFIX}/share/examples/dhcpcd-dbus
INSTALL_MAKE_FLAGS+=	SYSCONFDIR=${EGDIR}

# Install the configuration file
CONF_FILES+=		${EGDIR}/dhcpcd-dbus.conf \
			${PKG_SYSCONFDIR}/dbus-1/system.d/dhcpcd-dbus.conf

DEPENDS+=		dhcpcd>=5.0.0:../../net/dhcpcd
DEPENDS+=		dbus>=1.1:../../sysutils/dbus

.include "../../sysutils/dbus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
