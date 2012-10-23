# $NetBSD: Makefile,v 1.14 2012/10/23 17:18:40 asau Exp $
#

DISTNAME=	nbtscan-1.5.1
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.inetcat.net/software/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.inetcat.net/software/nbtscan.html
COMMENT=	NetBIOS name network scanner

GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}a
BUILD_TARGET=	nbtscan

INSTALLATION_DIRS=	bin share/doc/nbtscan

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nbtscan ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/nbtscan

.include "../../mk/bsd.pkg.mk"
