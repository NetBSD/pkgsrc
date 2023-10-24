# $NetBSD: Makefile,v 1.4 2023/10/24 22:11:01 wiz Exp $

DISTNAME=	vaultwarden-${PKGVER}
PKGVER=		1.28.1
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=dani-garcia/}
EXTRACT_SUFX=	.tar.gz

DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	hauke@NetBSD.org
HOMEPAGE=	https://github.com/dani-garcia/vaultwarden
COMMENT=	Bitwarden compatible backend server

LICENSE=	gnu-agpl-v3

# From
# 'make CARGO_ARGS="build --release --features `make show-var VARNAME=CARGO_FEATURES`" build &&
#  make print-cargo-depends > cargo-depends.mk'
#
# Or generate from FreeBSD security/vaultwarden/Makefile.crates like
# awk '{ CA = ( NF > 2) ? $2 : $1 ; printf("CARGO_CRATE_DEPENDS+=\t%s\n", CA) }' < .../Makefile.crates > cargo-depends.mk

.include "cargo-depends.mk"

USE_TOOLS+=	perl

DEPENDS+=	daemonize>=1.7.8:../../sysutils/daemonize

MAKE_ENV+=	OPENSSL_DIR=${SSLBASE:Q}

.include "../../mk/bsd.prefs.mk"

.include "options.mk"

BUILD_DEFS+=		VARBASE

VAULTWARDEN_LOGDIR=	${VARBASE}/log/vaultwarden
VAULTWARDEN_DATADIR=	${VARBASE}/vaultwarden

EGDIR=			share/examples/vaultwarden

VAULTWARDEN_USER?=	vwarden
VAULTWARDEN_GROUP?=	vwarden

PKG_USERS_VARS+=	VAULTWARDEN_USER
PKG_GROUPS_VARS+=	VAULTWARDEN_GROUP
PKG_GROUPS=		${VAULTWARDEN_GROUP}
PKG_USERS=		${VAULTWARDEN_USER}:${VAULTWARDEN_GROUP}

PKG_GECOS.${VAULTWARDEN_USER}=	VAULTWARDEN password server
PKG_HOME.${VAULTWARDEN_USER}=	${VAULTWARDEN_DATADIR}
PKG_SHELL.${VAULTWARDEN_USER}=	${NOLOGIN}

RCD_SCRIPTS+=		vaultwarden
FILES_SUBST+=		VAULTWARDEN_USER=${VAULTWARDEN_USER:Q}
FILES_SUBST+=		VAULTWARDEN_GROUP=${VAULTWARDEN_GROUP:Q}
FILES_SUBST+=		VAULTWARDEN_DATADIR=${VAULTWARDEN_DATADIR:Q}
FILES_SUBST+=		VAULTWARDEN_LOGDIR=${VAULTWARDEN_LOGDIR:Q}

MESSAGE_SUBST+=		VAULTWARDEN_DATADIR=${VAULTWARDEN_DATADIR:Q}
MESSAGE_SUBST+=		VAULTWARDEN_LOGDIR=${VAULTWARDEN_LOGDIR:Q}

CONF_FILES+=		${EGDIR}/vaultwarden.env.sample \
				${PKG_SYSCONFDIR}/vaultwarden.env

INSTALLATION_DIRS=	sbin ${EGDIR}

OWN_DIRS_PERMS+=	${VAULTWARDEN_LOGDIR} ${VAULTWARDEN_USER} \
				${VAULTWARDEN_GROUP} 0750
OWN_DIRS+=		${VAULTWARDEN_DATADIR}
OWN_DIRS_PERMS+=	${VAULTWARDEN_DATADIR}/data ${VAULTWARDEN_USER} \
				${VAULTWARDEN_GROUP} 0700

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-install
SUBST_MESSAGE.paths=	Adjusting package paths.
SUBST_FILES.paths=	.env.template
SUBST_VARS.paths=	PREFIX PKG_SYSCONFDIR VAULTWARDEN_LOGDIR WEB_VAULT_DIR

do-install:
	${INSTALL_DATA} ${WRKSRC}/.env.template \
		 ${DESTDIR}${PREFIX}/${EGDIR}/vaultwarden.env.sample
	${INSTALL_DATA} ${FILESDIR}/httpd-vaultwarden.conf \
		 ${DESTDIR}${PREFIX}/${EGDIR}/httpd-vaultwarden.conf.sample
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/vaultwarden \
		 ${DESTDIR}${PREFIX}/sbin/vaultwarden

.include "../../devel/capnproto/buildlink3.mk"
.include "../../security/nettle/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../lang/rust/cargo.mk"

.include "../../mk/bsd.pkg.mk"
