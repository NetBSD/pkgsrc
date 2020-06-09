# $NetBSD: Makefile,v 1.1 2020/06/09 22:20:01 jym Exp $

DISTNAME=	solr-${SOLR_VER}
PKGNAME=	apache-solr-${SOLR_VER}
SOLR_VER=	8.5.1
CATEGORIES=	databases textproc
MASTER_SITES=	${MASTER_SITE_APACHE:=lucene/solr/${SOLR_VER}/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	jym@NetBSD.org
HOMEPAGE=	https://lucene.apache.org/solr/
COMMENT=	High performance search server built using Lucene Java
LICENSE=	apache-2.0

NO_BUILD=	yes
USE_LANGUAGES=	# none
USE_JAVA=	run
USE_JAVA2=	8
USE_TOOLS+=	bash:run pax

# Used by solr launch script to test for presence of the listening socket
DEPENDS+=	lsof-[0-9]*:../../sysutils/lsof

REPLACE_INTERPRETER+=	bash
REPLACE.bash.old=	/usr/bin/env bash
REPLACE.bash.new=	${TOOLS_PATH.bash}
REPLACE_FILES.bash=	bin/solr server/scripts/cloud-scripts/*.sh

.include "../../mk/bsd.prefs.mk"

EGDIR=		${PREFIX}/share/examples/solr
DOCDIR=		${PREFIX}/share/doc/solr
SOLR_DIR?=	${PREFIX}/solr
SOLR_LOGDIR?=	${VARBASE}/log/solr
SOLR_PIDDIR?=	${VARBASE}/run/solr
SOLR_EXAMPLE?=	${EGDIR}/example

BUILD_DEFS+=	SOLR_USER SOLR_GROUP SOLR_HOME SOLR_PORT
BUILD_DEFS+=	SOLR_LOGDIR SOLR_PIDDIR VARBASE

CONF_FILES+=	${EGDIR}/solr.in.sh ${PKG_SYSCONFDIR}/solr.in.sh
CONF_FILES+=	${EGDIR}/solr.xml   ${PKG_SYSCONFDIR}/solr.xml

DOCS=		CHANGES.txt LICENSE.txt NOTICE.txt README.txt
PAXDIRS=	contrib dist server

RCD_SCRIPTS=		solr
# Solr binding port
SOLR_PORT?=		8983
SOLR_USER?=		solr
SOLR_GROUP?=		${SOLR_USER}
SOLR_HOME?=		${SOLR_DIR}

PKG_SYSCONFSUBDIR=	solr
PKG_USERS=		${SOLR_USER}:${SOLR_GROUP}
PKG_GROUPS=		${SOLR_GROUP}
PKG_HOME.solr=		${SOLR_HOME}
PKG_USERS_VARS+=	SOLR_USER
PKG_GROUPS_VARS+=	SOLR_GROUP

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	solr.in.sh bin/solr
SUBST_VARS.paths+=	PKG_SYSCONFDIR PREFIX SOLR_HOME SOLR_PORT
SUBST_VARS.paths+=	SOLR_EXAMPLE SOLR_LOGDIR SOLR_PIDDIR

FILES_SUBST+=	JAVA_HOME=${PKG_JAVA_HOME:Q} \
		SOLR_LOGDIR=${SOLR_LOGDIR:Q} SOLR_HOME=${SOLR_HOME:Q} \
		SOLR_PIDDIR=${SOLR_PIDDIR:Q} SOLR_PORT=${SOLR_PORT:Q} \
		SOLR_USER=${SOLR_USER} SOLR_GROUP=${SOLR_GROUP}

OWN_DIRS_PERMS+=	${SOLR_HOME}   ${SOLR_USER} ${SOLR_GROUP} 0700
OWN_DIRS_PERMS+=	${SOLR_LOGDIR} ${SOLR_USER} ${SOLR_GROUP} 0700
OWN_DIRS_PERMS+=	${SOLR_PIDDIR} ${SOLR_USER} ${SOLR_GROUP} 0700

INSTALLATION_DIRS=	bin ${DOCDIR} ${EGDIR} ${SOLR_DIR}

pre-patch:
	${CP} ${FILESDIR}/solr.in.sh ${WRKSRC}/solr.in.sh

do-install:
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${DOCDIR}
.endfor
.for d in ${PAXDIRS}
	${INSTALL_DATA_DIR} ${DESTDIR}${SOLR_DIR}/${d}
	cd ${WRKSRC}/${d} && pax -rwpam . ${DESTDIR}${SOLR_DIR}/${d}
.endfor
	${INSTALL_DATA} ${WRKSRC}/solr.in.sh ${DESTDIR}${EGDIR}/solr.in.sh
	${INSTALL_DATA} ${WRKSRC}/server/solr/solr.xml \
		${DESTDIR}${EGDIR}/solr.xml
	${INSTALL_DATA_DIR} ${DESTDIR}${SOLR_EXAMPLE}
	cd ${WRKSRC}/example && pax -rwpam . ${DESTDIR}${SOLR_EXAMPLE}
	${CHOWN} -R ${SOLR_USER}:${SOLR_GROUP} ${DESTDIR}${SOLR_EXAMPLE}

	${INSTALL_DATA_DIR} ${DESTDIR}${SOLR_DIR}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/solr ${DESTDIR}${SOLR_DIR}/bin/solr
	${LN} -s ${DESTDIR}${SOLR_DIR}/bin/solr ${DESTDIR}${PREFIX}/bin/solr

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
