# $NetBSD: Makefile,v 1.70 2022/01/10 01:46:27 ryoon Exp $

DISTNAME=	mongodb-src-r4.2.15
PKGNAME=	${DISTNAME:S/src-r//}
PKGREVISION=	3
CATEGORIES=	databases
MASTER_SITES=	http://fastdl.mongodb.org/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.mongodb.com/
COMMENT=	NoSQL distributed document-oriented database
LICENSE=	server-side-public-license # Client and tools licensed under apache-2.0

# MongoDB 3.4 onwards explicitly does not support 32-bit x86 platforms
NOT_FOR_PLATFORM+=	*-*-i386

EXTRACT_USING=	bsdtar

BUILD_DEPENDS+=	${PYPKGPREFIX}-cheetah-[0-9]*:../../devel/py-cheetah3
BUILD_DEPENDS+=	${PYPKGPREFIX}-psutil-[0-9]*:../../sysutils/py-psutil
BUILD_DEPENDS+=	${PYPKGPREFIX}-regex-[0-9]*:../../textproc/py-regex
BUILD_DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

# https://github.com/mongodb/mongo/blob/master/docs/building.md
USE_LANGUAGES=	c99 c++17
# Note that USE_LANGUAGES should contain c11, per SConstruct, but
# pkgsrc does not yet support that.
GCC_REQD+=	8

USE_TOOLS+=	pkg-config

SCONS_ARGS=	${_MAKE_JOBS}
SCONS_ARGS+=	--dbg=off # on: argument parsing problem
SCONS_ARGS+=	--disable-warnings-as-errors
SCONS_ARGS+=	--release
SCONS_ARGS+=	--runtime-hardening=off # on: does not produce executables
#SCONS_ARGS+=	--use-system-asio
SCONS_ARGS+=	--use-system-boost
SCONS_ARGS+=	--use-system-icu
SCONS_ARGS+=	--use-system-mongo-c
SCONS_ARGS+=	--use-system-pcre
SCONS_ARGS+=	--use-system-snappy
SCONS_ARGS+=	--use-system-sqlite
SCONS_ARGS+=	--use-system-tcmalloc
#SCONS_ARGS+=	--use-system-wiredtiger
SCONS_ARGS+=	--use-system-yaml
SCONS_ARGS+=	--use-system-zlib
SCONS_ARGS+=	--use-system-zstd

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../mk/bsd.prefs.mk"

CPPFLAGS+=	-fno-jump-tables  # XXX: still needed?
INCL_PATH+=	${BUILDLINK_PREFIX.mongo-c-driver}/include/libbson-1.0
INCL_PATH+=	${BUILDLINK_PREFIX.mongo-c-driver}/include/libmongoc-1.0
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib -L${PREFIX}/lib

.include "options.mk"

SMF_METHODS+=		mongodb

BUILD_DEFS+=		VARBASE
BUILD_DEFS+=		MONGODB_USER MONGODB_GROUP MONGODB_DBPATH
BUILD_DEFS+=		MONGODB_LOGPATH

MONGODB_USER?=		mongodb
MONGODB_GROUP?=		mongodb
MONGODB_DBPATH?=	${VARBASE}/mongodb
MONGODB_CONFIGDBPATH?=	${VARBASE}/mongoconfigdb
MONGODB_LOGPATH?=	${VARBASE}/log/mongodb

PKG_USERS_VARS+=	MONGODB_USER
PKG_GROUPS_VARS+=	MONGODB_GROUP

PKG_GROUPS=		${MONGODB_GROUP}
PKG_USERS=		${MONGODB_USER}:${MONGODB_GROUP}

PKG_GECOS.${MONGODB_USER}=	MongoDB database administrator
PKG_HOME.${MONGODB_USER}=	${MONGODB_DBPATH}
PKG_SHELL.${MONGODB_USER}=	${SH}

OWN_DIRS_PERMS+=	${MONGODB_DBPATH:Q} ${MONGODB_USER} ${MONGODB_GROUP} 0755
OWN_DIRS_PERMS+=	${MONGODB_DBPATH:Q}/journal ${MONGODB_USER} ${MONGODB_GROUP} 0755
OWN_DIRS_PERMS+=	${MONGODB_LOGPATH:Q} ${MONGODB_USER} ${MONGODB_GROUP} 0755

FILES_SUBST+=		MONGODB_USER=${MONGODB_USER}
FILES_SUBST+=		MONGODB_GROUP=${MONGODB_GROUP}
FILES_SUBST+=		MONGODB_DBPATH=${MONGODB_DBPATH}
FILES_SUBST+=		MONGODB_LOGPATH=${MONGODB_LOGPATH}

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-build
SUBST_MESSAGE.path=	Replacing database paths.
SUBST_FILES.path=	debian/mongo.1 debian/mongod.1
SUBST_FILES.path+=	src/mongo/db/storage/storage_options.cpp
SUBST_SED.path=		-e 's,/data/db,${MONGODB_DBPATH},g'
SUBST_SED.path+=	-e 's,/data/configdb,${MONGODB_CONFIGDBPATH},g'
SUBST_SED.path+=	-e 's,/etc,${PKG_SYSCONFDIR},g'

SUBST_CLASSES+=		varbase
SUBST_STAGE.varbase=	pre-build
SUBST_MESSAGE.varbase=	Changing /var to ${VARBASE}.
SUBST_FILES.varbase=	debian/mongod.conf
SUBST_SED.varbase=	-e 's,/var/lib/mongodb,${VARBASE}/mongodb,g'
SUBST_SED.varbase+=	-e 's,/var/log/mongodb,${VARBASE}/mongodb,g'

REPLACE_PYTHON+=	src/mongo/installer/compass/install_compass

NOT_PAX_MPROTECT_SAFE+=	bin/mongo bin/mongod

RCD_SCRIPTS=		mongodb

INSTALLATION_DIRS+=	share/doc/mongodb share/examples/mongodb ${PKGMANDIR}/man1

CONF_FILES+=		share/examples/mongodb/mongod.conf \
			${PKG_SYSCONFDIR}/mongod.conf

CHECK_PORTABILITY_SKIP=	src/mongo/gotools/src/github.com/mongodb/mongo-tools/vendor/go.mongodb.org/mongo-driver/etc/add-license.sh

# Copy system specific files for NetBSD and DragonFly
post-extract:
	${CHMOD} -R g-w ${WRKSRC}
	${CP} -R ${WRKSRC}/src/third_party/mozjs-60/platform/x86_64/freebsd \
		${WRKSRC}/src/third_party/mozjs-60/platform/x86_64/dragonfly
	${CP} -R ${WRKSRC}/src/third_party/mozjs-60/platform/x86_64/freebsd \
		${WRKSRC}/src/third_party/mozjs-60/platform/x86_64/netbsd
	${CP} ${WRKSRC}/src/mongo/db/ftdc/ftdc_system_stats_openbsd.cpp \
		${WRKSRC}/src/mongo/db/ftdc/ftdc_system_stats_netbsd.cpp
	${CP} ${WRKSRC}/src/mongo/db/ftdc/ftdc_system_stats_freebsd.cpp \
		${WRKSRC}/src/mongo/db/ftdc/ftdc_system_stats_dragonfly.cpp
	${CP} ${WRKSRC}/src/mongo/util/processinfo_openbsd.cpp \
		${WRKSRC}/src/mongo/util/processinfo_netbsd.cpp
	${CP} ${WRKSRC}/src/mongo/util/processinfo_freebsd.cpp \
		${WRKSRC}/src/mongo/util/processinfo_dragonfly.cpp
	${CP} ${WRKSRC}/src/mongo/platform/stack_locator_freebsd.cpp \
		${WRKSRC}/src/mongo/platform/stack_locator_netbsd.cpp
	${CP} ${WRKSRC}/src/mongo/platform/stack_locator_freebsd.cpp \
		${WRKSRC}/src/mongo/platform/stack_locator_dragonfly.cpp
	${CP} -R ${WRKSRC}/src/third_party/wiredtiger/build_openbsd \
		${WRKSRC}/src/third_party/wiredtiger/build_netbsd
	${CP} -R ${WRKSRC}/src/third_party/wiredtiger/build_freebsd \
		${WRKSRC}/src/third_party/wiredtiger/build_dragonfly

# let REPLACE_INTERPRETER kick in
do-configure:
	${DO_NADA}

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${SCONSBIN} ${SCONS_ARGS} \
	CC=${CC:Q} CXX=${CXX:Q} CFLAGS=${CFLAGS:Q} CXXFLAGS=${CXXFLAGS:Q} \
	LINKFLAGS=${LDFLAGS:Q} CPPPATH=${INCL_PATH:Q} VERBOSE=1 core

do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${SCONSBIN} ${SCONS_ARGS} \
	CC=${CC:Q} CXX=${CXX:Q} CFLAGS=${CFLAGS:Q} CXXFLAGS=${CXXFLAGS:Q} \
	LINKFLAGS=${LDFLAGS:Q} CPPPATH=${INCL_PATH:Q} \
	--prefix=${DESTDIR}${PREFIX} install

post-install:
	${INSTALL_MAN} ${WRKSRC}/debian/*.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/debian/mongod.conf \
		${DESTDIR}${PREFIX}/share/examples/mongodb

.include "../../archivers/zstd/buildlink3.mk"
.include "../../databases/mongo-c-driver/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
#.include "../../databases/wiredtiger/buildlink3.mk"
#.include "../../devel/asio/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/scons/buildlink3.mk"
.include "../../devel/snappy/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/yaml-cpp/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
