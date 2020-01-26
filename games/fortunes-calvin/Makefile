# $NetBSD: Makefile,v 1.10 2020/01/26 17:31:14 rillig Exp $
#

DISTNAME=	fortunes-calvin-0.2
CATEGORIES=	games
MASTER_SITES=	http://www.netmeister.org/apps/
EXTRACT_SUFX=	.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.netmeister.org/misc.html
COMMENT=	Fortunes from the famous Calvin & Hobbes comic strips

BUILD_DEPENDS+=	fortune-strfile-[0-9]*:../../games/fortune-strfile

DIST_SUBDIR=	${PKGNAME_NOREV}nb1
STRFILE=	${LOCALBASE}/bin/strfile
WRKSRC=		${WRKDIR}

do-build:
	${STRFILE} ${WRKDIR}/${DISTNAME}

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/games/fortune/
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME} \
		${DESTDIR}${PREFIX}/share/games/fortune/calvin
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}.dat \
		${DESTDIR}${PREFIX}/share/games/fortune/calvin.dat

.include "../../mk/bsd.pkg.mk"
