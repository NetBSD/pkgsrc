# $NetBSD: Makefile,v 1.23 2020/03/26 12:46:58 nia Exp $
#

DISTNAME=	sl-5.02
PKGREVISION=	3
CATEGORIES=	games
MASTER_SITES=	-https://github.com/mtoyoda/sl/archive/${PKGVERSION_NOREV}${EXTRACT_SUFX}

MAINTAINER=	minoura@NetBSD.org
HOMEPAGE=	http://www.tkl.iis.u-tokyo.ac.jp/~toyoda/
COMMENT=	Animated SL that runs across the terminal when you type `sl'

FAKE_NCURSES=	yes

DIST_SUBDIR=	${PKGNAME_NOREV}
BUILD_TARGET=	sl

MAKE_FLAGS+=	CC=${CC:Q}
MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/ja_JP.EUC/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sl ${DESTDIR}${PREFIX}/bin/sl
	${INSTALL_MAN} ${WRKSRC}/sl.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/sl.1.ja \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/ja_JP.EUC/man1/sl.1

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
