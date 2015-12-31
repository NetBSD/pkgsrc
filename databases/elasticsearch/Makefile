# $NetBSD: Makefile,v 1.14 2015/12/31 09:57:31 fhajny Exp $

DISTNAME=	elasticsearch-2.1.1
CATEGORIES=	textproc
MASTER_SITES=	https://download.elasticsearch.org/elasticsearch/elasticsearch/

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	http://www.elasticsearch.org/
COMMENT=	Distributed RESTful Search Engine
LICENSE=	apache-2.0

USE_LANGUAGES=	# none
USE_JAVA=	run
USE_JAVA2=	yes
NO_BUILD=	yes

PKG_SYSCONFSUBDIR=	elasticsearch
EGDIR=			${PREFIX}/share/examples/elasticsearch

CONFS=	elasticsearch.yml logging.yml
.for f in ${CONFS}
CONF_FILES+=	${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor
DOCS=		LICENSE.txt NOTICE.txt README.textile
BINS=		elasticsearch elasticsearch.in.sh plugin

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	ES_USER ES_GROUP ES_DBDIR ES_LOGDIR ES_PIDDIR ES_TMPDIR

ES_USER?=	elasticsearch
ES_GROUP?=	${ES_USER}
ES_LIBDIR?=	${PREFIX}/lib/elasticsearch
ES_DBDIR?=	${VARBASE}/db/elasticsearch
ES_LOGDIR?=	${VARBASE}/log/elasticsearch
ES_PIDDIR?=	${VARBASE}/run
ES_TMPDIR?=	${VARBASE}/tmp/elasticsearch

PKG_USERS_VARS+=	ES_USER
PKG_GROUPS_VARS+=	ES_GROUP
PKG_GROUPS=		${ES_GROUP}
PKG_USERS=		${ES_USER}:${ES_GROUP}

FILES_SUBST+=		JAVA_HOME=${PKG_JAVA_HOME} ES_USER=${ES_USER}	\
			ES_GROUP=${ES_GROUP} ES_LIBDIR=${ES_LIBDIR}	\
			ES_LOGDIR=${ES_LOGDIR} ES_PIDDIR=${ES_PIDDIR}	\
			ES_DBDIR=${ES_DBDIR} ES_TMPDIR=${ES_TMPDIR}	\
			DISTNAME=${DISTNAME}

RCD_SCRIPTS=		elasticsearch

OWN_DIRS+=		${ES_LIBDIR}/plugins
OWN_DIRS_PERMS+=	${ES_LOGDIR} ${ES_USER} ${ES_GROUP} 0700
OWN_DIRS_PERMS+=	${ES_DBDIR} ${ES_USER} ${ES_GROUP} 0700
OWN_DIRS_PERMS+=	${ES_TMPDIR} ${ES_USER} ${ES_GROUP} 0700
MAKE_DIRS+=		${PKG_SYSCONFDIR}/scripts
INSTALLATION_DIRS+=	${ES_LIBDIR} ${PREFIX}/libexec/elasticsearch
INSTALLATION_DIRS+=	${EGDIR} ${PREFIX}/share/doc/elasticsearch

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	bin/plugin config/elasticsearch.yml
SUBST_VARS.paths=	PKG_JAVA_HOME PKG_SYSCONFDIR PREFIX ES_DBDIR ES_LIBDIR ES_LOGDIR ES_TMPDIR

do-install:
.for f in ${CONFS}
	${INSTALL_DATA} ${WRKSRC}/config/${f} ${DESTDIR}${EGDIR}
.endfor
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f}	\
		${DESTDIR}${PREFIX}/share/doc/elasticsearch
.endfor
.for f in ${BINS}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${f}	\
		${DESTDIR}${PREFIX}/libexec/elasticsearch
.endfor
	${INSTALL_DATA} ${WRKSRC}/lib/*.jar ${DESTDIR}${ES_LIBDIR}

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
