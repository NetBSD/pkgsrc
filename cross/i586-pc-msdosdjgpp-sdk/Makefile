# $NetBSD: Makefile,v 1.1 2022/12/04 22:37:27 js Exp $

PKGNAME=	cross-i586-pc-msdosdjgpp-sdk-2.05
DISTNAME=	djcrx205
CATEGORIES=	cross
MASTER_SITES=	http://www.delorie.com/pub/djgpp/current/v2/
EXTRACT_SUFX=	.zip

MAINTAINER=	js@NetBSD.org
HOMEPAGE=	https://delorie.com/djgpp/
COMMENT=	DJGPP headers and libraries
LICENSE=	djgpp-license

WRKSRC=		${WRKDIR}

do-build:
	cd ${WRKSRC}/src/stub && ${CC} -O2 -o stubify stubify.c

do-install:
	${MKDIR} ${DESTDIR}${PREFIX}/cross-djgpp/bin
	install -m755 ${WRKSRC}/src/stub/stubify \
		${DESTDIR}${PREFIX}/cross-djgpp/bin/stubify
	${MKDIR} ${DESTDIR}${PREFIX}/cross-djgpp/i586-pc-msdosdjgpp
	cp -R ${WRKSRC}/include ${WRKSRC}/lib \
		${DESTDIR}${PREFIX}/cross-djgpp/i586-pc-msdosdjgpp/

.include "../../mk/bsd.pkg.mk"
