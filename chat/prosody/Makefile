# $NetBSD: Makefile,v 1.6 2012/10/03 00:02:43 asau Exp $
#

DISTNAME=		prosody-0.8.2
PKGREVISION=		1
CATEGORIES=		chat
MASTER_SITES=		http://prosody.im/downloads/source/

MAINTAINER=		filip@joyent.com
HOMEPAGE=		http://prosody.im/
COMMENT=		Flexible communications server for Jabber/XMPP written in Lua
LICENSE=		mit

DEPENDS+=		lua-filesystem>=1.0:../../devel/lua-filesystem
DEPENDS+=		lua-expat>=1.2:../../textproc/lua-expat
DEPENDS+=		lua-sec>=0.3.3:../../security/lua-sec
DEPENDS+=		lua-socket>=2.0:../../net/lua-socket

HAS_CONFIGURE=		yes
USE_TOOLS+=		gmake
BUILD_DEFS+=		VARBASE

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

PKG_USERS_VARS+=	PROSODY_USER
PKG_GROUPS_VARS+=	PROSODY_GROUP
PKG_GROUPS?=		${PROSODY_GROUP}
PKG_USERS?=		${PROSODY_USER}:${PROSODY_GROUP}
PKG_GECOS.${PROSODY_USER}=	Prosody daemon user
PKG_HOME.${PROSODY_USER}=	${PROSODY_DATA}
PKG_SHELL.${PROSODY_USER}=	${NOLOGIN}

PKG_SYSCONFSUBDIR=	${PKGBASE}
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
CONF_FILES+=		${EGDIR}/prosody.cfg.lua ${PKG_SYSCONFDIR}/prosody.cfg.lua
CONF_FILES+=		${EGDIR}/certs/localhost.cert ${PKG_SYSCONFDIR}/certs/localhost.cert
CONF_FILES+=		${EGDIR}/certs/localhost.key ${PKG_SYSCONFDIR}/certs/localhost.key

REPLACE_INTERPRETER+=	lua
REPLACE.lua.old=	/usr/bin/env lua
REPLACE.lua.new=	${PREFIX}/bin/lua
REPLACE_FILES.lua=	prosody prosodyctl

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--datadir=${PROSODY_DATA}
CONFIGURE_ARGS+=	--ldflags="${COMPILER_RPATH_FLAG}${PREFIX}/lib -shared"

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

.include "../../devel/libidn/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
