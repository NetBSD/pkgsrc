# $NetBSD: Makefile,v 1.16 2004/03/11 18:19:09 xtraeme Exp $
#

DISTNAME=	cmp3-2.0pre5
PKGNAME=	cmp3-2.0.p5
PKGREVISION=			1
CATEGORIES=	audio
MASTER_SITES=	http://www.personal.psu.edu/users/n/k/nkk104/cmp3/

MAINTAINER=	rxg@ms25.url.com.tw
HOMEPAGE=	http://www.personal.psu.edu/nkk104/cmp3/
COMMENT=	Curses based frontend to mpg123

DEPENDS+=	mpg123-[0-9]*:../../audio/mpg123

WRKSRC=			${WRKDIR}/cmp3
USE_BUILDLINK3=		YES
USE_GNU_TOOLS+=		make
USE_NCURSES=		# MAX_FORM_COMMAND

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cmp3 ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/rnmp3 ${PREFIX}/bin
	@${INSTALL_DATA_DIR} ${PREFIX}/share/doc/cmp3
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/cmp3
	${INSTALL_DATA} ${WRKSRC}/cmp3rc ${PREFIX}/share/doc/cmp3/sample.cmp3rc

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
