# $NetBSD: Makefile,v 1.1.1.1 2009/11/08 07:47:49 wiz Exp $
#

DISTNAME=	JBidwatcher-2.1pre4
CATEGORIES=	misc
MASTER_SITES=	http://www.jbidwatcher.com/alpha/
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
	${ECHO} "${PKG_JAVA_HOME}/bin/java -jar ${PREFIX}/libexec/JBidwatcher/${DISTNAME}.jar"' "$$@"' >> ${WRKSRC}/JBidwatcher

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/JBidwatcher ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}.jar \
		${DESTDIR}${PREFIX}/libexec/JBidwatcher

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
