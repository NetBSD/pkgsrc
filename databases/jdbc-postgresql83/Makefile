# $NetBSD: Makefile,v 1.3 2009/10/20 11:02:55 abs Exp $
#

DISTNAME=		postgresql-jdbc-8.3-${PGBUILD}.src
PKGNAME=		jdbc-postgresql83-${PGBUILD}
DISTFILES+=		${DISTNAME}.tar.gz ${JARDIST}
CATEGORIES=		databases
MASTER_SITES=		http://jdbc.postgresql.org/download/

MAINTAINER=		abs@NetBSD.org
HOMEPAGE=		http://jdbc.postgresql.org/
COMMENT=		PostgreSQL 8.3 JDBC3 driver

PGBUILD=		605
JARDIST=		postgresql-8.3-${PGBUILD}.jdbc3.jar
JARFILE=		postgresql83.jar
EXTRACT_ONLY=           ${DISTFILES:N*.jar}

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	lib/java ${DOCDIR}

USE_JAVA=		run
USE_JAVA2=		1.4
NO_BUILD=       	YES

DOCDIR=                 share/doc/java/${PKGBASE}
PLIST_SUBST+=		JARFILE=${JARFILE:Q}
PLIST_SUBST+=		DOCDIR=${DOCDIR:Q}

do-install:
	${INSTALL_DATA} ${DISTDIR}/${JARDIST} \
		${DESTDIR}${PREFIX}/lib/java/${JARFILE}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/${DOCDIR}

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
