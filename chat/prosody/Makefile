# $NetBSD: Makefile,v 1.37.2.1 2022/07/26 19:08:02 spz Exp $

DISTNAME=		prosody-0.12.0
PKGREVISION=		2
CATEGORIES=		chat
MASTER_SITES=		https://prosody.im/downloads/source/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://prosody.im/
COMMENT=		Flexible communications server for Jabber/XMPP written in Lua
LICENSE=		mit

DEPENDS+=		${LUA_PKGPREFIX}-expat>=1.2:../../textproc/lua-expat
DEPENDS+=		${LUA_PKGPREFIX}-filesystem>=1.6.2:../../devel/lua-filesystem
DEPENDS+=		${LUA_PKGPREFIX}-sec>=0.3.3:../../security/lua-sec
DEPENDS+=		${LUA_PKGPREFIX}-socket>=2.0:../../net/lua-socket
DEPENDS+=		${LUA_PKGPREFIX}-unbound-[0-9]*:../../net/lua-unbound

HAS_CONFIGURE=		yes
USE_LANGUAGES=		c
BUILD_DEFS+=		VARBASE

LUA_VERSIONS_ACCEPTED=	52 51

.include "../../mk/bsd.prefs.mk"

PROSODY_USER?=		prosody
PROSODY_GROUP?=		${PROSODY_USER}
PROSODY_DATA?=		${VARBASE}/db/prosody
PROSODY_LOG?=		${VARBASE}/log/prosody
PROSODY_RUN?=		${VARBASE}/run/prosody

OWN_DIRS_PERMS+=	${PROSODY_DATA} ${PROSODY_USER} ${PROSODY_GROUP} 0770
OWN_DIRS_PERMS+=	${PROSODY_LOG} ${PROSODY_USER} ${PROSODY_GROUP} 0770
OWN_DIRS_PERMS+=	${PROSODY_RUN} ${PROSODY_USER} ${PROSODY_GROUP} 0770
MAKE_DIRS+=		${PKG_SYSCONFDIR}/certs

PKG_USERS_VARS=			PROSODY_USER
PKG_GROUPS_VARS=		PROSODY_GROUP
PKG_GROUPS=			${PROSODY_GROUP}
PKG_USERS=			${PROSODY_USER}:${PROSODY_GROUP}
PKG_GECOS.${PROSODY_USER}=	Prosody daemon user
PKG_HOME.${PROSODY_USER}=	${PROSODY_DATA}
PKG_SHELL.${PROSODY_USER}=	${NOLOGIN}

PKG_SYSCONFSUBDIR=	${PKGBASE}
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
CONF_FILES+=		${EGDIR}/prosody.cfg.lua ${PKG_SYSCONFDIR}/prosody.cfg.lua
CONF_FILES+=		${EGDIR}/certs/localhost.cnf ${PKG_SYSCONFDIR}/certs/localhost.cnf

REPLACE_LUA+=		prosody prosodyctl

SUBST_CLASSES+=		path
SUBST_MESSAGE.path=	Fixing default paths
SUBST_STAGE.path=	pre-configure
SUBST_FILES.path=	makefile prosody.cfg.lua.dist
SUBST_SED.path=		-e 's,$$(CONFIG),$${DESTDIR}${EGDIR},g'
SUBST_VARS.path=	EGDIR PROSODY_DATA PROSODY_LOG PROSODY_RUN

CONFIGURE_ARGS+=	--cflags=${CFLAGS:Q}
CONFIGURE_ARGS+=	--datadir=${PROSODY_DATA}
CONFIGURE_ARGS+=	--ldflags="-L${PREFIX}/lib ${COMPILER_RPATH_FLAG}${PREFIX}/lib -shared"
CONFIGURE_ARGS+=	--no-example-certs
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-lua-include=${PREFIX}/${LUA_INCDIR}

CFLAGS+=		-fPIC -Wall -DLUA_COMPAT_MODULE
MAKE_ENV.SunOS+=	SOCKET_LIB=-lsocket
MAKE_FILE=		makefile

RCD_SCRIPTS=		prosody
FILES_SUBST+=		PROSODY_RUN=${PROSODY_RUN}
FILES_SUBST+=		PROSODY_USER=${PROSODY_USER}
FILES_SUBST+=		PROSODY_GROUP=${PROSODY_GROUP}

TEST_TARGET=		test

.include "../../lang/lua/application.mk"
.include "../../lang/lua/tool.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
