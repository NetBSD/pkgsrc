# $NetBSD: Makefile,v 1.5 1999/01/30 23:18:46 agc Exp $

DISTNAME=		vice-0.15.0
CATEGORIES=		emulators
MASTER_SITES=		http://www.tu-chemnitz.de/~fachat/vice/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.tu-chemnitz.de/~fachat/vice/

BUILD_DEPENDS+= 	bison:../../devel/bison
DEPENDS+=		xpm-3.4k:../../graphics/xpm

MIRROR_DISTFILE=	no
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		LDFLAGS="-Wl,-R${X11BASE}/lib"
USE_GMAKE=		yes
USE_X11BASE=		yes
INFO_FILES=		vice.info

post-install:
	for ii in C64 C128 VIC20; do \
		for xx in basic chargen dos1541 kernal; do \
			${INSTALL_DATA} ${WRKSRC}/data/$$ii/$$xx ${PREFIX}/share/vice/$$ii; \
		done; \
	done
	for ii in chargen edit2.b edit4.b40 edit4.b80 pet2001 pet3032 pet4032; do \
		${INSTALL_DATA} ${WRKSRC}/data/PET/$$ii ${PREFIX}/share/vice/PET; \
	done

.include "../../mk/bsd.pkg.mk"
