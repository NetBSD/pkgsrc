# $NetBSD: Makefile,v 1.22 2002/07/12 03:39:15 itojun Exp $

DISTNAME=		bochs-1.4.1
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=bochs/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://bochs.sourceforge.net/
COMMENT=		i386 machine emulator capable of running DOS/Windows

GNU_CONFIGURE=		yes
USE_GMAKE=		yes
# These options are not enabled by default because they can adversely impact
# performance. The number of processors can be either 1 (default), 2, or 4.
#CONFIGURE_ARGS+=	--enable-debugger --enable-disasm
#CONFIGURE_ARGS+=	--enable-processors=2
CONFIGURE_ARGS+=	--enable-cdrom
CONFIGURE_ARGS+=	--enable-ne2000
CONFIGURE_ARGS+=	--enable-sb16=dummy
CONFIGURE_ENV+=		CXXFLAGS="-I${X11BASE}/include ${CXXFLAGS}"
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
	${INSTALL_DATA} ${WRKSRC}/bios/VGABIOS-lgpl-0.3a ${BOCHS_BIOSDIR}
	${INSTALL_DATA} ${WRKSRC}/bios/VGABIOS-lgpl-README ${BOCHS_BIOSDIR}
	${INSTALL_DATA_DIR} ${BOCHS_DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs-html/00README ${BOCHS_DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs-html/*.gif ${BOCHS_DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs-html/*.html ${BOCHS_DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs-html/*.txt ${BOCHS_DOCDIR}
	${INSTALL_DATA_DIR} ${BOCHS_FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/font/hercules.bdf ${BOCHS_FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/font/vga.bdf ${BOCHS_FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/font/vga.pcf ${BOCHS_FONTDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/bochs ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bximage ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/bochsrc ${PREFIX}/share/bochs
	${INSTALL_MAN} ${WRKSRC}/doc/man/*.1 ${PREFIX}/man/man1
	${X11BASE}/bin/mkfontdir ${PREFIX}/share/bochs/xfonts

.include "../../mk/bsd.pkg.mk"
