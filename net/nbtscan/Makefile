# $NetBSD: Makefile,v 1.13 2009/01/25 14:21:13 obache Exp $
#

DISTNAME=	nbtscan-1.5.1
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.inetcat.net/software/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.inetcat.net/software/nbtscan.html
COMMENT=	NetBIOS name network scanner

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}a
BUILD_TARGET=	nbtscan

INSTALLATION_DIRS=	bin share/doc/nbtscan

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nbtscan ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/nbtscan

.include "../../mk/bsd.pkg.mk"
