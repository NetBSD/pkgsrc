# $NetBSD: Makefile,v 1.14 2006/03/16 22:46:30 wiz Exp $
#

DISTNAME=	javadeps-1.1
PKGREVISION=	1
CATEGORIES=	devel java
MASTER_SITES=	http://www.vet.com.au/java/javadeps/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.vet.com.au/java/javadeps/
COMMENT=	Automatic dependency tracking for Java

WRKSRC=		${WRKDIR}/JavaDeps-1.1
USE_JAVA=	run

INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC}; for file in jdeps; do				\
		${SED}	-e "s|@PREFIX@|${PREFIX}|g"			\
			-e "s|@JAVA_HOME@|${PKG_JAVA_HOME}|g"		\
			$${file} > $${file}.fixed;			\
		${MV} -f $${file}.fixed $${file};			\
	done

do-install:
	${CP} ${WRKSRC}/jdeps ${PREFIX}/bin
	${INSTALL_PROGRAM_DIR} ${PREFIX}/share/jdeps
	${CP} ${WRKSRC}/jdeps.jar ${PREFIX}/share/jdeps/jdeps.jar
	${INSTALL_PROGRAM_DIR} ${PREFIX}/share/doc/jdeps
	cd ${WRKSRC}/doc && ${PAX} -rw -pe . ${PREFIX}/share/doc/jdeps
	${CHOWN} -R ${BINOWN}:${BINGRP} ${PREFIX}/share/jdeps ${PREFIX}/share/doc/jdeps

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
