# $NetBSD: Makefile,v 1.2 2002/12/25 23:03:13 wiz Exp $
#

DISTNAME=	pircbot-0.9.11
CATEGORIES=	chat
MASTER_SITES=	http://www.jibble.org/files/
EXTRACT_SUFX=	.zip

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.jibble.org/pircbot.php
COMMENT=	Java IRC Bot Framework

USE_BUILDLINK2=	YES
USE_JAVA=	run
NO_PATCH=	YES
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
	    ${PAX} -rwpppm . ${PREFIX}/share/doc/java/pircbot

.include "../../mk/java.mk"
.include "../../mk/bsd.pkg.mk"
