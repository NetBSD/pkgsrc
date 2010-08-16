# $NetBSD: Makefile,v 1.5 2010/08/16 21:39:34 wiz Exp $
#

DISTNAME=	JBidwatcher-2.1.1
CATEGORIES=	misc
MASTER_SITES=	http://www.jbidwatcher.com/download/
EXTRACT_SUFX=	.jar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.jbidwatcher.com/
COMMENT=	eBay sniping, bidding and monitoring software
#LICENSE=	Creative Commons BY-NC-SA

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}
USE_JAVA=	run
INSTALLATION_DIRS=      bin libexec/JBidwatcher

do-build:
	${ECHO} "#!/bin/sh" > ${WRKSRC}/JBidwatcher
	${ECHO} "${PKG_JAVA_HOME}/bin/java -Xmx512m -jar ${PREFIX}/libexec/JBidwatcher/${DISTNAME}.jar"' "$$@"' >> ${WRKSRC}/JBidwatcher

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/JBidwatcher ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}.jar \
		${DESTDIR}${PREFIX}/libexec/JBidwatcher

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
