# $NetBSD: Makefile,v 1.12 2005/06/16 06:58:02 jlam Exp $
#

DISTNAME=	bbmail-0.8.3
CATEGORIES=	mail x11
MASTER_SITES=	http://bbtools.windsofstorm.net/sources/

MAINTAINER=	jschauma@NetBSD.org
HOMEPAGE=	http://bbtools.windsofstorm.net/
COMMENT=	Mailbox monitor (not only) for the blackbox windowmanager

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c++

INSTALLATION_DIRS=	bin man/man1

.include "../../mk/x11.buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bbmail ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/bbmail.1 ${PREFIX}/man/man1/
	${INSTALL_DATA_DIR} ${PREFIX}/share/bbtools/
	${INSTALL_DATA} ${WRKSRC}/data/bbmail.bb ${PREFIX}/share/bbtools/

.include "../../mk/bsd.pkg.mk"
