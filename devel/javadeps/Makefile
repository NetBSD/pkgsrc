# $NetBSD: Makefile,v 1.19 2026/11/26 00:57:15 gdt Exp $
#

DISTNAME=	javadeps-1.1
PKGREVISION=	1
CATEGORIES=	devel java
#MASTER_SITES=	http://www.vet.com.au/java/javadeps/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.vet.com.au/java/javadeps/
COMMENT=	Automatic dependency tracking for Java
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	destdir

WRKSRC=		${WRKDIR}/JavaDeps-1.1
USE_JAVA=	run
USE_TOOLS+=	pax

INSTALLATION_DIRS=	bin share/doc/jdeps share/jdeps

do-build:
	cd ${WRKSRC}; for file in jdeps; do				\
		${SED}	-e "s|@PREFIX@|${PREFIX}|g"			\
			-e "s|@JAVA_HOME@|${PKG_JAVA_HOME}|g"		\
			$${file} > $${file}.fixed;			\
		${MV} -f $${file}.fixed $${file};			\
	done

do-install:
	${INSTALL} ${WRKSRC}/jdeps ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/jdeps.jar ${DESTDIR}${PREFIX}/share/jdeps/jdeps.jar
	cd ${WRKSRC}/doc && pax -rw -pp . ${DESTDIR}${PREFIX}/share/doc/jdeps
	${CHOWN} -R ${BINOWN}:${BINGRP} \
		${DESTDIR}${PREFIX}/share/jdeps ${DESTDIR}${PREFIX}/share/doc/jdeps

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
