# $NetBSD: Makefile,v 1.2 1998/09/22 06:11:36 garbled Exp $

DISTNAME=		bochs-980707a
CATEGORIES=		emulators
MASTER_SITES=		ftp://ftp.std.com/pub/bochs/

NOT_FOR_ARCHS=		alpha	#runs, SEGV.

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://world.std.com/~bochs/

LICENSE=		shareware
WRKSRC=			${WRKDIR}/bochs-980707
USE_GMAKE=		yes
CONFIGURE_ARGS+=	--enable-vga #--with-x11
GNU_CONFIGURE=		yes
USE_X11=		yes

post-configure:
	${SED} -e 's@XXXPREFIXXXX@${PREFIX}@' < ${WRKSRC}/.bochsrc > ${WRKSRC}/bochsrc

do-install:
	${MKDIR} ${PREFIX}/share/bochs/bios
	${INSTALL_DATA} ${WRKSRC}/bios/BIOS-bochs-980702a ${PREFIX}/share/bochs/bios
	${INSTALL_DATA} ${WRKSRC}/bios/VGABIOS-elpin-2.20 ${PREFIX}/share/bochs/bios
	${MKDIR} ${PREFIX}/share/doc/bochs
	${INSTALL_DATA} ${WRKSRC}/docs-html/* ${PREFIX}/share/doc/bochs
	${INSTALL_DATA} ${WRKSRC}/font/hercules.bdf ${X11BASE}/lib/X11/fonts/misc
	${INSTALL_DATA} ${WRKSRC}/font/vga.bdf ${X11BASE}/lib/X11/fonts/misc
	${INSTALL_DATA} ${WRKSRC}/font/vga.pcf ${X11BASE}/lib/X11/fonts/misc
	${INSTALL_PROGRAM} ${WRKSRC}/bochs ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/bochsrc ${PREFIX}/share/bochs
	${X11BASE}/bin/mkfontdir ${X11BASE}/lib/X11/fonts/misc

.include "../../mk/bsd.pkg.mk"
