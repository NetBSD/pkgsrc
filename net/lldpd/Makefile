# $NetBSD: Makefile,v 1.7 2014/02/12 23:18:23 tron Exp $

DISTNAME=		lldpd-0.7.6
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		http://media.luffy.cx/files/lldpd/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://vincentbernat.github.com/lldpd/
COMMENT=		802.1ab (LLDP) implementation
LICENSE=		isc
# `lldpcli` will be linked to GNU Readline (which is GPL licensed)
# if available. To avoid this, use `--without-readline` as a configure
# option.

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-privsep-chroot=${PKG_HOME._lldpd}
BUILD_DEFS+=		VARBASE

RCD_SCRIPTS=		lldpd
PKG_GROUPS=		_lldpd
PKG_USERS=		_lldpd:_lldpd
PKG_HOME._lldpd=	${VARBASE}/chroot/lldpd

OWN_DIRS=		${VARBASE}/chroot/lldpd
AUTO_MKDIRS=		yes

INSTALLATION_DIRS+=	sbin ${PKGMANDIR}/man5 ${PKGMANDIR}/man8

BUILDLINK_API_DEPENDS.libevent+=	libevent>=2.0.5
.include "../../devel/libevent/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
