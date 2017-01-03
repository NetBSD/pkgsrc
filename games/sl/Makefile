# $NetBSD: Makefile,v 1.22 2017/01/03 22:13:11 roy Exp $
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

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/ja_JP.EUC/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sl ${DESTDIR}${PREFIX}/bin/sl
	${INSTALL_MAN} ${WRKSRC}/sl.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/sl.1.ja \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/ja_JP.EUC/man1/sl.1

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
