# $NetBSD: Makefile,v 1.3 2003/12/30 17:21:55 cjep Exp $
#

DISTNAME=	emech-2.8.4
CATEGORIES=	chat
MASTER_SITES=	http://www.energymech.net/files/

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	http://www.energymech.net/
COMMENT=	IRC bot written in C

HAS_CONFIGURE=	YES

do-configure:
	cd ${WRKSRC} && ${ECHO} "\n\n\n\n\n\n\n\n\n\n"|./configure

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mech ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/genuser ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/example/emech
	${INSTALL_DATA} ${WRKSRC}/sample.set \
	    ${PREFIX}/share/example/emech/
	${INSTALL_DATA} ${WRKSRC}/mech.help \
	    ${PREFIX}/share/example/emech/

.include "../../mk/bsd.pkg.mk"
