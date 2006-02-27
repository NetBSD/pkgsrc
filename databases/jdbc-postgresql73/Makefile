# $NetBSD: Makefile,v 1.1.1.1 2006/02/27 14:47:08 abs Exp $
#

DISTNAME=		${JARDIST}
PKGNAME=		jdbc-postgresql73-${PGBUILD}
DISTFILES+=		${JARDIST}
CATEGORIES=		databases
MASTER_SITES=		http://jdbc.postgresql.org/download/

MAINTAINER=		abs@NetBSD.org
HOMEPAGE=		http://jdbc.postgresql.org/
COMMENT=		PostgreSQL 7.3 JDBC3 driver

PGBUILD=		113
JARDIST=		pg73jdbc3.jar
JARFILE=		postgresql73.jar
EXTRACT_ONLY=           

USE_JAVA2=		1.4
NO_BUILD=       	YES

PLIST_SUBST+=		JARFILE=${JARFILE:Q}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/java
	${INSTALL_DATA} ${DISTDIR}/${JARDIST} ${PREFIX}/lib/java/${JARFILE}

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
