# $NetBSD: Makefile,v 1.9 2017/09/03 08:53:09 wiz Exp $

DISTNAME=	MyGoGrinder-2.3.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mygogrinder/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/mygogrinder/
COMMENT=	Program to solve Go (Weiqi, Baduk) problems
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/MyGoGrinder
USE_LANGUAGES=	# none

USE_JAVA=       run
USE_JAVA2=      yes
USE_TOOLS+=	pax

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/${PKGBASE}
INSTALLATION_DIRS+=	share/doc/${PKGBASE}/docs
INSTALLATION_DIRS+=	share/examples/${PKGBASE}
INSTALLATION_DIRS+=	share/pixmaps

do-build:
	${ECHO} '#!/bin/sh' > ${WRKDIR}/MyGoGrinder.sh
	${ECHO} "cd ${PREFIX}/share/doc/${PKGBASE} && exec ${JAVA_BINPREFIX}-java -jar "'"'"${PREFIX}/share/${PKGBASE}/MyGoGrinder.jar"'" "$$@"' >> ${WRKDIR}/MyGoGrinder.sh

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/MyGoGrinder.sh ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/icons/*.ico ${DESTDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/icons/*.png ${DESTDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/Tag*.txt ${DESTDIR}${PREFIX}/share/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/*.jar ${DESTDIR}${PREFIX}/share/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/"GNU LICENSE v.2 (1991).txt" ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKDIR}/"Xuan-Xuan-Qi-Jing-(problems).zip" ${DESTDIR}${PREFIX}/share/examples/${PKGBASE}
	cd ${WRKSRC}/docs && pax -pp -rw * ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/docs
	${RM} -f ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/docs/Notizen*
	${CHMOD} a-wx ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/*.*
	${CHMOD} a-wx ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/*/*.*
	${CHMOD} a-wx ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/*/*/*.*

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
