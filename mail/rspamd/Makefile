# $NetBSD: Makefile,v 1.135 2026/04/15 20:48:56 wiz Exp $
#
# When updating this, run 'make cfgfiles'.
# XXX: as of 4.0.1 this adds two extra entries (worker-hs_helper*)
# XXX: removed manually

DISTNAME=	rspamd-4.0.1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=rspamd/}

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	https://www.rspamd.com/
COMMENT=	Fast, free and open-source spam filtering system
LICENSE=	2-clause-bsd

DEPENDS+=	${LUA_PKGPREFIX}-lpeg-[0-9]*:../../devel/lua-lpeg
DEPENDS+=	ragel-[0-9]*:../../devel/ragel
TEST_DEPENDS+=	lua-cffi-[0-9]*:../../devel/lua-cffi

USE_TOOLS+=	perl pkg-config
USE_LANGUAGES=	c c++
BUILD_DEFS+=	VARBASE

USE_CC_FEATURES=	c99
USE_CXX_FEATURES+=	c++20

.include "../../mk/bsd.prefs.mk"

BUILDLINK_TRANSFORM.SunOS+=	rm:-liberty
CPPFLAGS.SunOS+=		-D__EXTENSIONS__

CMAKE_INSTALL_NAME_DIR=	${PREFIX}/lib/rspamd
LDFLAGS+=		${COMPILER_RPATH_FLAG}${PREFIX}/lib/rspamd
TEST_TARGET=		run-test

RSPAMD_USER?=	rspamd
RSPAMD_GROUP?=	rspamd
PKG_GROUPS=	${RSPAMD_GROUP}
PKG_USERS=	${RSPAMD_USER}:${RSPAMD_GROUP}

PKG_GROUPS_VARS=	RSPAMD_GROUP
PKG_USERS_VARS=		RSPAMD_USER

PKG_GECOS.${RSPAMD_USER}=	rspamd user

PKG_SYSCONFSUBDIR=	rspamd

EGDIR=		${PREFIX}/share/examples/${PKGBASE}
LOGDIR=		${VARBASE}/log/rspamd
DBDIR=		${VARBASE}/db/rspamd
RUNDIR=		${VARBASE}/run/rspamd

FILES_SUBST+=	RSPAMD_USER=${RSPAMD_USER}
FILES_SUBST+=	RSPAMD_GROUP=${RSPAMD_GROUP}

INSTALLATION_DIRS+=	share/examples

RCD_SCRIPTS=	rspamd
SMF_METHODS=	rspamd

CMAKE_CONFIGURE_ARGS+=	-DMANDIR:PATH=${PREFIX}/${PKGMANDIR}
CMAKE_CONFIGURE_ARGS+=	-DLOGDIR:PATH=${LOGDIR}
CMAKE_CONFIGURE_ARGS+=	-DRUNDIR:PATH=${VARBASE}/run/rspamd
CMAKE_CONFIGURE_ARGS+=	-DDBDIR:PATH=${DBDIR}
CMAKE_CONFIGURE_ARGS+=	-DCONFDIR:PATH=${PKG_SYSCONFDIR}
CMAKE_CONFIGURE_ARGS+=	-DEXAMPLESDIR:PATH=${EGDIR}
CMAKE_CONFIGURE_ARGS+=	-DRSPAMD_USER=${RSPAMD_USER}
CMAKE_CONFIGURE_ARGS+=	-DRSPAMD_GROUP=${RSPAMD_GROUP}
# Torch requires LuaJIT2, but LuaJIT2 only supports Lua 5.1
CMAKE_CONFIGURE_ARGS+=	-DENABLE_LUAJIT=OFF

# Assumes inotify == Linux
CMAKE_CONFIGURE_ARGS.SunOS+=	-DHAVE_INOTIFY_INIT=NO

REPLACE_PERL+=	utils/*.pl

MAKE_DIRS+=	${PKG_SYSCONFDIR}/local.d
MAKE_DIRS+=	${PKG_SYSCONFDIR}/lua.local.d
MAKE_DIRS+=	${PKG_SYSCONFDIR}/maps.d
MAKE_DIRS+=	${PKG_SYSCONFDIR}/modules.d
MAKE_DIRS+=	${PKG_SYSCONFDIR}/modules.local.d
MAKE_DIRS+=	${PKG_SYSCONFDIR}/override.d
MAKE_DIRS+=	${PKG_SYSCONFDIR}/scores.d

OWN_DIRS_PERMS+=	${DBDIR} ${RSPAMD_USER} ${RSPAMD_GROUP} 0700
OWN_DIRS_PERMS+=	${LOGDIR} ${RSPAMD_USER} ${RSPAMD_GROUP} 0750
OWN_DIRS_PERMS+=	${RUNDIR} ${RSPAMD_USER} ${RSPAMD_GROUP} 0755

.include "cfgfiles.mk"

.for file in ${CFGFILES}
CONF_FILES+=	${EGDIR}/${file} ${PKG_SYSCONFDIR}/${file}
.endfor

###
### Generate list of config files
###
.PHONY: cfgfiles
cfgfiles:
	${RUN} ${RECURSIVE_MAKE} extract
	@${ECHO} "# \$$NetBSD\$$" > ${.CURDIR}/cfgfiles.mk
	@${ECHO} "# Do not edit, regenerate using 'make cfgfiles'" >> ${.CURDIR}/cfgfiles.mk
	${RUN} cd ${WRKSRC}/conf && ${FIND} * -type f | ${SORT} \
	| ${TR} '\n' ' ' | ${SED} 's, $$,,' \
	| ${AWK} '{print("CFGFILES=\t" $$0)}' >> ${.CURDIR}/cfgfiles.mk
	@${ECHO} >> ${.CURDIR}/cfgfiles.mk

post-extract:
	${FIND} ${WRKSRC}/conf -type d -exec ${CHMOD} ${PKGDIRMODE} {} \;
	${FIND} ${WRKSRC}/conf -type f -exec ${CHMOD} ${DOCMODE} {} \;

post-install:
	${MV} ${DESTDIR}${PKG_SYSCONFDIR} ${DESTDIR}${PREFIX}/share/examples/rspamd

# as of 4.0.1
# 952 tests 946 passed 2244 assertions 2 failed 0 errors 4 unassertive 0 pending

TEST_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}/src:${WRKSRC}/${CMAKE_BUILD_DIR}/contrib/replxx:${WRKSRC}/${CMAKE_BUILD_DIR}/contrib/aho-corasick:${WRKSRC}/${CMAKE_BUILD_DIR}/contrib/libev:${WRKSRC}/${CMAKE_BUILD_DIR}/contrib/kann

.include "../../archivers/libarchive/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../databases/hiredis/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/fann/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../security/libsodium/buildlink3.mk"
.include "../../sysutils/file/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
