# $NetBSD: Makefile,v 1.2 2017/05/10 18:14:06 fhajny Exp $

DISTNAME=	kafka_${SCALA_VERSION}-0.10.2.1
PKGNAME=	${DISTNAME:S/_${SCALA_VERSION}//}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_APACHE:=kafka/${PKGVERSION_NOREV}/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://kafka.apache.org/
COMMENT=	Distributed streaming platform
LICENSE=	apache-2.0 AND cddl-1.0

DEPENDS+=	zookeeper-[0-9]*:../../devel/zookeeper

USE_JAVA2=	7
USE_LANGUAGES=	# none

NO_BUILD=	yes

SCALA_VERSION=	2.12

REPLACE_SH+=	bin/connect-* bin/kafka-*

FILES_SUBST+=	KAFKA_USER=${KAFKA_USER} KAFKA_GROUP=${KAFKA_GROUP}

PKG_SYSCONFSUBDIR=	kafka

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	KAFKA_DATADIR KAFKA_LOGDIR KAFKA_USER KAFKA_GROUP VARBASE

KAFKA_DATADIR?=	${VARBASE}/db/kafka
KAFKA_LOGDIR?=	${VARBASE}/log/kafka
KAFKA_USER?=	kafka
KAFKA_GROUP?=	kafka

PKG_GROUPS+=		${KAFKA_GROUP}
PKG_USERS+=		${KAFKA_USER}:${KAFKA_GROUP}
PKG_GECOS.${KAFKA_USER}=Kafka service user
PKG_HOME.${KAFKA_USER}=	${KAFKA_DATADIR}

OWN_DIRS_PERMS+=	${KAFKA_DATADIR} ${KAFKA_USER} ${KAFKA_GROUP} 0755
OWN_DIRS_PERMS+=	${KAFKA_LOGDIR} ${KAFKA_USER} ${KAFKA_GROUP} 0755

CONFIG_FILES=		consumer log4j producer server tools-log4j 	\
			connect-console-sink connect-console-source	\
			connect-distributed connect-file-sink		\
			connect-file-source connect-log4j		\
			connect-standalone

.for file in ${CONFIG_FILES}
CONF_FILES+=		share/examples/kafka/${file}.properties		\
			${PKG_SYSCONFDIR}/${file}.properties
.endfor

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_MESSAGE.path=	Fixing default paths
SUBST_FILES.path=	bin/kafka-run-class.sh bin/kafka-server-start.sh
SUBST_FILES.path+=	config/server.properties
SUBST_VARS.path=	KAFKA_DATADIR KAFKA_LOGDIR PKG_SYSCONFDIR PKG_JAVA_HOME

INSTALLATION_DIRS+=	bin share/examples/kafka lib/java/kafka/libs

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/connect-*.sh			\
		${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/kafka-*.sh			\
		${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/libs/*.jar		\
		${DESTDIR}${PREFIX}/lib/java/kafka/libs
.for file in ${CONFIG_FILES}
	${INSTALL_DATA} ${WRKSRC}/config/${file}.properties		\
		${DESTDIR}${PREFIX}/share/examples/kafka
.endfor

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
