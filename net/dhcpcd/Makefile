# $NetBSD: Makefile,v 1.50 2015/08/21 10:53:36 roy Exp $
#

DISTNAME=		dhcpcd-6.9.2
CATEGORIES=		net
MASTER_SITES=		ftp://roy.marples.name/pub/dhcpcd/
MASTER_SITES+=		http://roy.aydogan.net/dhcpcd/
MASTER_SITES+=		http://cflags.cc/roy/dhcpcd/
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		roy@NetBSD.org
HOMEPAGE=		http://roy.marples.name/projects/dhcpcd/
COMMENT=		DHCP / IPv4LL / IPv6RA / DHCPv6 client
LICENSE=		modified-bsd

USE_LANGUAGES=		c99
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-hooks=ntp

EGDIR=			${PREFIX}/share/examples
INSTALL_MAKE_FLAGS+=	SYSCONFDIR=${EGDIR}
CONF_FILES+=		${EGDIR}/dhcpcd.conf ${PKG_SYSCONFDIR}/dhcpcd.conf

RCD_SCRIPTS+=		dhcpcd

.include "../../mk/bsd.pkg.mk"
