# $NetBSD: Makefile,v 1.7 2000/01/31 21:18:43 drochner Exp $

DISTNAME=		bochs-2000_0104c
PKGNAME=		bochs-2000.01.04c
CATEGORIES=		emulators
MASTER_SITES=		ftp://bochs.com/pub/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.bochs.com/

NOT_FOR_PLATFORM=	*-*-alpha	#runs, SEGV.

LICENSE=		shareware
GNU_CONFIGURE=		yes
#CONFIGURE_ARGS=		--enable-debugger --enable-disasm
USE_X11=		yes

post-configure:
	${SED} -e 's@XXXPREFIXXXX@${PREFIX}@' < ${WRKSRC}/.bochsrc > ${WRKSRC}/bochsrc

do-install:
	${MKDIR} ${PREFIX}/share/bochs/bios
	${INSTALL_DATA} ${WRKSRC}/bios/BIOS-bochs-990925a ${PREFIX}/share/bochs/bios
	${INSTALL_DATA} ${WRKSRC}/bios/VGABIOS-elpin-2.20 ${PREFIX}/share/bochs/bios
	${MKDIR} ${PREFIX}/share/bochs/doc
	${INSTALL_DATA} ${WRKSRC}/docs-html/* ${PREFIX}/share/bochs/doc
	${MKDIR} ${PREFIX}/share/bochs/xfonts
	${INSTALL_DATA} ${WRKSRC}/font/hercules.bdf ${PREFIX}/share/bochs/xfonts
	${INSTALL_DATA} ${WRKSRC}/font/vga.bdf ${PREFIX}/share/bochs/xfonts
	${INSTALL_DATA} ${WRKSRC}/font/vga.pcf ${PREFIX}/share/bochs/xfonts
	${INSTALL_PROGRAM} ${WRKSRC}/bochs ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/bochsrc ${PREFIX}/share/bochs
	${X11BASE}/bin/mkfontdir ${PREFIX}/share/bochs/xfonts

.include "../../mk/bsd.pkg.mk"
