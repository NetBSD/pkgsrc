# $NetBSD: Makefile,v 1.50 2020/04/21 16:06:19 jperkin Exp $

DISTNAME=	elasticsearch-6.8.8
CATEGORIES=	databases textproc
MASTER_SITES=	https://artifacts.elastic.co/downloads/elasticsearch/

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	http://www.elasticsearch.org/
COMMENT=	Distributed RESTful Search Engine
LICENSE=	apache-2.0

# Uses javah, which doesn't exist in JDK10+ anymore.
PKG_JVMS_ACCEPTED=	openjdk8 oracle-jdk8 openjdk7 sun-jdk7

# Build our own native JNA, the version should match the one that ES ships with
JNA=			jna-4.5.1
DISTFILES=		${DEFAULT_DISTFILES} ${JNA}.tar.gz
SITES.${JNA}.tar.gz=	-${MASTER_SITE_GITHUB:=java-native-access/}jna/archive/${JNA:S/jna-//}.tar.gz

BUILD_DEPENDS+=	apache-ant-[0-9]*:../../devel/apache-ant

USE_LANGUAGES=	c c++
USE_JAVA=	run
USE_JAVA2=	8
USE_TOOLS+=	bash:run gmake pax pkg-config

PKG_SYSCONFSUBDIR=	elasticsearch
EGDIR=			${PREFIX}/share/examples/elasticsearch

CONFS=		elasticsearch.yml jvm.options log4j2.properties
.for f in ${CONFS}
CONF_FILES+=	${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor
DOCS=		LICENSE.txt NOTICE.txt README.textile

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	ES_USER ES_GROUP ES_DBDIR ES_LOGDIR ES_PIDDIR VARBASE

ES_USER?=	elasticsearch
ES_GROUP?=	${ES_USER}
ES_BASEDIR?=	${PREFIX}/lib/elasticsearch
ES_DBDIR?=	${VARBASE}/db/elasticsearch
ES_LOGDIR?=	${VARBASE}/log/elasticsearch
ES_PIDDIR?=	${VARBASE}/run

PKG_USERS_VARS+=	ES_USER
PKG_GROUPS_VARS+=	ES_GROUP
PKG_GROUPS=		${ES_GROUP}
PKG_USERS=		${ES_USER}:${ES_GROUP}

FILES_SUBST+=		JAVA_HOME=${PKG_JAVA_HOME:Q} ES_USER=${ES_USER}	\
			ES_GROUP=${ES_GROUP} ES_BASEDIR=${ES_BASEDIR}	\
			ES_LOGDIR=${ES_LOGDIR} ES_PIDDIR=${ES_PIDDIR}	\
			ES_DBDIR=${ES_DBDIR} 				\
			DISTNAME=${DISTNAME}

RCD_SCRIPTS=		elasticsearch

OWN_DIRS+=		${ES_BASEDIR}/plugins
OWN_DIRS_PERMS+=	${ES_LOGDIR} ${ES_USER} ${ES_GROUP} 0700
OWN_DIRS_PERMS+=	${ES_DBDIR} ${ES_USER} ${ES_GROUP} 0700
MAKE_DIRS+=		${PKG_SYSCONFDIR}/scripts

REPLACE_BASH+=		bin/elasticsearch*
INSTALLATION_DIRS+=	bin ${ES_BASEDIR}/bin
INSTALLATION_DIRS+=	${EGDIR} ${PREFIX}/share/doc/elasticsearch

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	bin/elasticsearch-env config/elasticsearch.yml
SUBST_VARS.paths=	PKG_JAVA_HOME PKG_SYSCONFDIR ES_DBDIR ES_BASEDIR ES_LOGDIR

BUILDLINK_TRANSFORM+=	rm:-Wno-unknown-warning-option
BUILDLINK_TRANSFORM+=	rm:-Werror

post-extract:
	${RM} ${WRKSRC}/lib/${JNA}.jar
	${MV} ${WRKDIR}/${JNA} ${WRKSRC}/jna

do-build:
	# Override silly SunOS et al. assumptions.
	${_ULIMIT_CMD} cd ${WRKSRC}/jna && ${SETENV} ${MAKE_ENV} ant -Ddynlink.native=true -Dgrep=grep -Dmake.PATH=PATH=${PATH:Q} -Dmake=make native
	${_ULIMIT_CMD} cd ${WRKSRC}/jna/build/classes && ${SETENV} ${MAKE_ENV} jar cf ${WRKSRC}/lib/${JNA}.jar com/

do-install:
.for f in ${CONFS}
	${INSTALL_DATA} ${WRKSRC}/config/${f} ${DESTDIR}${EGDIR}
.endfor
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f}	\
		${DESTDIR}${PREFIX}/share/doc/elasticsearch
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/bin/elasticsearch ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/elasticsearch-env ${DESTDIR}${ES_BASEDIR}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/elasticsearch-keystore ${DESTDIR}${ES_BASEDIR}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/elasticsearch-plugin ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/elasticsearch-translog ${DESTDIR}${ES_BASEDIR}/bin
	cd ${WRKSRC} && ${PAX} -rw -pp lib modules ${DESTDIR}${ES_BASEDIR}
# Remove irrelevant precompiled binaries and libs
	${RM} -rf ${DESTDIR}${ES_BASEDIR}/modules/x-pack-ml/platform/windows-x86_64
.if empty(MACHINE_PLATFORM:MDarwin-*-x86_64)
	${RM} -rf ${DESTDIR}${ES_BASEDIR}/modules/x-pack-ml/platform/darwin-x86_64
.endif
.if empty(MACHINE_PLATFORM:MLinux-*-x86_64)
	${RM} -rf ${DESTDIR}${ES_BASEDIR}/modules/x-pack-ml/platform/linux-x86_64
.endif

.include "../../devel/libffi/buildlink3.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
