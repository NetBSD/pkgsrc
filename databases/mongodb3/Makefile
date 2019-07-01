# $NetBSD: Makefile,v 1.2 2019/07/01 04:08:01 ryoon Exp $

# This package is intentionally old to avoid:
#   Server Side Public License
#   c++17 (and c++14 if 3.4.4 does not already need it)
DISTNAME=	mongodb-src-r3.4.4
PKGNAME=	${DISTNAME:S/src-r//:S/-rc/rc/}
PKGREVISION=	7
CATEGORIES=	databases
MASTER_SITES=	http://fastdl.mongodb.org/src/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://mongodb.org/
COMMENT=	NoSQL distributed document-oriented database
LICENSE=	gnu-agpl-v3 # Client and tools licensed under apache-2.0

# MongoDB 3.4 onwards explicitly does not support 32-bit x86 platforms
NOT_FOR_PLATFORM+=	*-*-i386

EXTRACT_USING=	bsdtar

NO_CONFIGURE=	yes
USE_LANGUAGES=	c c++

SCONS_ARGS=	${_MAKE_JOBS}
SCONS_ARGS+=	--use-system-boost
SCONS_ARGS+=	--use-system-pcre
SCONS_ARGS+=	--use-system-snappy
SCONS_ARGS+=	--use-system-tcmalloc
SCONS_ARGS+=	--use-system-yaml
SCONS_ARGS+=	--use-system-zlib
SCONS_ARGS+=	--js-engine=mozjs
SCONS_ARGS+=	--release

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # not yet supported as of 3.0.4

.include "../../mk/bsd.prefs.mk"

# XXX this doesn't work for some reason
#.if !empty(INSTALL_UNSTRIPPED:Uno:M[Yy][Ee][Ss])
#SCONS_ARGS+=	--nostrip
#.endif

GCC_REQD+=	5.3.0

CPPFLAGS+=	-fno-jump-tables

.include "options.mk"

SMF_METHODS+=		mongodb

BUILD_DEFS+=		VARBASE
BUILD_DEFS+=		MONGODB_USER MONGODB_GROUP MONGODB_DBPATH
BUILD_DEFS+=		MONGODB_LOGPATH

MONGODB_USER?=		mongodb
MONGODB_GROUP?=		mongodb
MONGODB_DBPATH?=	${VARBASE}/mongodb
MONGODB_LOGPATH?=	${VARBASE}/log/mongodb

PKG_USERS_VARS+=	MONGODB_USER
PKG_GROUPS_VARS+=	MONGODB_GROUP

PKG_GROUPS=		${MONGODB_GROUP}
PKG_USERS=		${MONGODB_USER}:${MONGODB_GROUP}

PKG_GECOS.${MONGODB_USER}=	MongoDB database administrator
PKG_HOME.${MONGODB_USER}=	${MONGODB_DBPATH}
PKG_SHELL.${MONGODB_USER}=	${SH}

OWN_DIRS_PERMS+=	${MONGODB_DBPATH} ${MONGODB_USER} ${MONGODB_GROUP} 0755
OWN_DIRS_PERMS+=	${MONGODB_DBPATH}/journal ${MONGODB_USER} ${MONGODB_GROUP} 0755
OWN_DIRS_PERMS+=	${MONGODB_LOGPATH} ${MONGODB_USER} ${MONGODB_GROUP} 0755

FILES_SUBST+=		MONGODB_USER=${MONGODB_USER}
FILES_SUBST+=		MONGODB_GROUP=${MONGODB_GROUP}
FILES_SUBST+=		MONGODB_DBPATH=${MONGODB_DBPATH}
FILES_SUBST+=		MONGODB_LOGPATH=${MONGODB_LOGPATH}

# XXX No better idea how to pass CXXFLAGS and LDFLAGS to scons
SUBST_CLASSES+=		scons
SUBST_STAGE.scons=	pre-build
SUBST_FILES.scons=	SConstruct
SUBST_VARS.scons=	PREFIX CXXFLAGS LDFLAGS

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-build
SUBST_FILES.path=	src/mongo/db/flushtest.cpp debian/mongod.conf
SUBST_FILES.path+=	debian/mongod.1 debian/mongo.1 src/mongo/shell/dbshell.cpp
SUBST_SED.path=		-e 's|/data/db|${MONGODB_DBPATH}|g'
SUBST_SED.path+=	-e 's|/etc|${PKG_SYSCONFDIR}|'
SUBST_VARS.path=	MONGODB_DBPATH MONGODB_LOGPATH

LDFLAGS+=		${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.boost-libs}/lib

MONGODB_MAN_FILES=	bsondump.1 mongo.1 mongod.1 mongodump.1 mongoexport.1	\
			mongofiles.1 mongoimport.1 mongooplog.1 mongoperf.1	\
			mongorestore.1 mongos.1 mongosniff.1 mongostat.1 mongotop.1

NOT_PAX_MPROTECT_SAFE+=	bin/mongo bin/mongod

RCD_SCRIPTS=		mongodb

INSTALLATION_DIRS+=	share/doc/mongodb share/examples/mongodb ${PKGMANDIR}/man1

CONF_FILES+=		share/examples/mongodb/mongod.conf \
			${PKG_SYSCONFDIR}/mongod.conf

post-extract:
	chmod -R g-w ${WRKSRC}
	cp -r ${WRKSRC}/src/third_party/mozjs-45/platform/x86_64/freebsd \
		${WRKSRC}/src/third_party/mozjs-45/platform/x86_64/dragonfly
	cp -r ${WRKSRC}/src/third_party/mozjs-45/platform/x86_64/openbsd \
		${WRKSRC}/src/third_party/mozjs-45/platform/x86_64/netbsd
	cp ${WRKSRC}/src/mongo/db/ftdc/ftdc_system_stats_openbsd.cpp \
		${WRKSRC}/src/mongo/db/ftdc/ftdc_system_stats_netbsd.cpp

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${SCONSBIN} ${SCONS_ARGS} core

do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${SCONSBIN} ${SCONS_ARGS} \
		--prefix=${DESTDIR}${PREFIX} install

do-test:
	cd ${WRKSRC} && ./test

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/mongodb
.for file in ${MONGODB_MAN_FILES}
	${INSTALL_MAN} ${WRKSRC}/debian/${file} \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.endfor
	${INSTALL_DATA} ${WRKSRC}/debian/mongod.conf \
		${DESTDIR}${PREFIX}/share/examples/mongodb

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/py-boost/buildlink3.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/scons/buildlink3.mk"
.include "../../devel/snappy/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../textproc/yaml-cpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
