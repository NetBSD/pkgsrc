# $NetBSD: Makefile,v 1.4 2001/09/27 23:17:42 jlam Exp $
# FreeBSD: ports/audio/cmp3/Makefile,v 1.13 2001/02/04 21:12:44 olgeni Exp
#

DISTNAME=	cmp3-2.0pre5
PKGNAME=	cmp3-2.0.p5
CATEGORIES=	audio
MASTER_SITES=	http://www.personal.psu.edu/users/n/k/nkk104/cmp3/

MAINTAINER=	rxg@ms25.url.com.tw
HOMEPAGE=	http://www.personal.psu.edu/nkk104/cmp3/
COMMENT=	ncurses based frontend to mpg123

DEPENDS+=	mpg123-[0-9]*:../../audio/mpg123

WRKSRC=		${WRKDIR}/cmp3

USE_GMAKE=	yes
NEED_NCURSES=	YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cmp3 ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/rnmp3 ${PREFIX}/bin
	@${INSTALL_DATA_DIR} ${PREFIX}/share/doc/cmp3
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/cmp3
	${INSTALL_DATA} ${WRKSRC}/cmp3rc ${PREFIX}/share/doc/cmp3/sample.cmp3rc

.include "../../mk/bsd.pkg.mk"
