# $NetBSD: Makefile,v 1.1.1.1 2009/03/05 23:43:08 roy Exp $
#

DISTNAME=		dhcpcd-dbus-0.3.0
CATEGORIES=		net
MASTER_SITES=		ftp://roy.marples.name/pub/dhcpcd/
MASTER_SITES+=		http://roy.aydogan.net/dhcpcd/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		roy@marples.name
HOMEPAGE=		http://roy.marples.name/projects/dhcpcd/
COMMENT=		DBus binding for dhcpcd

PKG_DESTDIR_SUPPORT=	user-destdir
USE_LANGUAGES=		c99

EGDIR=			${PREFIX}/share/examples/dhcpcd-dbus
INSTALL_MAKE_FLAGS+=	SYSCONFDIR=${EGDIR}

# Install the configuration file
CONF_FILES+=		${EGDIR}/dhcpcd-dbus.conf \
			${PKG_SYSCONFDIR}/dbus-1/system.d/dhcpcd-dbus.conf

DEPENDS+=		dhcpcd>=4.99.14:../../net/dhcpcd
DEPENDS+=		dbus>=1.1:../../sysutils/dbus

.include "../../sysutils/dbus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
