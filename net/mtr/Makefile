# $NetBSD: Makefile,v 1.39 2005/02/01 17:02:00 wiz Exp $
#

DISTNAME=	mtr-0.67
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.bitwizard.nl/mtr/

MAINTAINER=	sommerfeld@NetBSD.org
HOMEPAGE=	http://www.bitwizard.nl/mtr/
COMMENT=	Traceroute and ping in a single graphical network diagnostic tool

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		YES
USE_GNU_TOOLS+=		make
USE_BUILDLINK3=		YES
CONFIGURE_ARGS+=	--without-gtk
INSTALLATION_DIRS=	man/man8 sbin

# mtr uses libtermcap by default, but needs wattr_{on,off} from (n)curses,
# so we rewrite -ltermcap to -lncurses (which will be auto-mangled into
# -lcurses on the appropriate platforms).
BUILDLINK_TRANSFORM+=	l:termcap:ncurses

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mtr
	${INSTALL} -c -s -m 4755 -o ${ROOT_USER} -g ${ROOT_GROUP} ${WRKSRC}/mtr ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/mtr.8 ${PREFIX}/man/man8
	${INSTALL_DATA} ${WRKSRC}/SECURITY ${PREFIX}/share/doc/mtr

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
