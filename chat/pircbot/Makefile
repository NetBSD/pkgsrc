# $NetBSD: Makefile,v 1.9 2004/04/27 22:03:13 snj Exp $
#

DISTNAME=	pircbot-0.9.11
CATEGORIES=	chat java
MASTER_SITES=	http://www.jibble.org/files/
EXTRACT_SUFX=	.zip

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.jibble.org/pircbot.php
COMMENT=	Java IRC Bot Framework

USE_BUILDLINK3=	YES
USE_JAVA=	run
NO_CONFIGURE=	YES
NO_BUILD=	YES

post-extract:
	${FIND} ${WRKSRC} -type d -exec ${CHMOD} 755 {} \;
	${FIND} ${WRKSRC} -type f -exec ${CHMOD} 644 {} \;

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/java
	${INSTALL_DATA} ${WRKSRC}/pircbot.jar ${PREFIX}/lib/java
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/java/pircbot
	cd ${WRKSRC}/javadocs && \
	    ${PAX} -rw -pp -pm . ${PREFIX}/share/doc/java/pircbot

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
