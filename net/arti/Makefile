# $NetBSD: Makefile,v 1.10 2025/02/07 19:51:11 wiz Exp $

DISTNAME=	arti-arti-v1.4.0
PKGNAME=	${DISTNAME:S/arti-v//}
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

SUBST_CLASSES+=		var
SUBST_FILES.var+=	crates/arti/src/arti-example-config.toml
SUBST_SED.var+=		-e 's,$${ARTI_CACHE}'",${VARBASE}/chroot/arti/,"
SUBST_SED.var+=		-e 's,$${ARTI_LOCAL_DATA}'",${VARBASE}/chroot/arti/,"
SUBST_STAGE.var=	post-patch
SUBST_MESSAGE.var=	Adapt some paths for pkgsrc.

MAKE_ENV+=		OPENSSL_DIR=${BUILDLINK_PREFIX.openssl}

INSTALLATION_DIRS=	${EGDIR}

.if ${INIT_SYSTEM} == "rc.d"
DEPENDS+=		daemonize-[0-9]*:../../sysutils/daemonize
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/arti ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/crates/arti/src/arti-example-config.toml ${DESTDIR}${EGDIR}/arti.toml

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
