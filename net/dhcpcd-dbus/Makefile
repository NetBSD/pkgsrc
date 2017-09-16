# $NetBSD: Makefile,v 1.12 2017/09/16 08:37:35 wiz Exp $

DISTNAME=		dhcpcd-dbus-0.6.0
CATEGORIES=		net
MASTER_SITES=		ftp://roy.marples.name/pub/dhcpcd/
MASTER_SITES+=		http://roy.aydogan.net/dhcpcd/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		roy@NetBSD.org
HOMEPAGE=		https://roy.marples.name/projects/dhcpcd/
COMMENT=		DBus binding for dhcpcd
LICENSE=		modified-bsd

USE_LANGUAGES=		c99
USE_TOOLS+=		pkg-config
HAS_CONFIGURE=		yes

EGDIR=			${PREFIX}/share/examples/dhcpcd-dbus
INSTALL_MAKE_FLAGS+=	CONFDIR=${EGDIR}

# Install the configuration file
CONF_FILES+=		${EGDIR}/dhcpcd-dbus.conf \
			${PKG_SYSCONFDIR}/dbus-1/system.d/dhcpcd-dbus.conf

DEPENDS+=		dhcpcd>=5.0.0:../../net/dhcpcd
DEPENDS+=		dbus>=1.1:../../sysutils/dbus

.include "../../sysutils/dbus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
