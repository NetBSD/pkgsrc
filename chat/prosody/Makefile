# $NetBSD: Makefile,v 1.15 2014/05/03 13:01:24 alnsn Exp $
#

DISTNAME=		prosody-0.9.4
PKGREVISION=		1
CATEGORIES=		chat
MASTER_SITES=		http://prosody.im/downloads/source/

MAINTAINER=		filip@joyent.com
HOMEPAGE=		http://prosody.im/
COMMENT=		Flexible communications server for Jabber/XMPP written in Lua
LICENSE=		mit

DEPENDS+=	${LUA_PKGPREFIX}-filesystem>=1.0:../../devel/lua-filesystem
DEPENDS+=	${LUA_PKGPREFIX}-expat>=1.2:../../textproc/lua-expat
DEPENDS+=	${LUA_PKGPREFIX}-sec>=0.3.3:../../security/lua-sec
DEPENDS+=	${LUA_PKGPREFIX}-socket>=2.0:../../net/lua-socket

HAS_CONFIGURE=		yes
USE_TOOLS+=		gmake
BUILD_DEFS+=		VARBASE

CONFIGURE_ARGS+=	--with-lua-include=${PREFIX}/${LUA_INCDIR}

RCD_SCRIPTS=		prosody

.include "../../mk/bsd.prefs.mk"

PROSODY_USER?=		prosody
PROSODY_GROUP?=		${PROSODY_USER}
PROSODY_DATA?=		${VARBASE}/db/prosody
PROSODY_LOG?=		${VARBASE}/log/prosody
PROSODY_RUN?=		${VARBASE}/run/prosody

OWN_DIRS+=		${PROSODY_DATA} ${PROSODY_LOG} ${PROSODY_RUN}
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
CONF_FILES+=		${EGDIR}/certs/example.com.crt ${PKG_SYSCONFDIR}/certs/example.com.crt
CONF_FILES+=		${EGDIR}/certs/example.com.key ${PKG_SYSCONFDIR}/certs/example.com.key
CONF_FILES+=		${EGDIR}/certs/localhost.cnf ${PKG_SYSCONFDIR}/certs/localhost.cnf
CONF_FILES+=		${EGDIR}/certs/localhost.crt ${PKG_SYSCONFDIR}/certs/localhost.crt
CONF_FILES+=		${EGDIR}/certs/localhost.key ${PKG_SYSCONFDIR}/certs/localhost.key

CFLAGS+=		-fPIC -Wall -DLUA_COMPAT_MODULE

REPLACE_LUA+=		prosody prosodyctl

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--datadir=${PROSODY_DATA}
CONFIGURE_ARGS+=	--ldflags="${COMPILER_RPATH_FLAG}${PREFIX}/lib -shared"
CONFIGURE_ARGS+=	--cflags=${CFLAGS:Q}

SUBST_CLASSES+=		eg
SUBST_MESSAGE.eg=	Fixing examples/configuration directories
SUBST_STAGE.eg=		post-patch
SUBST_FILES.eg=		Makefile man/prosodyctl.man
SUBST_SED.eg=		-e 's,@EGDIR@,${EGDIR},g'
SUBST_SED.eg+=		-e 's,/etc/prosody,${PKG_SYSCONFDIR},g'

SUBST_CLASSES+=		config
SUBST_MESSAGE.config=	Configure POSIX functionality
SUBST_STAGE.config=	pre-configure
SUBST_FILES.config=	prosody.cfg.lua.dist
SUBST_SED.config=	-e 's,@PROSODY_DATA@,${PROSODY_DATA},'
SUBST_SED.config+=	-e 's,@PROSODY_LOG@,${PROSODY_LOG},'
SUBST_SED.config+=	-e 's,@PROSODY_RUN@,${PROSODY_RUN},'

.include "../../lang/lua/application.mk"

.include "../../devel/libidn/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
