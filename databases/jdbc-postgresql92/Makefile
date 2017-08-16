# $NetBSD: Makefile,v 1.3 2017/08/16 20:21:06 wiz Exp $
#

DISTNAME=		postgresql-jdbc-9.2-${PGBUILD}.src
PKGNAME=		jdbc-postgresql92-${PGBUILD}
DISTFILES+=		${DISTNAME}.tar.gz ${JARDIST}
CATEGORIES=		databases
MASTER_SITES=		https://jdbc.postgresql.org/download/

MAINTAINER=		ryoon@NetBSD.org
HOMEPAGE=		https://jdbc.postgresql.org/
COMMENT=		PostgreSQL 9.2 JDBC4 driver

PGBUILD=		1002
JARDIST=		postgresql-9.2-${PGBUILD}.jdbc4.jar
JARFILE=		postgresql92.jar
EXTRACT_ONLY=		${DISTFILES:N*.jar}

INSTALLATION_DIRS=	lib/java ${DOCDIR}

USE_JAVA=		run
USE_JAVA2=		6
NO_BUILD=		YES

DOCDIR=                 share/doc/java/${PKGBASE}
PLIST_SUBST+=		JARFILE=${JARFILE:Q}
PLIST_SUBST+=		DOCDIR=${DOCDIR:Q}

do-install:
	${INSTALL_DATA} ${DISTDIR}/${JARDIST} \
		${DESTDIR}${PREFIX}/lib/java/${JARFILE}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/${DOCDIR}

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
