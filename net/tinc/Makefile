# $NetBSD: Makefile,v 1.34 2023/10/24 22:10:35 wiz Exp $

DISTNAME=	tinc-1.0.36
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	https://www.tinc-vpn.org/packages/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tinc-vpn.org/
COMMENT=	Virtual Private Network (VPN) daemon
LICENSE=	gnu-gpl-v2

BUILD_DEFS+=		VARBASE

INFO_FILES=		yes
USE_TOOLS+=		msgfmt
GNU_CONFIGURE=		yes

EGDIR=			${PREFIX}/share/examples/tinc
TINC_USER?=		tinc
TINC_GROUP?=		tinc

PKG_GROUPS_VARS+=	TINC_GROUP
PKG_USERS_VARS+=	TINC_USER

PKG_GROUPS=		${TINC_GROUP}
PKG_USERS=		${TINC_USER}:${TINC_GROUP}
PKG_SHELL.${TINC_USER}=	${SH}

OWN_DIRS+=		${VARBASE}/log/tinc
MAKE_DIRS+=		${PKG_SYSCONFDIR}/default

INSTALLATION_DIRS=	share/examples/tinc

PKG_SYSCONFSUBDIR=	tinc

CONF_FILES_PERMS+=	${EGDIR}/tinc.conf ${PKG_SYSCONFDIR}/default/tinc.conf \
			${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 644
CONF_FILES_PERMS+=	${EGDIR}/tinc-up ${PKG_SYSCONFDIR}/default/tinc-up \
			${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 755
CONF_FILES_PERMS+=	${EGDIR}/tinc-down ${PKG_SYSCONFDIR}/default/tinc-down \
			${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 755

SMF_METHODS=		tinc

post-install:
	${INSTALL_DATA} ${FILESDIR}/tinc.conf ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${FILESDIR}/tinc-up ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${FILESDIR}/tinc-down ${DESTDIR}${EGDIR}

.include "../../archivers/lzo/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
