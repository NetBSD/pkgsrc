# $NetBSD: Makefile,v 1.24 2016/02/25 11:28:58 jperkin Exp $
#

DISTNAME=		prosody-0.9.10
CATEGORIES=		chat
MASTER_SITES=		http://prosody.im/downloads/source/

MAINTAINER=		filip@joyent.com
HOMEPAGE=		http://prosody.im/
COMMENT=		Flexible communications server for Jabber/XMPP written in Lua
LICENSE=		mit

DEPENDS+=		${LUA_PKGPREFIX}-expat>=1.2:../../textproc/lua-expat
DEPENDS+=		${LUA_PKGPREFIX}-filesystem>=1.0:../../devel/lua-filesystem
DEPENDS+=		${LUA_PKGPREFIX}-sec>=0.3.3:../../security/lua-sec
DEPENDS+=		${LUA_PKGPREFIX}-socket>=2.0:../../net/lua-socket

HAS_CONFIGURE=		yes
USE_TOOLS+=		gmake
BUILD_DEFS+=		VARBASE

LUA_VERSIONS_ACCEPTED=	51

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

PKG_USERS_VARS=		PROSODY_USER
PKG_GROUPS_VARS=	PROSODY_GROUP
PKG_GROUPS=		${PROSODY_GROUP}
PKG_USERS=		${PROSODY_USER}:${PROSODY_GROUP}
PKG_GECOS.${PROSODY_USER}=	Prosody daemon user
PKG_HOME.${PROSODY_USER}=	${PROSODY_DATA}
PKG_SHELL.${PROSODY_USER}=	${NOLOGIN}

PKG_SYSCONFSUBDIR=	${PKGBASE}
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
CONF_FILES+=		${EGDIR}/prosody.cfg.lua ${PKG_SYSCONFDIR}/prosody.cfg.lua
CONF_FILES+=		${EGDIR}/certs/example.com.cnf ${PKG_SYSCONFDIR}/certs/example.com.cnf
CONF_FILES+=		${EGDIR}/certs/example.com.key ${PKG_SYSCONFDIR}/certs/example.com.key
CONF_FILES+=		${EGDIR}/certs/localhost.cnf ${PKG_SYSCONFDIR}/certs/localhost.cnf
CONF_FILES+=		${EGDIR}/certs/localhost.key ${PKG_SYSCONFDIR}/certs/localhost.key

REPLACE_LUA+=		prosody prosodyctl

SUBST_CLASSES+=		path
SUBST_MESSAGE.path=	Fixing default paths
SUBST_STAGE.path=	pre-configure
SUBST_FILES.path=	Makefile man/prosodyctl.man prosody.cfg.lua.dist
SUBST_SED.path=		-e 's,/etc/prosody,${PKG_SYSCONFDIR},g'
SUBST_VARS.path=	EGDIR PROSODY_DATA PROSODY_LOG PROSODY_RUN

CONFIGURE_ARGS+=	--cflags=${CFLAGS:Q}
CONFIGURE_ARGS+=	--datadir=${PROSODY_DATA}
CONFIGURE_ARGS+=	--ldflags="-L${PREFIX}/lib ${COMPILER_RPATH_FLAG}${PREFIX}/lib -shared"
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-lua-include=${PREFIX}/${LUA_INCDIR}

CFLAGS+=		-fPIC -Wall -DLUA_COMPAT_MODULE
MAKE_ENV.SunOS+=	SOCKET_LIB=-lsocket

RCD_SCRIPTS=		prosody

.include "../../lang/lua/application.mk"
.include "../../lang/lua/tool.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
