# $NetBSD: Makefile,v 1.39 2005/05/16 18:22:57 jlam Exp $

DISTNAME=		bochs-2.1.1
PKGREVISION=		1
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=bochs/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://bochs.sourceforge.net/
COMMENT=		i386 machine emulator capable of running DOS/Windows

GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
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
USE_X11=		yes
MANCOMPRESSED=		yes
MAKE_ENV+=		GZIP_CMD=${GZIP_CMD:Q} \
			GUNZIP_CMD=${GUNZIP_CMD:Q}

BOCHS_MAINDIR=		${PREFIX}/share/bochs
BOCHS_BIOSDIR=		${BOCHS_MAINDIR}/bios
BOCHS_FONTDIR=		${BOCHS_MAINDIR}/xfonts

post-configure:
	${MV} ${WRKSRC}/.bochsrc ${WRKSRC}/.bochsrc.BAK
	${SED} -e 's@XXXPREFIXXXX@${PREFIX}@' \
		< ${WRKSRC}/.bochsrc.BAK > ${WRKSRC}/.bochsrc

.include "../../mk/bsd.pkg.mk"
