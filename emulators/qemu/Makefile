# $NetBSD: Makefile,v 1.69 2010/08/09 11:49:10 tsutsui Exp $
#

DISTNAME=		qemu-0.12.4
CATEGORIES=		emulators
MASTER_SITES=		http://download.savannah.gnu.org/releases/qemu/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.qemu.org/
COMMENT=		CPU emulator using dynamic translation
LICENSE=		gnu-gpl-v2 AND gnu-lgpl-v2.1 AND mit AND modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=		qemu-bin-[0-9]*
NOT_FOR_PLATFORM=	NetBSD-1.[0-6]*-*

USE_TOOLS+=		gmake perl:build
HAS_CONFIGURE=		yes

BUILD_DEPENDS+=		texi2html-[0-9]*:../../textproc/texi2html

# Workaround for PR/41007 - ensure WRKSRC comes before any buildlinked
# directories so we pickup our audio/audio.h. Cannot use CPPFLAGS for this
CFLAGS+=		-I${WRKSRC} -I${WRKSRC}/slirp

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ENV+=		mansuffix=/${PKGMANDIR}
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--interp-prefix=${PREFIX:Q}/share/qemu

# Avoid clash with system include file:
pre-patch:
	mv ${WRKSRC}/audio/audio.h ${WRKSRC}/audio/qaudio.h

SUBST_CLASSES+=		qaudio
SUBST_STAGE.qaudio=	pre-configure
SUBST_FILES.qaudio=	monitor.c savevm.c vl.c vnc.h \
			audio/*.c \
			hw/ac97.c \
			hw/adlib.c \
			hw/cs4231a.c \
			hw/es1370.c \
			hw/gus.c \
			hw/marvell_88w8618_audio.c \
			hw/mips_jazz.c \
			hw/mips_malta.c \
			hw/omap2.c \
			hw/palm.c \
			hw/pc.c \
			hw/pcspk.c \
			hw/sb16.c \
			hw/spitz.c \
			hw/tsc210x.c \
			hw/wm8750.c
SUBST_SED.qaudio=	-e s,audio.h\",qaudio.h\",g
SUBST_MESSAGE.qaudio= 	Fixing audio.h confusion

REPLACE_PERL+=		texi2pod.pl

BUILDLINK_PASSTHRU_DIRS+= /usr/lib
BUILDLINK_PASSTHRU_RPATHDIRS+= /usr/lib

INSTALLATION_DIRS=	${PKGMANDIR}/man1 share/doc/qemu

UE_ARCHS+=		alpha arm armeb cris i386 m68k microblaze mips mipsel
UE_ARCHS+=		nbd ppc ppc64 ppc64abi32 sh4 sh4eb sparc sparc32plus
UE_ARCHS+=		sparc64 x86_64

.if !empty(OPSYS:M*BSD) || !empty(OPSYS:MDragonFly)
USER_EMUL=		i386 x86_64 sparc sparc64
.elif !empty(OPSYS:MDarwin)
USER_EMUL=		i386 x86_64 sparc sparc64 ppc
.elif !empty(OPSYS:MLinux)
USER_EMUL=		${UE_ARCHS}
PLIST.nbd=		YES
.endif

PLIST_VARS+=		${UE_ARCHS} nbd
.for _var_ in ${USER_EMUL}
PLIST.${_var_}=		YES
.endfor

post-install:
	${INSTALL_DATA} ${FILESDIR}/Makefile.multinode-NetBSD \
		${DESTDIR}${PREFIX}/share/doc/qemu/

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
