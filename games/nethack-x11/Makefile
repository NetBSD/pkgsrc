# $NetBSD: Makefile,v 1.1 1998/08/27 13:15:01 garbled Exp $
#

DISTNAME=		nethack-3.2.2
PKGNAME=		nethack-x11-3.2.2
CATEGORIES=		games x11
MASTER_SITES=		# empty

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.win.tue.nl/games/roguelike/nethack/

DEPENDS+=		nethack-lib-3.2.2:../nethack-lib
DEPENDS+=		xpm-3.4k:../../graphics/xpm

WRKSRC=			../nethack-lib/work/${DISTNAME}
NO_CHECKSUM=		yes
ALL_TARGET=		nethack
INSTALL_TARGET=		binfiles
MAKE_ENV+=		GTYPE=-x11

do-fetch:	#empty
do-extract:
	-@mkdir work
	(cd ../nethack-lib && make clean)
	(cd ../nethack-lib && make configure)
	(cd ${WRKSRC}/src && make clean)

do-clean:
	-@rm -r work

.include "../../mk/bsd.pkg.mk"
