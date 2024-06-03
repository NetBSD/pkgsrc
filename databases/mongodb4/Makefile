# $NetBSD: Makefile,v 1.11 2024/06/03 14:27:34 ryoon Exp $

DISTNAME=	mongodb-src-r4.4.28
PKGNAME=	${DISTNAME:S/src-r//}
PKGREVISION=	4
CATEGORIES=	databases
MASTER_SITES=	http://fastdl.mongodb.org/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.mongodb.com/
COMMENT=	NoSQL distributed document-oriented database
LICENSE=	server-side-public-license # Client and tools licensed under apache-2.0

# MongoDB 3.4 onwards explicitly does not support 32-bit x86 platforms
NOT_FOR_PLATFORM+=	*-*-i386

EXTRACT_USING=	bsdtar

# etc/pip/core-requirements.txt
TOOL_DEPENDS+=	${PYPKGPREFIX}-cheetah-[0-9]*:../../devel/py-cheetah3
TOOL_DEPENDS+=	${PYPKGPREFIX}-mongo>=3.0:../../databases/py-mongo
TOOL_DEPENDS+=	${PYPKGPREFIX}-psutil-[0-9]*:../../sysutils/py-psutil
TOOL_DEPENDS+=	${PYPKGPREFIX}-regex-[0-9]*:../../textproc/py-regex
TOOL_DEPENDS+=	${PYPKGPREFIX}-requests>=2.0.0:../../devel/py-requests
TOOL_DEPENDS+=	${PYPKGPREFIX}-yaml>=3.0.0:../../textproc/py-yaml
TOOL_DEPENDS+=	${PYPKGPREFIX}-wrapt>=1.12.1:../../devel/py-wrapt

# https://github.com/mongodb/mongo/blob/master/docs/building.md
USE_LANGUAGES=		c c++
USE_CC_FEATURES=	c99
USE_CXX_FEATURES=	c++17 filesystem
GCC_REQD+=		10

USE_TOOLS+=	pkg-config

SCONS_BUILD_ARGS=	${_MAKE_JOBS}
SCONS_BUILD_ARGS+=	--dbg=off # on: argument parsing problem
SCONS_BUILD_ARGS+=	--disable-warnings-as-errors
SCONS_BUILD_ARGS+=	--release
SCONS_BUILD_ARGS+=	--runtime-hardening=off # on: does not produce executables
#SCONS_BUILD_ARGS+=	--use-system-abseil-cpp
#SCONS_BUILD_ARGS+=	--use-system-asio
#SCONS_BUILD_ARGS+=	--use-system-boost
SCONS_BUILD_ARGS+=	--use-system-icu
SCONS_BUILD_ARGS+=	--use-system-mongo-c
SCONS_BUILD_ARGS+=	--use-system-pcre
SCONS_BUILD_ARGS+=	--use-system-snappy
SCONS_BUILD_ARGS+=	--use-system-tcmalloc
#SCONS_BUILD_ARGS+=	--use-system-wiredtiger
SCONS_BUILD_ARGS+=	--use-system-yaml
SCONS_BUILD_ARGS+=	--use-system-zlib
SCONS_BUILD_ARGS+=	--use-system-zstd
SCONS_BUILD_ARGS+=	--modules='' # avoid enterprise build

PYTHON_VERSIONS_INCOMPATIBLE=	27 312

.include "../../mk/bsd.prefs.mk"

INCL_PATH+=	${BUILDLINK_PREFIX.mongo-c-driver}/include/libbson-1.0
INCL_PATH+=	${BUILDLINK_PREFIX.mongo-c-driver}/include/libmongoc-1.0
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib -L${PREFIX}/lib

# needed for linking against boost_log, otherwise some symbols are not found
#SCONS_BUILD_ARGS+=	CPPDEFINES=-DBOOST_LOG_DYN_LINK=1
SCONS_BUILD_ARGS+=	CC=${CC:Q}
SCONS_BUILD_ARGS+=	CXX=${CXX:Q}
SCONS_BUILD_ARGS+=	CFLAGS=${CFLAGS:Q}
SCONS_BUILD_ARGS+=	CXXFLAGS=${CXXFLAGS:Q}
SCONS_BUILD_ARGS+=	LINKFLAGS=${LDFLAGS:Q}
SCONS_BUILD_ARGS+=	CPPPATH=${INCL_PATH:Q}
INSTALL_TARGET=		install-devcore
SCONS_INSTALL_ARGS+=	DESTDIR=${DESTDIR}
SCONS_INSTALL_ARGS+=	PREFIX=${PREFIX}

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

NOT_PAX_MPROTECT_SAFE+=	bin/mongo bin/mongod bin/mongos

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

post-install:
.for junk in LICENSE-Community.txt LICENSE-Enterprise.txt MPL-2 README THIRD-PARTY-NOTICES \
	bin/resmoke.py macos_mongodb.plist
	${RM} -f ${DESTDIR}${PREFIX}/${junk}
.endfor
	${INSTALL_MAN} ${WRKSRC}/debian/*.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/debian/mongod.conf \
		${DESTDIR}${PREFIX}/share/examples/mongodb

.include "../../archivers/zstd/buildlink3.mk"
.include "../../databases/mongo-c-driver/buildlink3.mk"
#.include "../../databases/wiredtiger/buildlink3.mk"
#.include "../../devel/abseil/buildlink3.mk"
#.include "../../devel/asio/buildlink3.mk"
#.include "../../devel/boost-headers/buildlink3.mk"
#.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/scons4/build.mk"
_SCONS_BUILD_ARGS=     -j${MAKE_JOBS:U1}
_SCONS_BUILD_ARGS+=     ${SCONS_BUILD_ARGS}
.include "../../devel/snappy/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/yaml-cpp/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
