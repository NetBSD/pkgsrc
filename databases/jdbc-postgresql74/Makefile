# $NetBSD: Makefile,v 1.3 2004/10/10 16:19:18 jdolecek Exp $
#

DIST_VERS=		7.4.5
DISTNAME=		postgresql-${DIST_VERS}
PKGNAME=		jdbc-${DISTNAME}
CATEGORIES=		databases java
MASTER_SITES?=		http://www.postgresql.org/ftpsite/source/v${DIST_VERS}/ \
			ftp://ftp.postgresql.org/pub/source/v${DIST_VERS}/ \
			ftp://ftp.de.postgresql.org/pub/source/v${DIST_VERS}/ \
			ftp://ch.postgresql.org/mirror/postgresql/source/v${DIST_VERS}/ \
			ftp://gd.tuwien.ac.at/db/www.postgresql.org/pub/source/v${DIST_VERS}/ \
			ftp://looking-glass.usask.ca/pub/postgresql/source/v${DIST_VERS}/ \
			ftp://ftp.sunsite.auc.dk/mirrors/postgresql/source/v${DIST_VERS}/ \
			ftp://ftp.jaist.ac.jp/pub/dbms/postgres95/source/v${DIST_VERS}/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jwise@NetBSD.org
HOMEPAGE=		http://www.postgresql.org/
COMMENT=		Pure Java JDBC driver for PostgreSQL 7.4.x

# No, we don't depend on postgresql.  This code base stands alone.
BUILD_DEPENDS+=		apache-ant-[0-9]*:../../devel/apache-ant

EXTRACT_ELEMENTS=	${DISTNAME}/src/interfaces/jdbc

WRKSRC=			${WRKDIR}/${DISTNAME}/src/interfaces/jdbc
USE_GNU_TOOLS+=		make

EXAMPLEDIR=		${PREFIX}/share/examples/java/jdbc-postgresql
DOCDIR=			${PREFIX}/share/doc/java/jdbc-postgresql

do-configure:
	( ${ECHO} "VERSION=		${DIST_VERS}";			\
	  ${ECHO} "ANT=			${LOCALBASE}/bin/ant";		\
	  ${ECHO} "DEF_PGPORT=		5432";				\
	  ${ECHO} "srcdir=		.";				\
	) > ${WRKSRC}/../../../src/Makefile.global
	${SED}  -e "s:@FULLVERSION@:${DIST_VERS}:" \
		-e "s:@MAJOR@:${DIST_VERS:C/\..*//}:" \
		-e "s:@MINOR@:${DIST_VERS:C/[0-9]*\.//:C/\..*//}:" \
	${FILESDIR}/build.properties > ${WRKSRC}/build.properties

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
