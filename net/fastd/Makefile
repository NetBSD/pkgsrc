# $NetBSD: Makefile,v 1.4 2023/10/24 22:10:15 wiz Exp $

DISTNAME=	fastd-22
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=NeoRaider/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/NeoRaider/fastd
COMMENT=	Fast and small VPN tunnelling daemon
LICENSE=	modified-bsd

USE_TOOLS+=	bison pkg-config

MESON_ARGS+=	-Dsystemd=disabled

# breaks compatibility with older and embedded x86
MESON_ARGS+=	-Dmac_ghash_pclmulqdq=disabled
MESON_ARGS+=	-Dcipher_salsa20_xmm=disabled
MESON_ARGS+=	-Dcipher_salsa2012_xmm=disabled

MESON_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

RCD_SCRIPTS=	fastd

PYTHON_FOR_BUILD_ONLY=	tool

EGDIR=			share/examples/fastd

INSTALLATION_DIRS+=	${PKGMANDIR}/man1
INSTALLATION_DIRS+=	${EGDIR}

BUILD_DEFS+=		VARBASE

.include "../../mk/bsd.prefs.mk"

PKG_SYSCONFSUBDIR=	fastd

CONF_FILES+=		${PREFIX}/${EGDIR}/fastd.conf \
			${PKG_SYSCONFDIR}/fastd.conf

FASTD_USER?=		fastd
FASTD_GROUP?=		fastd
PKG_GROUPS=		${FASTD_GROUP}
PKG_USERS=		${FASTD_USER}:${FASTD_GROUP}
PKG_GROUPS_VARS=	FASTD_USER
PKG_USERS_VARS=		FASTD_GROUP

OWN_DIRS+=		${PKG_SYSCONFDIR}/peers
OWN_DIRS_PERMS+=	${VARBASE}/run/fastd \
			${FASTD_USER} ${FASTD_GROUP} 0755

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Fixing absolute paths.
SUBST_FILES.paths=	fastd.conf
SUBST_VARS.paths=	PREFIX VARBASE PKG_SYSCONFDIR
SUBST_VARS.paths+=	FASTD_USER FASTD_GROUP

FILES_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR:Q}

post-extract:
	${CP} ${FILESDIR}/fastd.conf ${WRKSRC}/fastd.conf

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/fastd.1 \
	    ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/fastd.1
	${INSTALL_MAN} ${WRKSRC}/fastd.conf \
	    ${DESTDIR}${PREFIX}/${EGDIR}/fastd.conf

.include "../../devel/meson/build.mk"
.include "../../security/libsodium/buildlink3.mk"
.include "../../security/libuecc/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/json-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
