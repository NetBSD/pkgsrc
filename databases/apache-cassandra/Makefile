# $NetBSD: Makefile,v 1.15 2014/02/14 10:25:23 fhajny Exp $
#

DISTNAME=	apache-cassandra-${CASSANDRA_VER}
PKGNAME=	apache-cassandra-${CASSANDRA_VER:S/-//}
CATEGORIES=	databases
#MASTER_SITES=	${MASTER_SITE_APACHE:=cassandra/${CASSANDRA_VER:C/-.*//}/}
MASTER_SITES=	http://archive.apache.org/dist/cassandra/${PKGVERSION_NOREV}/
DISTFILES=	${DISTNAME}-bin${EXTRACT_SUFX}

MAINTAINER=	tonnerre@NetBSD.org
HOMEPAGE=	http://cassandra.apache.org/
COMMENT=	Highly scalable, distributed structured key-value store

LICENSE=	apache-2.0
NO_BUILD=	yes
USE_LANGUAGES=	# none
USE_JAVA=	run
USE_JAVA2=	6
USE_TOOLS+=	pax

PKG_DESTDIR_SUPPORT=	destdir

.include "../../mk/bsd.prefs.mk"

CASSANDRA_VER=	1.2.15
CASSANDRA_HOME=	${PREFIX}/share/cassandra
EGDIR=		${PREFIX}/share/examples/cassandra
DOCDIR=		${PREFIX}/share/doc/cassandra

RCD_SCRIPTS=		cassandra
CASSANDRA_USER?=	cassandra
CASSANDRA_GROUP?=	cassandra
PKG_GROUPS=		${CASSANDRA_GROUP}
PKG_USERS=		${CASSANDRA_USER}:${CASSANDRA_GROUP}
PKG_GROUPS_VARS+=	CASSANDRA_GROUP
PKG_USERS_VARS=		CASSANDRA_USER
PKG_HOME.cassandra=	${CASSANDRA_HOME}
PKG_SHELL.cassandra=	${SH}

# Following line only to unlock PKG_SYSCONFDIR_PERMS
PKG_SYSCONFSUBDIR=		conf
PKG_SYSCONFVAR=			cassandra
PKG_SYSCONFDIR.cassandra=	${CASSANDRA_HOME}/${PKG_SYSCONFSUBDIR}
PKG_SYSCONFDIR_PERMS=		${CASSANDRA_USER} ${CASSANDRA_GROUP} 0755

OWN_DIRS_PERMS+=	${VARBASE}/lib/cassandra ${CASSANDRA_USER} ${CASSANDRA_GROUP} 0751
OWN_DIRS_PERMS+=	${VARBASE}/log/cassandra ${CASSANDRA_USER} ${CASSANDRA_GROUP} 0755

FILES_SUBST+=		JAVA_HOME=${PKG_JAVA_HOME}		\
			CASSANDRA_HOME=${CASSANDRA_HOME}	\
			CASSANDRA_USER=${CASSANDRA_USER}	\
			CASSANDRA_GROUP=${CASSANDRA_GROUP}

EGFILES=		cassandra-env.sh cassandra-rackdc.properties	\
			cassandra-topology.properties cassandra.yaml	\
			commitlog_archiving.properties cqlshrc.sample	\
			log4j-server.properties	log4j-tools.properties

DOCFILES=		CHANGES LICENSE NEWS NOTICE README

.for f in ${EGFILES}
CONF_FILES_PERMS+=	${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f} \
			${CASSANDRA_USER} ${CASSANDRA_GROUP} 0644
.endfor

INSTALLATION_DIRS+=	${CASSANDRA_HOME} ${EGDIR} ${DOCDIR}

CHECK_INTERPRETER_SKIP+=share/cassandra/interface/cassandra.thrift
CHECK_INTERPRETER_SKIP+=share/cassandra/pylib/setup.py
CHECK_INTERPRETER_SKIP+=share/cassandra/tools/bin/token-generator

do-install:
.for d in ${WORK_DIRS}
		${RM} -rf ${WRKSRC}/${d}
.endfor

.for f in ${DOCFILES}
		${INSTALL_DATA} ${WRKSRC}/${f}.txt ${DESTDIR}${DOCDIR}/${f}
		${RM} -f ${WRKSRC}/${f}.txt
.endfor

.for f in ${EGFILES}
		${INSTALL_DATA} ${WRKSRC}/conf/${f} ${DESTDIR}${EGDIR}/${f}
.endfor

	${FIND} ${WRKSRC} -name \*.exe -type f -print | ${XARGS} ${RM} -f
	${FIND} ${WRKSRC} -name \*.bat -type f -print | ${XARGS} ${RM} -f

	cd ${WRKSRC} && \
	  ${PAX} -rw -pm bin interface javadoc lib pylib tools \
	  ${DESTDIR}${CASSANDRA_HOME}

	${FIND} ${DESTDIR}${CASSANDRA_HOME} -type d -print |	\
		${XARGS} ${CHMOD} ${PKGDIRMODE}
	${FIND} ${DESTDIR}${CASSANDRA_HOME} -type f -print |	\
		${XARGS} ${CHMOD} ${SHAREMODE}
	${FIND} ${DESTDIR}${CASSANDRA_HOME}/bin -type f -print |	\
		${XARGS} ${CHMOD} ${BINMODE}
	${FIND} ${DESTDIR}${CASSANDRA_HOME} -type f -name \*.sh -print |	\
		${XARGS} ${CHMOD} ${BINMODE}

.include "../../lang/python/application.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
