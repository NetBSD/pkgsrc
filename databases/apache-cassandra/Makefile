# $NetBSD: Makefile,v 1.1.1.1 2010/04/27 23:12:58 tonnerre Exp $
#

DISTNAME=	apache-cassandra-${CASSANDRA_VER}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_APACHE:=cassandra/${CASSANDRA_VER}/}
DISTFILES=	${DISTNAME}-bin${EXTRACT_SUFX}

MAINTAINER=	tonnerre@NetBSD.org
HOMEPAGE=	http://cassandra.apache.org/
COMMENT=	Highly scalable, distributed structured key-value store

LICENSE=	apache-2.0
NO_BUILD=	yes
USE_LANGUAGES=	# none
USE_JAVA=	run
USE_JAVA2=	1.5
USE_TOOLS+=	pax

PKG_DESTDIR_SUPPORT=	destdir

.include "../../mk/bsd.prefs.mk"

CASSANDRA_VER=	0.6.1
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
PKG_SYSCONFDIR.cassandra= ${CASSANDRA_HOME}/conf
OWN_DIRS+=		${PKG_SYSCONFDIR.cassandra}
FILES_SUBST+=		JAVA_HOME=${PKG_JAVA_HOME}		\
			CASSANDRA_HOME=${CASSANDRA_HOME}	\
			CASSANDRA_USER=${CASSANDRA_USER}	\
			CASSANDRA_GROUP=${CASSANDRA_GROUP}

PRIVATE_EGFILES=	passwd.properties
PUBLIC_EGFILES=		access.properties log4j.properties	\
			log4j-tools.properties storage-conf.xml

DOCFILES=		CHANGES DISCLAIMER LICENSE NEWS NOTICE README

.for f in ${PRIVATE_EGFILES}
CONF_FILES_PERMS+=	${EGDIR}/${f} ${PKG_SYSCONFDIR.cassandra}/${f}	\
			${CASSANDRA_USER} ${CASSANDRA_GROUP} 0640
.endfor

.for f in ${PUBLIC_EGFILES}
CONF_FILES_PERMS+=	${EGDIR}/${f} ${PKG_SYSCONFDIR.cassandra}/${f}	\
			${CASSANDRA_USER} ${CASSANDRA_GROUP} 0644
.endfor

INSTALLATION_DIRS+=	${CASSANDRA_HOME} ${EGDIR} ${DOCDIR}

do-install:
.for d in ${WORK_DIRS}
		${RM} -rf ${WRKSRC}/${d}
.endfor

.for f in ${DOCFILES}
		${INSTALL_DATA} ${WRKSRC}/${f}.txt ${DESTDIR}${DOCDIR}/${f}
		${RM} -f ${WRKSRC}/${f}
.endfor

.for f in ${PRIVATE_EGFILES}
		${INSTALL_DATA} ${WRKSRC}/conf/${f} ${DESTDIR}${EGDIR}/${f}
		${RM} -f ${WRKSRC}/conf/${f}
.endfor

.for f in ${PUBLIC_EGFILES}
		${INSTALL_DATA} ${WRKSRC}/conf/${f} ${DESTDIR}${EGDIR}/${f}
		${RM} -f ${WRKSRC}/conf/${f}
.endfor

	${FIND} ${WRKSRC} -name \*.exe -type f -print | ${XARGS} ${RM} -f
	${FIND} ${WRKSRC} -name \*.bat -type f -print | ${XARGS} ${RM} -f

	cd ${WRKSRC} && ${PAX} -rw -pm . ${DESTDIR}${CASSANDRA_HOME}

	${FIND} ${DESTDIR}${CASSANDRA_HOME} -type d -print |	\
		${XARGS} ${CHMOD} ${PKGDIRMODE}
	${FIND} ${DESTDIR}${CASSANDRA_HOME} -type f -print |	\
		${XARGS} ${CHMOD} ${SHAREMODE}
	${FIND} ${DESTDIR}${CASSANDRA_HOME}/bin -type f -print |	\
		${XARGS} ${CHMOD} ${BINMODE}
	${FIND} ${DESTDIR}${CASSANDRA_HOME} -type f -name \*.sh -print |	\
		${XARGS} ${CHMOD} ${BINMODE}

	${CHOWN} ${CASSANDRA_USER}:${CASSANDRA_GROUP}	\
		${DESTDIR}${CASSANDRA_HOME}/conf

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
