# $NetBSD: Makefile,v 1.2 2008/01/12 06:57:32 bjs Exp $
#

DISTNAME=	smirk-20080111
CATEGORIES=	chat
MASTER_SITES=	http://ftp.NetBSD.org/pub/NetBSD/misc/bjs/distfiles/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	bjs@NetBSD.org
HOMEPAGE=	${MASTER_SITE_LOCAL}
COMMENT=	Revival of the curses-based Rhapsody IRC client

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_NCURSES=		yes
USE_TOOLS+=		gmake

BUILDLINK_TRANSFORM+=	l:curses:ncurses
HELP_DIR=		${PREFIX}/share/${PKGBASE}
HELP_FILES=		clientcmnds.hlp irccmnds.hlp keys.hlp

do-install:
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/smirk ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${HELP_DIR}
.for fn in ${HELP_FILES}
	${INSTALL_DATA} ${WRKSRC}/help/${fn} ${DESTDIR}${HELP_DIR}
.endfor

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
