# $NetBSD: Makefile,v 1.108 2020/11/20 13:27:23 roy Exp $

DISTNAME=		dhcpcd-9.3.3
PKGNAME=		${DISTNAME:S/-rc/rc/}
CATEGORIES=		net
MASTER_SITES=		ftp://roy.marples.name/pub/dhcpcd/
MASTER_SITES+=		http://roy.aydogan.net/dhcpcd/
MASTER_SITES+=		http://cflags.cc/roy/dhcpcd/
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		roy@NetBSD.org
HOMEPAGE=		https://roy.marples.name/projects/dhcpcd/
COMMENT=		DHCP / IPv4LL / IPv6RA / DHCPv6 client
LICENSE=		modified-bsd

.include "../../mk/bsd.prefs.mk"

# Use the system _dhcpcd user introduced in NetBSD-9.99.53
# Don't use the _dhcp user in other BSDs as their home directory
# is /var/empty and that shouldn't be used as a chroot.
.if !empty(MACHINE_PLATFORM:MNetBSD-*) && \
    (empty(MACHINE_PLATFORM:MNetBSD-[0-9].*) || \
    !empty(MACHINE_PLATFORM:MNetBSD-9.99.5[3-9]-*) || \
    !empty(MACHINE_PLATFORM:MNetBSD-9.99.[6-9]*-*))
DHCPCD_USER?=		_dhcpcd
DHCPCD_GROUP?=		_dhcpcd
.endif

.if !defined(DHCPCD_USER)
DHCPCD_USER?=		dhcpcd
DHCPCD_GROUP?=		dhcpcd
DHCPCD_CHROOTDIR?=	${VARBASE}/dhcpcd

BUILD_DEFS+=            DHCPCD_CHROOTDIR VARBASE

PKG_USERS_VARS+=        DHCPCD_USER
PKG_GROUPS_VARS+=       DHCPCD_GROUP
PKG_GROUPS=             ${DHCPCD_GROUP}
PKG_USERS=              ${DHCPCD_USER}:${DHCPCD_GROUP}

MAKE_DIRS+=		${DHCPCD_CHROOTDIR}

PKG_GECOS.${DHCPCD_USER}=	dhcpcd user
PKG_HOME.${DHCPCD_USER}=	${DHCPCD_CHROOTDIR}
PKG_SHELL.${DHCPCD_USER}=	${NOLOGIN}
.endif

USE_LANGUAGES=		c99
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-hooks=ntp
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/examples
CONFIGURE_ARGS+=	--privsepuser=${DHCPCD_USER}

EGDIR=			${PREFIX}/share/examples/dhcpcd
INSTALL_MAKE_FLAGS+=	SYSCONFDIR=${EGDIR}
CONF_FILES+=		${EGDIR}/dhcpcd.conf ${PKG_SYSCONFDIR}/dhcpcd.conf

RCD_SCRIPTS+=		dhcpcd

.include "../../mk/bsd.pkg.mk"
