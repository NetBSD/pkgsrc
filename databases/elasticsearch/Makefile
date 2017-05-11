# $NetBSD: Makefile,v 1.28 2017/05/11 08:36:30 fhajny Exp $

DISTNAME=	elasticsearch-5.4.0
CATEGORIES=	textproc
MASTER_SITES=	https://artifacts.elastic.co/downloads/elasticsearch/

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	http://www.elasticsearch.org/
COMMENT=	Distributed RESTful Search Engine
LICENSE=	apache-2.0

USE_LANGUAGES=	# none
USE_JAVA=	run
USE_JAVA2=	8
USE_TOOLS+=	bash:run pax
NO_BUILD=	yes

PKG_SYSCONFSUBDIR=	elasticsearch
EGDIR=			${PREFIX}/share/examples/elasticsearch

CONFS=		elasticsearch.yml jvm.options log4j2.properties
.for f in ${CONFS}
CONF_FILES+=	${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor
DOCS=		LICENSE.txt NOTICE.txt README.textile

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	ES_USER ES_GROUP ES_DBDIR ES_LOGDIR ES_PIDDIR

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

FILES_SUBST+=		JAVA_HOME=${PKG_JAVA_HOME} ES_USER=${ES_USER}	\
			ES_GROUP=${ES_GROUP} ES_BASEDIR=${ES_BASEDIR}	\
			ES_LOGDIR=${ES_LOGDIR} ES_PIDDIR=${ES_PIDDIR}	\
			ES_DBDIR=${ES_DBDIR} 				\
			DISTNAME=${DISTNAME}

RCD_SCRIPTS=		elasticsearch

OWN_DIRS+=		${ES_BASEDIR}/plugins
OWN_DIRS_PERMS+=	${ES_LOGDIR} ${ES_USER} ${ES_GROUP} 0700
OWN_DIRS_PERMS+=	${ES_DBDIR} ${ES_USER} ${ES_GROUP} 0700
MAKE_DIRS+=		${PKG_SYSCONFDIR}/scripts

REPLACE_BASH+=		bin/elasticsearch bin/elasticsearch.in.sh bin/elasticsearch-plugin
INSTALLATION_DIRS+=	bin ${ES_BASEDIR}/bin
INSTALLATION_DIRS+=	${EGDIR} ${PREFIX}/share/doc/elasticsearch

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	bin/elasticsearch bin/elasticsearch-plugin config/elasticsearch.yml
SUBST_VARS.paths=	PKG_JAVA_HOME PKG_SYSCONFDIR ES_DBDIR ES_BASEDIR ES_LOGDIR

do-install:
.for f in ${CONFS}
	${INSTALL_DATA} ${WRKSRC}/config/${f} ${DESTDIR}${EGDIR}
.endfor
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f}	\
		${DESTDIR}${PREFIX}/share/doc/elasticsearch
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/bin/elasticsearch ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/elasticsearch-plugin ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/elasticsearch.in.sh ${DESTDIR}${ES_BASEDIR}/bin
	cd ${WRKSRC} && ${PAX} -rw -pp lib modules ${DESTDIR}${ES_BASEDIR}

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
