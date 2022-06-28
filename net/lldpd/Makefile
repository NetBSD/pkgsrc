# $NetBSD: Makefile,v 1.41 2022/06/28 11:35:02 wiz Exp $

DISTNAME=		lldpd-1.0.13
PKGREVISION=		4
CATEGORIES=		net
MASTER_SITES=		http://media.luffy.cx/files/lldpd/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://vincentbernat.github.com/lldpd/
COMMENT=		802.1ab (LLDP) implementation
LICENSE=		isc

# interfaces-bsd.c:45:34: error: net/agr/if_agrioctl.h: No such file or directory
NOT_FOR_PLATFORM=	NetBSD-5.*-*

USE_TOOLS+=		pkg-config

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_LANGUAGES=		c

CONFIGURE_ARGS+=	--with-privsep-chroot=${LLDPD_HOME}
# Let pkgsrc handle security features.
CONFIGURE_ARGS+=	--disable-hardening
CONFIGURE_ARGS+=	--with-embedded-libevent=no
CONFIGURE_ARGS+=	--with-readline
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
# run/lldpd.socket is created under this directory
# (the default is ${PRERIX}/var, changed since 0.7.9)
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

BUILD_DEFS+=		VARBASE

EGDIR=			share/examples/${PKGBASE}
CONF_FILES=		${EGDIR}/lldpd.conf ${PKG_SYSCONFDIR}/lldpd.conf

RCD_SCRIPTS=		lldpd

LLDPD_USER?=		_lldpd
LLDPD_GROUP?=		_lldpd
LLDPD_HOME=		${VARBASE}/chroot/lldpd

PKG_GROUPS_VARS+=	LLDPD_GROUP
PKG_USERS_VARS+=	LLDPD_USER

PKG_GROUPS=		${LLDPD_GROUP}
PKG_USERS=		${LLDPD_USER}:${LLDPD_GROUP}
PKG_HOME.${LLDPD_USER}=	${LLDPD_HOME}

SUBST_CLASSES+=		files
SUBST_STAGE.files=	pre-configure
SUBST_FILES.files=	../lldpd.conf
SUBST_VARS.files=	PKG_SYSCONFDIR
SUBST_MESSAGE.files=	Fixing default configuration file.

INSTALLATION_DIRS+=	sbin include lib
INSTALLATION_DIRS+=	${PKGMANDIR}/man5 ${PKGMANDIR}/man8
INSTALLATION_DIRS+=	${EGDIR} share/doc
INSTALLATION_DIRS+=	share/bash-completion/completions
INSTALLATION_DIRS+=	share/zsh/site-functions

# Ownership and permission conflict with useradd?
#OWN_DIRS+=		${LLDPD_HOME}

TEST_TARGET=		check

.include "options.mk"

post-patch:
	${CP} ${PKGDIR}/files/lldpd.conf ${WRKDIR}

post-install:
	${RM} -r ${DESTDIR}${PKG_SYSCONFDIR}/lldpd.d
	${INSTALL_DATA} ${WRKDIR}/lldpd.conf \
		${DESTDIR}${PREFIX}/${EGDIR}/lldpd.conf


BUILDLINK_API_DEPENDS.libevent+=	libevent>=2.0.5
.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/editline/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
