# $NetBSD: Makefile,v 1.13 2001/05/15 20:20:07 fredb Exp $

DISTNAME=		bochs-2000_0325a
PKGNAME=		bochs-2000.03.25a
CATEGORIES=		emulators
MASTER_SITES=		ftp://bochs.com/bochs/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://bochs.sourceforge.net/
COMMENT=		I386 machine emulator capable of running dos/windows

GNU_CONFIGURE=		yes
USE_GMAKE=		yes
#CONFIGURE_ARGS=		--enable-debugger --enable-disasm
USE_X11=		yes

BOCHS_MAINDIR=		${PREFIX}/share/bochs
BOCHS_BIOSDIR=		${BOCHS_MAINDIR}/bios
BOCHS_FONTDIR=		${BOCHS_MAINDIR}/xfonts
BOCHS_DOCDIR=		${PREFIX}/share/doc/html/bochs
MESSAGE_SUBST+=		BOCHS_MAINDIR=${BOCHS_MAINDIR} \
			BOCHS_FONTDIR=${BOCHS_FONTDIR} \
			BOCHS_DOCDIR=${BOCHS_DOCDIR}

post-configure:
	${SED} -e 's@XXXPREFIXXXX@${PREFIX}@' \
		< ${WRKSRC}/.bochsrc > ${WRKSRC}/bochsrc

do-install:
	${INSTALL_DATA_DIR} ${BOCHS_BIOSDIR}
	${INSTALL_DATA} ${WRKSRC}/bios/BIOS-bochs-990925a ${BOCHS_BIOSDIR}
	${INSTALL_DATA} ${WRKSRC}/bios/VGABIOS-elpin-2.20 ${BOCHS_BIOSDIR}
	${INSTALL_DATA_DIR} ${BOCHS_DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs-html/00README ${BOCHS_DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs-html/*.gif ${BOCHS_DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs-html/*.html ${BOCHS_DOCDIR}
	${INSTALL_DATA_DIR} ${BOCHS_FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/font/hercules.bdf ${BOCHS_FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/font/vga.bdf ${BOCHS_FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/font/vga.pcf ${BOCHS_FONTDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/bochs ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/bochsrc ${PREFIX}/share/bochs
	${X11BASE}/bin/mkfontdir ${PREFIX}/share/bochs/xfonts

.include "../../mk/bsd.pkg.mk"
