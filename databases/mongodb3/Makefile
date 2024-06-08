# $NetBSD: Makefile,v 1.36 2024/06/08 22:49:45 gdt Exp $

# This package is intentionally old to avoid:
#   Server Side Public License
DISTNAME=	mongodb-src-r3.4.24
PKGNAME=	${DISTNAME:S/src-r//}
PKGREVISION=	22
CATEGORIES=	databases
MASTER_SITES=	http://fastdl.mongodb.org/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.mongodb.com/
COMMENT=	NoSQL distributed document-oriented database
LICENSE=	gnu-agpl-v3 # Client and tools licensed under apache-2.0

# MongoDB 3.4 onwards explicitly does not support 32-bit x86 platforms
NOT_FOR_PLATFORM+=	*-*-i386

EXTRACT_USING=	bsdtar

NO_CONFIGURE=	yes
USE_LANGUAGES=	c c++

FORCE_CXX_STD+=	c++17

SCONS_ARGS=	${_MAKE_JOBS}
SCONS_ARGS+=	--dbg=off # on: argument parsing problem
SCONS_ARGS+=	--disable-warnings-as-errors
SCONS_ARGS+=	--release
SCONS_ARGS+=	--runtime-hardening=off # on: does not produce executables
# incompatible with latest boost version, missing boost/filesystem/convenience.hpp
#SCONS_ARGS+=	--use-system-boost
SCONS_ARGS+=	--use-system-icu
SCONS_ARGS+=	--use-system-pcre
SCONS_ARGS+=	--use-system-snappy
SCONS_ARGS+=	--use-system-tcmalloc
SCONS_ARGS+=	--use-system-yaml
SCONS_ARGS+=	--use-system-zlib

PYTHON_VERSIONS_ACCEPTED=	27 # not yet supported as of 3.4.23

.include "../../mk/bsd.prefs.mk"

CPPFLAGS+=	-fno-jump-tables  # XXX: still needed?
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
SUBST_FILES.path+=	src/mongo/shell/dbshell.cpp
SUBST_FILES.path+=	src/mongo/db/storage/storage_options.cpp
SUBST_SED.path=		-e 's,/data/db,${MONGODB_DBPATH},g'
SUBST_SED.path+=	-e 's,/data/configdb,${MONGODB_CONFIGDBPATH},g'
SUBST_SED.path+=	-e 's,/etc,${PKG_SYSCONFDIR},g'

SUBST_CLASSES+=		varbase
SUBST_STAGE.varbase=	pre-build
SUBST_MESSAGE.varbase=	Changing /var to ${VARBASE}.
SUBST_FILES.varbase=	debian/mongod.conf
SUBST_SED.varbase=	-e 's,/var/lib,${VARBASE},g'
SUBST_SED.varbase+=	-e 's,/var/log,${VARBASE},g'

NOT_PAX_MPROTECT_SAFE+=	bin/mongo bin/mongod

RCD_SCRIPTS=		mongodb

INSTALLATION_DIRS+=	share/doc/mongodb share/examples/mongodb ${PKGMANDIR}/man1

CONF_FILES+=		share/examples/mongodb/mongod.conf \
			${PKG_SYSCONFDIR}/mongod.conf

# Copy system specific files for NetBSD and DragonFly
post-extract:
	${CHMOD} -R g-w ${WRKSRC}
	${CP} -R ${WRKSRC}/src/third_party/mozjs-45/platform/aarch64/linux \
		${WRKSRC}/src/third_party/mozjs-45/platform/aarch64/netbsd
	${CP} -R ${WRKSRC}/src/third_party/mozjs-45/platform/x86_64/freebsd \
		${WRKSRC}/src/third_party/mozjs-45/platform/x86_64/dragonfly
	${CP} -R ${WRKSRC}/src/third_party/mozjs-45/platform/x86_64/openbsd \
		${WRKSRC}/src/third_party/mozjs-45/platform/x86_64/netbsd
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
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/mongodb
	${INSTALL_MAN} ${WRKSRC}/debian/*.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/debian/mongod.conf \
		${DESTDIR}${PREFIX}/share/examples/mongodb

.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/scons/buildlink3.mk"
.include "../../devel/snappy/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/yaml-cpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
