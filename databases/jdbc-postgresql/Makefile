# $NetBSD: Makefile,v 1.1.1.1 2000/01/19 05:36:13 jwise Exp $
#

DISTNAME=		postgresql-6.5.3
PKGNAME=		jdbc-${DISTNAME}
WRKSRC=			${WRKDIR}/${DISTNAME}/src/interfaces/jdbc
CATEGORIES=		databases
MASTER_SITES=		ftp://ftp.PostgreSQL.org/pub/ \
			ftp://ftp.sunsite.auc.dk/mirrors/www.postgresql.org/pub/ \
			ftp://ftp.jaist.ac.jp/pub/dbms/postgres95/

MAINTAINER=		jwise@netbsd.org
HOMEPAGE=		http://www.PostgreSQL.ORG/

# No, we don't depend on postgresql.  This code base stands alone.

# checksum shared distfile, since we need not have built postgresql
MD5_FILE=		${PKGSRCDIR}/databases/postgresql/files/md5

.include "../../mk/bsd.prefs.mk"

USE_GMAKE=
USE_JAVA=
NO_CONFIGURE=
NO_PATCH=
ALL_TARGET=		jdbc1 doc
MAKE_ENV+=		CLASSPATH=${CLASSPATH}:.

HELP_FILES=		README README_6.3 Implementation CHANGELOG

do-install:
	${INSTALL_DATA} ${WRKSRC}/postgresql.jar ${PREFIX}/lib
	${MKDIR} ${PREFIX}/share/examples/jdbc-postgresql
	${INSTALL_DATA} ${WRKSRC}/example/*.java ${PREFIX}/share/examples/jdbc-postgresql
	${MKDIR} ${PREFIX}/share/doc/jdbc-postgresql
	${MKDIR} ${PREFIX}/share/doc/jdbc-postgresql/api
.for X in ${HELP_FILES}
	${INSTALL_DATA} ${WRKSRC}/${X} ${PREFIX}/share/doc/jdbc-postgresql
.endfor
	${INSTALL_DATA} ${WRKSRC}/*.html ${PREFIX}/share/doc/jdbc-postgresql/api

.include "../../mk/bsd.pkg.mk"

EXTRACT_CMD += ${DISTNAME}/src/interfaces/jdbc
