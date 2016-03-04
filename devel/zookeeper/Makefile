# $NetBSD: Makefile,v 1.3 2016/03/04 13:40:34 fhajny Exp $
#

.include "Makefile.common"

COMMENT=		Highly reliable distributed coordination server

DISTFILES=			${DEFAULT_DISTFILES} ${DISTNAME}-deps.tar.gz
SITES.${DISTNAME}-deps.tar.gz=	ftp://ftp.NetBSD.org/pub/NetBSD/misc/fhajny/

BUILD_DEPENDS+=		apache-ant-[0-9]*:../../devel/apache-ant
BUILD_DEPENDS+=		apache-ivy>=2.2.0:../../devel/apache-ivy

USE_JAVA=		yes
USE_JAVA2=		yes
USE_TOOLS+=		bash:run pax

PKG_SYSCONFSUBDIR=	zookeeper

.include "../../mk/bsd.prefs.mk"

ZK_DB?=			${VARBASE}/db/zookeeper
ZK_LOG?=		${VARBASE}/log/zookeeper
ZK_RUN?=		${VARBASE}/run/zookeeper
ZK_USER?=		zookeeper
ZK_GROUP?=		zookeeper

BUILD_DEFS+=		VARBASE ZK_DB ZK_LOG ZK_RUN ZK_USER ZK_GROUP

PKG_GROUPS+=		${ZK_GROUP}
PKG_USERS+=		${ZK_USER}:${ZK_GROUP}

PKG_GECOS.${ZK_USER}=	ZooKeeper Daemon User
PKG_HOME.${ZK_USER}=	${PREFIX}/share/zookeeper
PKG_SHELL.${ZK_USER}=	${BASH}

OWN_DIRS_PERMS+=	${ZK_DB} ${ZK_USER} ${ZK_GROUP} 755
OWN_DIRS_PERMS+=	${ZK_DB}/data ${ZK_USER} ${ZK_GROUP} 755
OWN_DIRS_PERMS+=	${ZK_LOG} ${ZK_USER} ${ZK_GROUP} 755
OWN_DIRS_PERMS+=	${ZK_RUN} ${ZK_USER} ${ZK_GROUP} 755

BUILDDIR=		${WRKSRC}/build/${DISTNAME}
EGDIR=			share/examples/zookeeper

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	post-patch
SUBST_MESSAGE.paths=	Fixing ZooKeeper default paths
SUBST_FILES.paths=	conf/zoo_sample.cfg
SUBST_FILES.paths+=	src/packages/templates/conf/zookeeper-env.sh
SUBST_VARS.paths+=	PKG_JAVA_HOME ZK_DB ZK_LOG ZK_RUN

REPLACE_BASH=		bin/zkCli.sh bin/zkEnv.sh bin/zkServer.sh

INSTALLATION_DIRS+=	bin libexec sbin share/zookeeper ${EGDIR}

CONF_FILES+=		${EGDIR}/configuration.xsl ${PKG_SYSCONFDIR}/configuration.xsl
CONF_FILES+=		${EGDIR}/log4j.properties ${PKG_SYSCONFDIR}/log4j.properties
CONF_FILES+=		${EGDIR}/zoo.cfg ${PKG_SYSCONFDIR}/zoo.cfg
CONF_FILES_PERMS+=	${EGDIR}/zookeeper-env.sh ${PKG_SYSCONFDIR}/zookeeper-env.sh \
			${ROOT_USER} ${ROOT_GROUP} 0755

FILES_SUBST+=		ZK_USER=${ZK_USER} ZK_GROUP=${ZK_GROUP}

ANT_ARGS+=		-Duser.home=${FAKEHOMEDIR} -Divy.home=${WRKDIR}/ivy
ANT_TARGET=		bin-package

post-extract:
	${LN} -s ${PREFIX}/lib/java/ant/ivy-*.jar ${WRKSRC}/src/java/lib/ivy-0.0.0.jar

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ant ${ANT_ARGS} ${ANT_TARGET}

do-install:
	${INSTALL_SCRIPT} ${BUILDDIR}/bin/zkCli.sh ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${BUILDDIR}/libexec/zkEnv.sh ${DESTDIR}${PREFIX}/libexec
	${INSTALL_SCRIPT} ${BUILDDIR}/sbin/zkServer.sh ${DESTDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${BUILDDIR}/conf/configuration.xsl ${DESTDIR}${PREFIX}/${EGDIR}
	${INSTALL_DATA} ${BUILDDIR}/conf/log4j.properties ${DESTDIR}${PREFIX}/${EGDIR}
	${INSTALL_DATA} ${BUILDDIR}/conf/zoo_sample.cfg ${DESTDIR}${PREFIX}/${EGDIR}/zoo.cfg
	${INSTALL_DATA} ${BUILDDIR}/share/zookeeper/templates/conf/zookeeper-env.sh	\
		${DESTDIR}${PREFIX}/${EGDIR}/zookeeper-env.sh
	cd ${BUILDDIR}/share/zookeeper && ${PAX} -rw -pp * ${DESTDIR}${PREFIX}/share/zookeeper/
	${RM} -f ${DESTDIR}${PREFIX}/share/zookeeper/templates/conf/zookeeper-env.sh.orig

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
