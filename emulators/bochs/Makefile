# $NetBSD: Makefile,v 1.16 2001/12/13 18:03:52 fredb Exp $

DISTNAME=		bochs-1.3
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=bochs/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://bochs.sourceforge.net/
COMMENT=		I386 machine emulator capable of running dos/windows

GNU_CONFIGURE=		yes
USE_GMAKE=		yes
# These options are not enabled by default because they can adversely impact
# performance. The number of processors can be either 1 (default), 2, or 4.
#CONFIGURE_ARGS+=	--enable-debugger --enable-disasm
#CONFIGURE_ARGS+=	--enable-processors=2
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
	${INSTALL_DATA} ${WRKSRC}/bios/BIOS-bochs-2-processors ${BOCHS_BIOSDIR}
	${INSTALL_DATA} ${WRKSRC}/bios/BIOS-bochs-4-processors ${BOCHS_BIOSDIR}
	${INSTALL_DATA} ${WRKSRC}/bios/BIOS-bochs-latest ${BOCHS_BIOSDIR}
	${INSTALL_DATA} ${WRKSRC}/bios/VGABIOS-elpin-2.40 ${BOCHS_BIOSDIR}
	${INSTALL_DATA} ${WRKSRC}/bios/VGABIOS-elpin-LICENSE ${BOCHS_BIOSDIR}
	${INSTALL_DATA} ${WRKSRC}/bios/VGABIOS-cbothamy-0.2a ${BOCHS_BIOSDIR}
	${INSTALL_DATA} ${WRKSRC}/bios/VGABIOS-cbothamy-0.2a-README ${BOCHS_BIOSDIR}
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
