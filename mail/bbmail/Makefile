# $NetBSD: Makefile,v 1.1.1.1 2002/06/30 02:07:34 jschauma Exp $
#

DISTNAME=	bbmail-0.8.2
CATEGORIES=	mail x11
MASTER_SITES=	http://bbtools.windsofstorm.net/sources/

MAINTAINER=	jschauma@netbsd.org
HOMEPAGE=	http://bbtools.windsofstorm.net/
COMMENT=	mailbox monitor (not only) for the blackbox windowmanager

GNU_CONFIGURE=	YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bbmail ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/bbmail.1 ${PREFIX}/man/man1/
	${INSTALL_DATA_DIR} ${PREFIX}/share/bbtools/
	${INSTALL_DATA} ${WRKSRC}/data/bbmail.bb ${PREFIX}/share/bbtools/

.include "../../mk/bsd.pkg.mk"
