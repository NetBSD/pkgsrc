# $NetBSD: Makefile,v 1.8 2003/01/24 13:36:17 wiz Exp $
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

USE_BUILDLINK2=		YES
USE_GMAKE=		YES
USE_NCURSES=		# MAX_FORM_COMMAND

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cmp3 ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/rnmp3 ${PREFIX}/bin
	@${INSTALL_DATA_DIR} ${PREFIX}/share/doc/cmp3
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/cmp3
	${INSTALL_DATA} ${WRKSRC}/cmp3rc ${PREFIX}/share/doc/cmp3/sample.cmp3rc

.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
