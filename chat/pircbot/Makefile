# $NetBSD: Makefile,v 1.15 2006/11/10 16:50:54 tv Exp $
#

DISTNAME=	pircbot-0.9.11
PKGREVISION=	1
CATEGORIES=	chat java
MASTER_SITES=	http://www.jibble.org/files/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.jibble.org/pircbot.php
COMMENT=	Java IRC Bot Framework

USE_JAVA=	run
NO_CONFIGURE=	YES
NO_BUILD=	YES

post-extract:
	${FIND} ${WRKSRC} -type d -print | ${XARGS} ${CHMOD} 755
	${FIND} ${WRKSRC} -type f -print | ${XARGS} ${CHMOD} 644

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/java
	${INSTALL_DATA} ${WRKSRC}/pircbot.jar ${PREFIX}/lib/java
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/java/pircbot
	cd ${WRKSRC}/javadocs && \
	    ${PAX} -rw -pp -pm . ${PREFIX}/share/doc/java/pircbot

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
