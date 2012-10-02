# $NetBSD: Makefile,v 1.6 2012/10/02 21:25:19 asau Exp $
#

DISTNAME=	mysql-connector-java-5.0.8
PKGNAME=	${DISTNAME:S/mysql-connector-java/jdbc-mysql/}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_MYSQL:=Connector-J/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mysql.com/products/connector/j/
COMMENT=	MySQL 5.0 JDBC driver

USE_JAVA=	run
USE_JAVA2=	1.5
NO_BUILD=	yes

DOCDIR=		share/doc/${PKGBASE}
PLIST_SUBST+=	DISTNAME=${DISTNAME:Q}

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/lib/java
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/${DOCDIR}

	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}-bin.jar \
		${DESTDIR}${PREFIX}/lib/java
	${INSTALL_DATA} ${WRKSRC}/docs/README ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/README.txt ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/connector-j.html ${DESTDIR}${PREFIX}/${DOCDIR}

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
