# $NetBSD: Makefile,v 1.3 1998/12/31 06:19:38 garbled Exp $

DISTNAME=		nethack-3.2.2
PKGNAME=		nethack-tty-3.2.2
CATEGORIES=		games
MASTER_SITES=		# empty

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.win.tue.nl/games/roguelike/nethack/

DEPENDS+=		nethack-lib-3.2.2:../nethack-lib

WRKSRC=			../nethack-lib/${WRKDIR_BASENAME}/${DISTNAME}
NO_CHECKSUM=		yes
ALL_TARGET=		nethack
INSTALL_TARGET=		binfiles
MAKE_ENV+=		GTYPE=-tty

do-fetch:	#empty
do-extract:
	-@mkdir ${WRKDIR_BASENAME}
	(cd ../nethack-lib && make clean)
	(cd ../nethack-lib && make configure)

.include "../../mk/bsd.pkg.mk"
