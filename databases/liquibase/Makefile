# $NetBSD: Makefile,v 1.1 2017/07/31 14:23:05 maya Exp $

VERSION=	3.5.5
PKGNAME=	liquibase-${VERSION}
DISTNAME=	${PKGNAME}-bin
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=liquibase/}
GITHUB_RELEASE=	liquibase-parent-${VERSION}

NO_BUILD=	yes
AUTO_MKDIRS=	yes
WRKSRC=		${WRKDIR}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/liquibase/liquibase/
COMMENT=	Database Change Management
LICENSE=	apache-2.0

USE_JAVA=	run
USE_JAVA2=	6

SUBST_CLASSES+=		javabin
SUBST_STAGE.javabin=	pre-configure
SUBST_FILES.javabin=	liquibase
SUBST_VARS.javabin=	JAVA_BINPREFIX

do-install:
	${INSTALL_DATA} ${WRKSRC}/liquibase.jar ${DESTDIR}${PREFIX}/share/liquibase
	${INSTALL_DATA} ${WRKSRC}/lib/snakeyaml-1.17.jar ${DESTDIR}${PREFIX}/share/liquibase/lib
	${INSTALL_SCRIPT} ${WRKSRC}/liquibase ${DESTDIR}${PREFIX}/bin

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
