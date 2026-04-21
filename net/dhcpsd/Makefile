# $NetBSD: Makefile,v 1.4 2026/04/21 17:07:42 roy Exp $

DISTNAME=		dhcpsd-0.0.7
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GITHUB:=NetworkConfiguration/}
GITHUB_PROJECT=		dhcpsd
#GITHUB_TAG=		v${PKGVERSION_NOREV}
GITHUB_RELEASE=		v${PKGVERSION_NOREV}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		roy@NetBSD.org
HOMEPAGE=		https://roy.marples.name/projects/dhcpsd/
COMMENT=		DHCP server
LICENSE=		modified-bsd

.include "../../mk/bsd.prefs.mk"

.if !defined(DHCPSD_USER)
DHCPSD_USER?=		dhcpsd
DHCPSD_GROUP?=		dhcpsd
DHCPSD_CHROOTDIR?=	${VARBASE}/dhcpsd

BUILD_DEFS+=		DHCPSD_CHROOTDIR VARBASE

PKG_USERS_VARS+=	DHCPSD_USER
PKG_GROUPS_VARS+=	DHCPSD_GROUP
PKG_GROUPS=		${DHCPSD_GROUP}
PKG_USERS=		${DHCPSD_USER}:${DHCPSD_GROUP}

MAKE_DIRS+=		${DHCPSD_CHROOTDIR}

PKG_GECOS.${DHCPSD_USER}=	dhcpsd user
PKG_HOME.${DHCPSD_USER}=	${DHCPSD_CHROOTDIR}
PKG_SHELL.${DHCPSD_USER}=	${NOLOGIN}
.endif

USE_LANGUAGES=		c11
USE_TOOLS=		pkg-config
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--user=${DHCPSD_USER}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}

.if ${USE_CROSS_COMPILE:tl} == "yes"
CONFIGURE_ARGS+=	--host=${MACHINE_GNU_PLATFORM:Q}
CONFIGURE_ARGS+=	--build=${NATIVE_MACHINE_GNU_PLATFORM:Q}
.endif

#EGDIR=			${PREFIX}/share/examples/dhcpsd
#INSTALL_MAKE_FLAGS+=	SYSCONFDIR=${EGDIR}
#CONF_FILES+=		${EGDIR}/dhcpcd.conf ${PKG_SYSCONFDIR}/dhcpcd.conf

RCD_SCRIPTS+=		dhcpsd

.include "../../lang/lua/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
