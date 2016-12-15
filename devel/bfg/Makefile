# $NetBSD: Makefile,v 1.1.1.1 2016/12/15 20:25:04 abs Exp $

DISTNAME=	bfg-1.12.14
CATEGORIES=	devel
MASTER_SITES=	http://repo1.maven.org/maven2/com/madgag/bfg/1.12.14/
EXTRACT_SUFX=	.jar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://rtyley.github.io/bfg-repo-cleaner/
COMMENT=	BFG git Repo-Cleaner
LICENSE=	gnu-gpl-v3

USE_JAVA=	run
USE_JAVA2=	7

INSTALLATION_DIRS=	bin share/${PKGBASE}

do-build:
	printf "#!/bin/sh\n${PKG_JAVA_HOME}/bin/java -jar ${PREFIX}/share/${PKGBASE}/${PKGBASE}.jar \$${1:+\"\$$@\"}\n" > ${WRKDIR}/${PKGBASE}.sh

do-install:
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}.jar ${DESTDIR}${PREFIX}/share/${PKGBASE}/${PKGBASE}.jar
	${INSTALL_SCRIPT} ${WRKDIR}/${PKGBASE}.sh ${DESTDIR}${PREFIX}/bin/${PKGBASE}

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
