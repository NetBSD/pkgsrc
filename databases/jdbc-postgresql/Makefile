# $NetBSD: Makefile,v 1.27 2005/12/09 20:34:08 wiz Exp $
#

DISTNAME=		postgresql-${DIST_VERS}
PKGNAME=		jdbc-${DISTNAME}
CATEGORIES=		databases java
MASTER_SITES?=		http://www.postgresql.org/ftp/source/OLD/v${DIST_VERS}/ \
			ftp://ftp.postgresql.org/pub/source/OLD/v${DIST_VERS}/ \
			ftp://ftp.de.postgresql.org/pub/source/OLD/v${DIST_VERS}/ \
			ftp://ch.postgresql.org/mirror/postgresql/source/OLD/v${DIST_VERS}/ \
			ftp://gd.tuwien.ac.at/db/www.postgresql.org/pub/source/OLD/v${DIST_VERS}/ \
			ftp://looking-glass.usask.ca/pub/postgresql/source/OLD/v${DIST_VERS}/ \
			ftp://ftp.sunsite.auc.dk/mirrors/postgresql/source/OLD/v${DIST_VERS}/ \
			ftp://ftp.jaist.ac.jp/pub/dbms/postgres95/source/OLD/v${DIST_VERS}/

DIST_VERS=		7.3.8
MAINTAINER=		jwise@NetBSD.org
HOMEPAGE=		http://www.postgresql.org/
COMMENT=		100% Java JDBC driver for PostgreSQL

# No, we don't depend on postgresql.  This code base stands alone.
BUILD_DEPENDS+=		apache-ant-[0-9]*:../../devel/apache-ant

EXTRACT_ELEMENTS=	${DISTNAME}/src/interfaces/jdbc

WRKSRC=			${WRKDIR}/${DISTNAME}/src/interfaces/jdbc
USE_TOOLS+=		gmake

EXAMPLEDIR=		${PREFIX}/share/examples/java/jdbc-postgresql
DOCDIR=			${PREFIX}/share/doc/java/jdbc-postgresql

do-configure:
	( ${ECHO} "VERSION=		${DIST_VERS}";			\
	  ${ECHO} "ANT=			${LOCALBASE}/bin/ant";		\
	  ${ECHO} "DEF_PGPORT=		5432";				\
	  ${ECHO} "srcdir=		.";				\
	) > ${WRKSRC}/../../../src/Makefile.global

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/java
	${INSTALL_DATA} ${WRKSRC}/jars/postgresql.jar ${PREFIX}/lib/java
	${INSTALL_DATA_DIR} ${EXAMPLEDIR}
	${INSTALL_DATA} ${WRKSRC}/example/*.java ${EXAMPLEDIR}
	${INSTALL_DATA} ${WRKSRC}/jars/postgresql-examples.jar ${EXAMPLEDIR}
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
