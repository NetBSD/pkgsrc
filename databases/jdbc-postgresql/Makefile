# $NetBSD: Makefile,v 1.6 2001/02/16 14:17:27 wiz Exp $
#

DISTNAME=		postgresql-7.0.3
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

# checksum shared distfile, since we need not have built postgresql
MD5_FILE=		${PKGSRCDIR}/databases/postgresql/files/md5

.include "../../mk/bsd.prefs.mk"

USE_GMAKE=
USE_JAVA=
NO_CONFIGURE=
ALL_TARGET=		jdbc1 doc
CLASSPATH:=		${CLASSPATH}:.

HELP_FILES=		README README_6.3 Implementation CHANGELOG

do-install:
	${MKDIR} ${PREFIX}/lib/java
	${INSTALL_DATA} ${WRKSRC}/postgresql.jar ${PREFIX}/lib/java
	${MKDIR} ${PREFIX}/share/examples/java/jdbc-postgresql
	${INSTALL_DATA} ${WRKSRC}/example/*.java ${PREFIX}/share/examples/java/jdbc-postgresql
	${MKDIR} ${PREFIX}/share/doc/java/jdbc-postgresql
	${MKDIR} ${PREFIX}/share/doc/java/jdbc-postgresql/api
.for X in ${HELP_FILES}
	${INSTALL_DATA} ${WRKSRC}/${X} ${PREFIX}/share/doc/java/jdbc-postgresql
.endfor
	${INSTALL_DATA} ${WRKSRC}/*.html ${PREFIX}/share/doc/java/jdbc-postgresql/api

.include "../../mk/bsd.pkg.mk"

EXTRACT_CMD += ${DISTNAME}/src/interfaces/jdbc
