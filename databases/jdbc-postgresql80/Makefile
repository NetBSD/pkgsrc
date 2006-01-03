# $NetBSD: Makefile,v 1.1.1.1 2006/01/03 17:54:09 abs Exp $
#

DISTNAME=		postgresql-jdbc-8.0-314.src
PKGNAME=		jdbc-postgresql80-314
DISTFILES+=		postgresql-jdbc-8.0-314.src.tar.gz
DISTFILES+=		${JARDIST}
CATEGORIES=		databases
MASTER_SITES=		http://jdbc.postgresql.org/download/

MAINTAINER=		abs@NetBSD.org
HOMEPAGE=		http://jdbc.postgresql.org/download/
COMMENT=		PostgreSQL 8.0 JDBC3 driver

JARDIST=		postgresql-8.0-314.jdbc3.jar
JARFILE=		postgresql80.jar
EXTRACT_ONLY=           ${DISTFILES:N*.jar}

USE_JAVA2=		1.4
NO_BUILD=       	YES

EXAMPLEDIR=             share/examples/java/jdbc-postgresql80
DOCDIR=                 share/doc/java/jdbc-postgresql80
PLIST_SUBST+=		JARFILE=${JARFILE:Q}
PLIST_SUBST+=		EXAMPLEDIR=${EXAMPLEDIR:Q}
PLIST_SUBST+=		DOCDIR=${DOCDIR:Q}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/java
	${INSTALL_DATA} ${DISTDIR}/${JARDIST} ${PREFIX}/lib/java/${JARFILE}
	${INSTALL_DATA_DIR} ${PREFIX}/${EXAMPLEDIR}
	${INSTALL_DATA} ${WRKSRC}/example/*.java ${PREFIX}/${EXAMPLEDIR}
	${INSTALL_DATA_DIR} ${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/${DOCDIR}

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
