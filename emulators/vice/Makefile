# $NetBSD: Makefile,v 1.1 1998/09/06 23:47:26 garbled Exp $

DISTNAME=		vice-0.15.0
CATEGORIES=		emulators
MASTER_SITES=		http://www.tu-chemnitz.de/~fachat/vice/
DISTFILES=		vice-0.15.0-roms.tar.gz ${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.tu-chemnitz.de/~fachat/vice/

BUILD_DEPENDS+= 	bison:../../devel/bison
DEPENDS+=		xpm-3.4k:../../graphics/xpm

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		LDFLAGS="-Wl,-R${X11BASE}/lib"
USE_GMAKE=		yes
USE_X11=		yes
INFO_FILES=		vice.info

post-install:
	${INSTALL_DATA} ${WRKDIR}/data/C64/* ${PREFIX}/share/vice/C64
	${INSTALL_DATA} ${WRKDIR}/data/C128/* ${PREFIX}/share/vice/C128
	${INSTALL_DATA} ${WRKDIR}/data/VIC20/* ${PREFIX}/share/vice/VIC20
	${INSTALL_DATA} ${WRKDIR}/data/PET/* ${PREFIX}/share/vice/PET

.include "../../mk/bsd.pkg.mk"
