# $NetBSD: Makefile,v 1.6 2005/09/28 16:51:32 rillig Exp $

DISTNAME=	skkfep0.86c
PKGNAME=	skkfep-0.86c
CATEGORIES=	japanese inputmethod
MASTER_SITES=	ftp://ei5nazha.yz.yamagata-u.ac.jp/skkfep/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://ei5nazha.yz.yamagata-u.ac.jp/~aito/aito-soft.html
COMMENT=	Terminal based SKK-like Kana-to-Kanji FrontEnd Processor

BUILD_DEFS+=	USE_INET6

WRKSRC=		${WRKDIR}/skkfep
NO_CONFIGURE=	yes
MAKE_ENV=	MAKE_FLAGS='EXECBASE=${LOCALBASE} CC=${CC}'

DESCR_SRC=	${WRKDIR}/DESCR
INSTALL_FILE=	${WRKDIR}/INSTALL

INSTALLATION_DIRS=	bin man/man1

post-build:
	${SED} 's#@PKGBASE@#${LOCALBASE}#g' ${PKGDIR}/DESCR	>${DESCR_SRC}
	${SED} 's#@PKGBASE@#${LOCALBASE}#g' ${PKGDIR}/INSTALL	>${INSTALL_FILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/skkfep ${PREFIX}/bin/skkfep
	${INSTALL_MAN} ${WRKSRC}/skkfep.1 ${PREFIX}/man/man1/skkfep.1
	${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
