# $NetBSD: Makefile,v 1.6 2003/07/21 16:56:42 martti Exp $
#

DISTNAME=	bbmail-0.8.3
CATEGORIES=	mail x11
MASTER_SITES=	http://bbtools.windsofstorm.net/sources/

MAINTAINER=	jschauma@NetBSD.org
HOMEPAGE=	http://bbtools.windsofstorm.net/
COMMENT=	Mailbox monitor (not only) for the blackbox windowmanager

GNU_CONFIGURE=	YES
USE_X11=	YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bbmail ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/bbmail.1 ${PREFIX}/man/man1/
	${INSTALL_DATA_DIR} ${PREFIX}/share/bbtools/
	${INSTALL_DATA} ${WRKSRC}/data/bbmail.bb ${PREFIX}/share/bbtools/

.include "../../mk/bsd.pkg.mk"
