# $NetBSD: Makefile,v 1.17 2008/05/26 02:13:16 joerg Exp $
#

DISTNAME=	pircbot-0.9.11
PKGREVISION=	1
CATEGORIES=	chat java
MASTER_SITES=	http://www.jibble.org/files/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.jibble.org/pircbot.php
COMMENT=	Java IRC Bot Framework

PKG_DESTDIR_SUPPORT=	user-destdir

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
