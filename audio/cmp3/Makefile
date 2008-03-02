# $NetBSD: Makefile,v 1.26 2008/03/02 06:10:31 jlam Exp $
#

DISTNAME=	cmp3-2.0pre6
PKGNAME=	cmp3-2.0.p6
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cmp3/}

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://cmp3.sourceforge.net/
COMMENT=	Curses based frontend to mpg123

DEPENDS+=	mpg123-[0-9]*:../../audio/mpg123
DEPENDS+=	vorbis-tools-[0-9]*:../../audio/vorbis-tools

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/cmp3-kenrevs
USE_TOOLS+=		gmake
INCOMPAT_CURSES=	NetBSD-1.5*-* NetBSD-1.6[-_.]*-*
INCOMPAT_CURSES+=	NetBSD-1.6[A-Z]-* NetBSD-1.6Z[A-H]*-*

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cmp3 ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/rnmp3 ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/cmp3
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}${PREFIX}/share/doc/cmp3
	${INSTALL_DATA} ${WRKSRC}/cmp3rc \
		${DESTDIR}${PREFIX}/share/doc/cmp3/sample.cmp3rc

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
