# $NetBSD: Makefile,v 1.18 2004/10/03 00:13:05 tv Exp $
#

DISTNAME=	cmp3-2.0pre5
PKGNAME=	cmp3-2.0.p5
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.personal.psu.edu/users/n/k/nkk104/cmp3/

MAINTAINER=	rxg@ms25.url.com.tw
HOMEPAGE=	http://www.personal.psu.edu/nkk104/cmp3/
COMMENT=	Curses based frontend to mpg123

DEPENDS+=	mpg123-[0-9]*:../../audio/mpg123

WRKSRC=			${WRKDIR}/cmp3
USE_BUILDLINK3=		YES
USE_GNU_TOOLS+=		make
INCOMPAT_CURSES=	NetBSD-1.5* NetBSD-1.6[-_.]*
INCOMPAT_CURSES+=	NetBSD-1.6[A-Z]-* NetBSD-1.6Z[A-H]*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cmp3 ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/rnmp3 ${PREFIX}/bin
	@${INSTALL_DATA_DIR} ${PREFIX}/share/doc/cmp3
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/cmp3
	${INSTALL_DATA} ${WRKSRC}/cmp3rc ${PREFIX}/share/doc/cmp3/sample.cmp3rc

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
