# $NetBSD: Makefile,v 1.4 2003/07/17 21:45:43 grant Exp $
#

DISTNAME=	bbmail-0.8.2
CATEGORIES=	mail x11
MASTER_SITES=	http://bbtools.windsofstorm.net/sources/

MAINTAINER=	jschauma@NetBSD.org
HOMEPAGE=	http://bbtools.windsofstorm.net/
COMMENT=	mailbox monitor (not only) for the blackbox windowmanager

GNU_CONFIGURE=	YES
USE_X11=	YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bbmail ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/bbmail.1 ${PREFIX}/man/man1/
	${INSTALL_DATA_DIR} ${PREFIX}/share/bbtools/
	${INSTALL_DATA} ${WRKSRC}/data/bbmail.bb ${PREFIX}/share/bbtools/

.include "../../mk/bsd.pkg.mk"
