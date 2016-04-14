# $NetBSD: Makefile,v 1.1.1.1 2016/04/14 21:58:09 abs Exp $

DISTNAME=	tvnjviewer-2.7.2-bin
PKGNAME=	${DISTNAME:S:-bin::}
CATEGORIES=	net
MASTER_SITES=	http://www.tightvnc.com/download/2.7.2/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tightvnc.com/doc/java/README.txt
COMMENT=	JAVA VNC viewer
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none
USE_JAVA=	run
INSTALLATION_DIRS=	bin lib/java/tvnjviewer share/doc/tvnjviewer

do-build:
	${ECHO} "#!/bin/sh" >${WRKSRC}/tvnjviewer
	${ECHO} "exec java -jar ${PREFIX}/lib/java/tvnjviewer/tightvnc-jviewer.jar \"\$$@\"" >>${WRKSRC}/tvnjviewer

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tvnjviewer ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/tightvnc-jviewer.jar ${DESTDIR}${PREFIX}/lib/java/tvnjviewer
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DESTDIR}${PREFIX}/share/doc/tvnjviewer
	${INSTALL_DATA} ${WRKSRC}/viewer-applet-example.html ${DESTDIR}${PREFIX}/share/doc/tvnjviewer

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
