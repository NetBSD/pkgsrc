# $NetBSD: Makefile,v 1.9 2004/06/28 17:02:52 abs Exp $
#

DISTNAME=	javadeps-1.1
CATEGORIES=	devel java
MASTER_SITES=	http://www.vet.com.au/java/javadeps/
EXTRACT_SUFX=	.zip

MAINTAINER=	ben@wongs.net
HOMEPAGE=	http://www.vet.com.au/java/javadeps/
COMMENT=	Automatic dependency tracking for Java

WRKSRC=		${WRKDIR}/JavaDeps-1.1
USE_BUILDLINK3=	# defined
USE_JAVA=	run

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
