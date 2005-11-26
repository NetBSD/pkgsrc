# $NetBSD: Makefile,v 1.42 2005/11/26 06:15:00 ben Exp $

DISTNAME=		bochs-2.2.1
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=bochs/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://bochs.sourceforge.net/
COMMENT=		IA32 and AMD64 PC emulator

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
USE_TOOLS+=		gunzip gzip
USE_LANGUAGES=		c c++

ONLY_FOR_COMPILER=	gcc

# These options are not enabled by default because they can adversely impact
# performance. The number of processors can be either 1 (default), 2, or 4.
#CONFIGURE_ARGS+=	--enable-debugger --enable-disasm
#CONFIGURE_ARGS+=	--enable-processors=2
CONFIGURE_ARGS+=	--enable-cdrom
CONFIGURE_ARGS+=	--enable-ne2000
CONFIGURE_ARGS+=	--enable-sb16=dummy
.if !defined(BOCHS_TINY)
CONFIGURE_ARGS+=	--enable-new-pit
CONFIGURE_ARGS+=	--enable-pci
CONFIGURE_ARGS+=	--enable-cpu-level=6
CONFIGURE_ARGS+=	--enable-apic
CONFIGURE_ARGS+=	--enable-usb
CONFIGURE_ARGS+=	--enable-4meg-pages
CONFIGURE_ARGS+=	--enable-pae
CONFIGURE_ARGS+=	--enable-guest2host-tlb
CONFIGURE_ARGS+=	--enable-repeat-speedups
CONFIGURE_ARGS+=	--enable-icache
.include "../../mk/bsd.prefs.mk"
.if !empty(MACHINE_PLATFORM:M*-*-i386)
CONFIGURE_ARGS+=	--enable-fast-function-calls
.endif
CONFIGURE_ARGS+=	--enable-global-pages
CONFIGURE_ARGS+=	--enable-host-specific-asms
CONFIGURE_ARGS+=	--enable-all-optimizations
CONFIGURE_ARGS+=	--enable-vbe
CONFIGURE_ARGS+=	--enable-fpu
CONFIGURE_ARGS+=	--enable-mmx
CONFIGURE_ARGS+=	--enable-3dnow
CONFIGURE_ARGS+=	--enable-sse=2
CONFIGURE_ARGS+=	--enable-daz
CONFIGURE_ARGS+=	--enable-sep
.endif # !BOCHS_TINY
CONFIGURE_ENV+=		CXXFLAGS="-I${X11BASE}/include ${CXXFLAGS}"
MANCOMPRESSED=		yes
MAKE_ENV+=		GZIP_CMD=${GZIP_CMD:Q} \
			GUNZIP_CMD=${GUNZIP_CMD:Q}

BOCHS_MAINDIR=		${PREFIX}/share/bochs
BOCHS_BIOSDIR=		${BOCHS_MAINDIR}/bios
BOCHS_FONTDIR=		${BOCHS_MAINDIR}/xfonts

.include "../../mk/x11.buildlink3.mk"

post-configure:
	${MV} ${WRKSRC}/.bochsrc ${WRKSRC}/.bochsrc.BAK
	${SED} -e 's@XXXPREFIXXXX@${PREFIX}@' \
		< ${WRKSRC}/.bochsrc.BAK > ${WRKSRC}/.bochsrc

.include "../../mk/bsd.pkg.mk"
