# $NetBSD: Makefile,v 1.5 2009/04/28 21:04:38 roy Exp $
#

DISTNAME=		dhcpcd-5.0.0
CATEGORIES=		net
LICENSE=		modified-bsd
MASTER_SITES=		ftp://roy.marples.name/pub/dhcpcd/
MASTER_SITES+=		http://roy.aydogan.net/dhcpcd/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		roy@NetBSD.org
HOMEPAGE=		http://roy.marples.name/projects/dhcpcd/
COMMENT=		RFC2131 compliant DHCP client

PKG_DESTDIR_SUPPORT=	user-destdir
USE_LANGUAGES=		c99

EGDIR=			${PREFIX}/share/examples
MAKE_ENV+=		MANDIR=${PREFIX}/${PKGMANDIR}/man
MAKE_ENV+=		SYSCONFDIR=${PKG_SYSCONFDIR}
INSTALL_MAKE_FLAGS+=	SYSCONFDIR=${EGDIR}

# Install the configuration file
CONF_FILES+=		${EGDIR}/dhcpcd.conf ${PKG_SYSCONFDIR}/dhcpcd.conf

RCD_SCRIPTS+=		dhcpcd

# Install the ntp hook script by default
MAKE_ENV+=		HOOKSCRIPTS=50-ntp.conf

.include "../../mk/bsd.pkg.mk"
