# $NetBSD: Makefile,v 1.6 2002/02/24 22:36:48 wiz Exp $
#

DISTNAME=	cmp3-2.0pre5
PKGNAME=	cmp3-2.0.p5
CATEGORIES=	audio
MASTER_SITES=	http://www.personal.psu.edu/users/n/k/nkk104/cmp3/

MAINTAINER=	rxg@ms25.url.com.tw
HOMEPAGE=	http://www.personal.psu.edu/nkk104/cmp3/
COMMENT=	curses based frontend to mpg123

DEPENDS+=	mpg123-[0-9]*:../../audio/mpg123

WRKSRC=		${WRKDIR}/cmp3

USE_GMAKE=		YES
# missing: newpad, prefresh, pnoutrefresh, wredrawln, redrawwin
USE_NCURSES=		YES
USE_BUILDLINK_ONLY=	YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cmp3 ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/rnmp3 ${PREFIX}/bin
	@${INSTALL_DATA_DIR} ${PREFIX}/share/doc/cmp3
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/cmp3
	${INSTALL_DATA} ${WRKSRC}/cmp3rc ${PREFIX}/share/doc/cmp3/sample.cmp3rc

.include "../../devel/ncurses/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
