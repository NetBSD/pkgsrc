# $NetBSD: Makefile,v 1.2 1998/12/31 06:19:38 garbled Exp $
#

DISTNAME=		nethack-3.2.2
PKGNAME=		nethack-x11-3.2.2
CATEGORIES=		games x11
MASTER_SITES=		# empty

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.win.tue.nl/games/roguelike/nethack/

DEPENDS+=		nethack-lib-3.2.2:../nethack-lib
DEPENDS+=		xpm-3.4k:../../graphics/xpm

WRKSRC=			../nethack-lib/${WRKDIR_BASENAME}/${DISTNAME}
NO_CHECKSUM=		yes
ALL_TARGET=		nethack
INSTALL_TARGET=		binfiles
MAKE_ENV+=		GTYPE=-x11

do-fetch:	#empty
do-extract:
	-@mkdir ${WRKDIR_BASENAME}
	(cd ../nethack-lib && make clean)
	(cd ../nethack-lib && make configure)
	(cd ${WRKSRC}/src && make clean)

do-clean:
	-@rm -r ${WRKDIR_BASENAME}

.include "../../mk/bsd.pkg.mk"
