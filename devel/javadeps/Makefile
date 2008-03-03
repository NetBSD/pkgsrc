# $NetBSD: Makefile,v 1.15 2008/03/03 17:45:35 jlam Exp $
#

DISTNAME=	javadeps-1.1
PKGREVISION=	1
CATEGORIES=	devel java
MASTER_SITES=	http://www.vet.com.au/java/javadeps/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.vet.com.au/java/javadeps/
COMMENT=	Automatic dependency tracking for Java

PKG_DESTDIR_SUPPORT=	destdir

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
	${CP} ${WRKSRC}/jdeps ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${PREFIX}/share/jdeps
	${CP} ${WRKSRC}/jdeps.jar ${DESTDIR}${PREFIX}/share/jdeps/jdeps.jar
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${PREFIX}/share/doc/jdeps
	cd ${WRKSRC}/doc && ${PAX} -rw -pe . ${DESTDIR}${PREFIX}/share/doc/jdeps
	${CHOWN} -R ${BINOWN}:${BINGRP} \
		${DESTDIR}${PREFIX}/share/jdeps ${PREFIX}/share/doc/jdeps

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
