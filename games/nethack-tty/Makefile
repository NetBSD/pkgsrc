# $NetBSD: Makefile,v 1.2 1998/08/28 12:56:17 garbled Exp $

DISTNAME=		nethack-3.2.2
PKGNAME=		nethack-tty-3.2.2
CATEGORIES=		games
MASTER_SITES=		# empty

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.win.tue.nl/games/roguelike/nethack/

DEPENDS+=		nethack-lib-3.2.2:../nethack-lib

WRKSRC=			../nethack-lib/work/${DISTNAME}
NO_CHECKSUM=		yes
ALL_TARGET=		nethack
INSTALL_TARGET=		binfiles
MAKE_ENV+=		GTYPE=-tty

do-fetch:	#empty
do-extract:
	@mkdir work
	(cd ../nethack-lib && make clean)
	(cd ../nethack-lib && make configure)

.include "../../mk/bsd.pkg.mk"
