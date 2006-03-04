# $NetBSD: Makefile,v 1.11 2006/03/04 21:30:21 jlam Exp $
#

DISTNAME=	nbtscan-1.5.1
CATEGORIES=	net
MASTER_SITES=	http://www.inetcat.org/software/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.inetcat.org/software/nbtscan.html
COMMENT=	NetBIOS name network scanner

GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}a
BUILD_TARGET=	nbtscan

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nbtscan ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/nbtscan
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/nbtscan

.include "../../mk/bsd.pkg.mk"
