# $NetBSD: Makefile,v 1.4 2012/05/12 05:38:00 adam Exp $

DISTNAME=	udns-0.2
CATEGORIES=	net
MASTER_SITES=	http://www.corpit.ru/mjt/udns/

MAINTAINER=	eric@cirr.com
HOMEPAGE=	http://www.corpit.ru/mjt/udns.html
COMMENT=	Lightweight DNS resolver supporting asynchronous queries
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

USE_LIBTOOL=		yes
HAS_CONFIGURE=		yes
INSTALLATION_DIRS=	bin lib include ${PKGMANDIR}/man1 ${PKGMANDIR}/man3

.include "options.mk"

do-install:
	${LIBTOOL} --mode=install ${INSTALL_LIB} \
		${WRKSRC}/libudns.la ${DESTDIR}${PREFIX}/lib
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} \
		${WRKSRC}/dnsget ${DESTDIR}${PREFIX}/bin
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} \
		${WRKSRC}/rblcheck ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/udns.h ${DESTDIR}${PREFIX}/include
	${INSTALL_MAN} ${WRKSRC}/udns.3 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man3
	${INSTALL_MAN} ${WRKSRC}/dnsget.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/rblcheck.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
