# $NetBSD: Makefile,v 1.1.1.1 1999/12/24 03:21:09 itohy Exp $

DISTNAME=	skkfep0.86c
PKGNAME=	skkfep-0.86c
WRKSRC=		${WRKDIR}/skkfep
CATEGORIES=	japanese
MASTER_SITES=	ftp://ei5nazha.yz.yamagata-u.ac.jp/skkfep/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://ei5nazha.yz.yamagata-u.ac.jp/~aito/aito-soft.html

NO_CONFIGURE=
MAKE_ENV=	MAKE_FLAGS='EXECBASE=${LOCALBASE} CC=${CC}'

DESCR_SRC=	${WRKDIR}/DESCR
INSTALL_FILE=	${WRKDIR}/INSTALL
MESSAGE_FILE=	${WRKDIR}/MESSAGE

post-build:
	${SED} 's#@PKGBASE@#${LOCALBASE}#g' ${PKGDIR}/DESCR	>${DESCR_SRC}
	${SED} 's#@PKGBASE@#${LOCALBASE}#g' ${PKGDIR}/INSTALL	>${INSTALL_FILE}
	${SED} 's#@PKGBASE@#${LOCALBASE}#g' ${PKGDIR}/MESSAGE	>${MESSAGE_FILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/skkfep ${PREFIX}/bin/skkfep
	${INSTALL_MAN} ${WRKSRC}/skkfep.1 ${PREFIX}/man/man1/skkfep.1
	${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
