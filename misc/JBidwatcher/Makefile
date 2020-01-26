# $NetBSD: Makefile,v 1.13 2020/01/26 17:31:42 rillig Exp $
#

DISTNAME=	JBidwatcher-2.1.5
CATEGORIES=	misc
MASTER_SITES=	http://www.jbidwatcher.com/download/
EXTRACT_SUFX=	.jar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.jbidwatcher.com/
COMMENT=	Software for eBay sniping, bidding and monitoring
#LICENSE=	Creative Commons BY-NC-SA Amended

WRKSRC=			${WRKDIR}
USE_JAVA=		run
INSTALLATION_DIRS=	bin libexec/JBidwatcher

do-build:
	${ECHO} "#!/bin/sh" > ${WRKSRC}/JBidwatcher
	${ECHO} "${PKG_JAVA_HOME}/bin/java -Xmx512m -jar ${PREFIX}/libexec/JBidwatcher/${DISTNAME}.jar"' "$$@"' >> ${WRKSRC}/JBidwatcher

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/JBidwatcher ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}.jar \
		${DESTDIR}${PREFIX}/libexec/JBidwatcher

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
