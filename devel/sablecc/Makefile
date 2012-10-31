# $NetBSD: Makefile,v 1.12 2012/10/31 11:19:44 asau Exp $
#

DISTNAME=	sablecc-2.16.2
PKGREVISION=	2
CATEGORIES=	devel java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sablecc/}

MAINTAINER=	hag@linnaean.org
HOMEPAGE=	http://sablecc.org/
COMMENT=	Java based Compiler Compiler

USE_JAVA=	run
USE_JAVA2=	yes

INSTALLATION_DIRS=	bin

do-build:
	${SED}	-e 's,@PREFIX@,${PREFIX},g'				\
		-e 's,@JAVA_HOME@,${PKG_JAVA_HOME},g'			\
		< ${FILESDIR}/sablecc > ${WRKDIR}/sablecc

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/sablecc ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/lib/java
	${INSTALL_DATA} ${WRKSRC}/lib/sablecc.jar ${DESTDIR}${PREFIX}/lib/java

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
