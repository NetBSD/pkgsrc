# $NetBSD: Makefile,v 1.21 2026/01/22 08:41:03 wiz Exp $

DISTNAME=	pircbot-1.5.0
CATEGORIES=	chat java
MASTER_SITES=	https://www.jibble.org/files/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.jibble.org/pircbot.php
COMMENT=	Java IRC Bot Framework

USE_JAVA=	run
NO_CONFIGURE=	YES
NO_BUILD=	YES
USE_TOOLS+=	pax

post-extract:
	${FIND} ${WRKSRC} -type d -print | ${XARGS} ${CHMOD} 755
	${FIND} ${WRKSRC} -type f -print | ${XARGS} ${CHMOD} 644

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/lib/java
	${INSTALL_DATA} ${WRKSRC}/pircbot.jar ${DESTDIR}${PREFIX}/lib/java
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/java/pircbot
	cd ${WRKSRC}/javadocs && \
	    pax -rw -pp -pm . ${DESTDIR}${PREFIX}/share/doc/java/pircbot

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
