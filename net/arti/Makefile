# $NetBSD: Makefile,v 1.7 2024/06/07 23:52:41 nikita Exp $

PKGNAME=	arti-1.1.3
PKGREVISION=	1
DISTNAME=	arti-arti-v${PKGVERSION_NOREV}
CATEGORIES=	net
# TODO: modify gitlab fetch to allow hosted gitlab instances
MASTER_SITES=	https://gitlab.torproject.org/tpo/core/arti/-/archive/arti-v${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.torproject.org/tpo/core/arti/
COMMENT=	Implementation of tor in Rust
LICENSE=	mit

.include "cargo-depends.mk"

USE_LANGUAGES=		c c++

.include "../../mk/bsd.prefs.mk"
ARTI_USER?=		arti
ARTI_GROUP?=		arti
PKG_HOME.${ARTI_USER}=	${VARBASE}/chroot/arti
BUILD_DEFS+=		VARBASE
PKG_SYSCONFSUBDIR=	arti

PKG_GROUP_VARS+=	ARTI_GROUP
PKG_USER_VARS=		ARTI_USER

RCD_SCRIPTS=		arti
RCD_SCRIPT_SRC.arti=	${FILESDIR}/arti.in
PKG_GROUPS=		${ARTI_GROUP}
PKG_USERS=		${ARTI_USER}:${ARTI_GROUP}
USER_GROUP=		${ARTI_USER} ${ARTI_GROUP}

OWN_DIRS_PERMS+=	${PKG_HOME.${ARTI_USER}} ${USER_GROUP} 0700

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
CONF_FILES+=		${EGDIR}/arti.toml ${PKG_SYSCONFDIR}/arti.toml
FILES_SUBST+=		PKG_HOME=${PKG_HOME.${ARTI_USER}}
FILES_SUBST+=		ARTI_USER=${ARTI_USER}
FILES_SUBST+=		ARTI_GROUP=${ARTI_GROUP}
MAKE_DIRS+=		${VARBASE}/chroot/arti
AUTO_MKDIRS=		yes

MAKE_ENV+=		OPENSSL_DIR=${BUILDLINK_PREFIX.openssl}

INSTALLATION_DIRS=	${EGDIR}

.if ${INIT_SYSTEM} == "rc.d"
DEPENDS+=		daemonize-[0-9]*:../../sysutils/daemonize
.endif

# error: found a virtual manifest at `/usr/work/net/arti/work/arti-arti-v1.1.3/Cargo.toml` instead of a package manifest
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/${PKGBASE} ${DESTDIR}${PREFIX}/bin

pre-install:
	${INSTALL_DATA} ${WRKSRC}/crates/arti/src/arti-example-config.toml ${DESTDIR}${EGDIR}/arti.toml

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
