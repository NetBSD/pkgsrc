# $NetBSD: Makefile,v 1.2 2003/06/02 01:19:08 jschauma Exp $

DISTNAME=	skkfep0.86c
PKGNAME=	skkfep-0.86c
WRKSRC=		${WRKDIR}/skkfep
CATEGORIES=	japanese inputmethod
MASTER_SITES=	ftp://ei5nazha.yz.yamagata-u.ac.jp/skkfep/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://ei5nazha.yz.yamagata-u.ac.jp/~aito/aito-soft.html
COMMENT=	Terminal based SKK-like Kana-to-Kanji FrontEnd Processor

BUILD_DEFS+=	USE_INET6

NO_CONFIGURE=
MAKE_ENV=	MAKE_FLAGS='EXECBASE=${LOCALBASE} CC=${CC}'

DESCR_SRC=	${WRKDIR}/DESCR
INSTALL_FILE=	${WRKDIR}/INSTALL

post-build:
	${SED} 's#@PKGBASE@#${LOCALBASE}#g' ${PKGDIR}/DESCR	>${DESCR_SRC}
	${SED} 's#@PKGBASE@#${LOCALBASE}#g' ${PKGDIR}/INSTALL	>${INSTALL_FILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/skkfep ${PREFIX}/bin/skkfep
	${INSTALL_MAN} ${WRKSRC}/skkfep.1 ${PREFIX}/man/man1/skkfep.1
	${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
