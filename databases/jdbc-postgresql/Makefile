# $NetBSD: Makefile,v 1.13 2001/10/15 17:13:57 jwise Exp $
#

DISTNAME=		postgresql-7.1.3
PKGNAME=		jdbc-${DISTNAME}
WRKSRC=			${WRKDIR}/${DISTNAME}/src/interfaces/jdbc
CATEGORIES=		databases
MASTER_SITES=		ftp://ftp.PostgreSQL.org/pub/ \
			ftp://ftp.sunsite.auc.dk/mirrors/www.postgresql.org/pub/ \
			ftp://ftp.jaist.ac.jp/pub/dbms/postgres95/

MAINTAINER=		jwise@netbsd.org
HOMEPAGE=		http://www.PostgreSQL.ORG/
COMMENT=		100% Java JDBC driver for PostgreSQL

# No, we don't depend on postgresql.  This code base stands alone.
DEPENDS+=		jakarta-ant-[0-9]*:../../devel/jakarta-ant

EXTRACT_ELEMENTS=	${DISTNAME}/src/interfaces/jdbc

.include "../../mk/bsd.prefs.mk"

USE_GMAKE=
USE_JAVA=
NO_CONFIGURE=
CLASSPATH:=		${CLASSPATH}:.

HELP_FILES=		README Implementation CHANGELOG

pre-build:
	${ECHO} "VERSION=7.1.3" > ${WRKSRC}/../../../src/Makefile.global
	${ECHO} "ANT=${LOCALBASE}/bin/ant" >> ${WRKSRC}/../../../src/Makefile.global
	${ECHO} "top_srcdir=." >> ${WRKSRC}/../../../src/Makefile.global
	${ECHO} "DEF_PGPORT=5432" >> ${WRKSRC}/../../../src/Makefile.global

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/java
	${INSTALL_DATA} ${WRKSRC}/jars/postgresql.jar ${PREFIX}/lib/java
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/java/jdbc-postgresql
	${INSTALL_DATA} ${WRKSRC}/example/*.java ${PREFIX}/share/examples/java/jdbc-postgresql
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/java/jdbc-postgresql
.for X in ${HELP_FILES}
	${INSTALL_DATA} ${WRKSRC}/${X} ${PREFIX}/share/doc/java/jdbc-postgresql
.endfor

.include "../../mk/bsd.pkg.mk"
