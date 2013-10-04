# $NetBSD: Makefile,v 1.1 2013/10/04 14:38:49 ryoon Exp $

DISTNAME=	hsqldb_1_8_0_10
PKGNAME=	${DISTNAME:S/hsqldb_/hsqldb18-/:S/_/./g}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hsqldb/}
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://hsqldb.org/
COMMENT=	Relational database management system witten in pure Java
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/hsqldb

USE_JAVA=	run
USE_JAVA2=	yes
USE_TOOLS+=	pax
NO_BUILD=	yes

HSQLDB_DIR=	lib/java/hsqldb18

INSTALLATION_DIRS=	${HSQLDB_DIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/hsqldb.jar \
		${DESTDIR}${PREFIX}/${HSQLDB_DIR}

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
