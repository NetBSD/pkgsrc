# $NetBSD: Makefile,v 1.4 2006/01/07 21:39:49 rillig Exp $
#

DISTNAME=	emech-2.8.4
CATEGORIES=	chat
MASTER_SITES=	http://www.energymech.net/files/

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	http://www.energymech.net/
COMMENT=	IRC bot written in C

HAS_CONFIGURE=	YES

# The ./configure script is interactive, but selects the default values
# when given no input.
do-configure:
	cd ${WRKSRC} && ./configure </dev/null

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mech ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/genuser ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/example/emech
	${INSTALL_DATA} ${WRKSRC}/sample.set \
	    ${PREFIX}/share/example/emech/
	${INSTALL_DATA} ${WRKSRC}/mech.help \
	    ${PREFIX}/share/example/emech/

.include "../../mk/bsd.pkg.mk"
