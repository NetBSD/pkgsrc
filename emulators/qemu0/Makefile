# $NetBSD: Makefile,v 1.16 2016/03/05 11:28:28 jperkin Exp $

DISTNAME=		qemu-0.15.1
PKGREVISION=		16
CATEGORIES=		emulators
MASTER_SITES=		http://wiki.qemu.org/download/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.qemu.org/
COMMENT=		CPU emulator using dynamic translation
LICENSE=		gnu-gpl-v2 AND gnu-lgpl-v2.1 AND mit AND modified-bsd

CONFLICTS+=		qemu-bin-[0-9]*
NOT_FOR_PLATFORM=	NetBSD-1.[0-6]*-*

USE_TOOLS+=		gmake makeinfo perl:build pkg-config
UNLIMIT_RESOURCES=	datasize
HAS_CONFIGURE=		yes

BUILD_DEPENDS+=		texi2html-[0-9]*:../../textproc/texi2html

.include "options.mk"

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--interp-prefix=${PREFIX}/share/qemu
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--python=${PYTHONBIN}

CONF_FILES=		${EGDIR}/target-x86_64.conf \
			${PKG_SYSCONFDIR}/target-x86_64.conf
EGDIR=			${PREFIX}/share/examples/qemu
INSTALL_MAKE_FLAGS=	egdir=${EGDIR}
PKG_SYSCONFSUBDIR=	qemu

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # not yet ported as of 0.15.1

# Avoid clash with system include file:
pre-patch:
	mv ${WRKSRC}/audio/audio.h ${WRKSRC}/audio/qaudio.h

SUBST_CLASSES+=		qaudio
SUBST_STAGE.qaudio=	pre-configure
SUBST_FILES.qaudio=	arch_init.c monitor.c savevm.c vl.c \
			audio/*.c \
			hw/ac97.c \
			hw/adlib.c \
			hw/cs4231a.c \
			hw/es1370.c \
			hw/gus.c \
			hw/hda-audio.c \
			hw/marvell_88w8618_audio.c \
			hw/milkymist-ac97.c \
			hw/mips_fulong2e.c \
			hw/mips_jazz.c \
			hw/mips_malta.c \
			hw/omap2.c \
			hw/palm.c \
			hw/pcspk.c \
			hw/sb16.c \
			hw/spitz.c \
			hw/tsc210x.c \
			hw/wm8750.c \
			ui/vnc.h
SUBST_SED.qaudio=	-e s,audio.h\",qaudio.h\",g
SUBST_MESSAGE.qaudio=	Fixing audio.h confusion

REPLACE_PERL+=		texi2pod.pl

BUILDLINK_PASSTHRU_DIRS+= /usr/lib
BUILDLINK_PASSTHRU_RPATHDIRS+= /usr/lib

INSTALLATION_DIRS=	${PKGMANDIR}/man1 share/doc/qemu

UE_ARCHS+=		alpha arm armeb cris i386 m68k microblaze mips mipsel
UE_ARCHS+=		ppc ppc64 ppc64abi32 sh4 sh4eb sparc sparc32plus
UE_ARCHS+=		sparc64 x86_64 microblazeel s390x unicore32

.if ${OPSYS} == "NetBSD"
.if (!empty(OS_VERSION:M5.99.*) || !empty(OS_VERSION:M[6-9].*))
# XXX
# i386 and x86_64 user emul require newer binutils for PROVIDE_HIDDEN()
# http://git.qemu.org/qemu.git/commit/?id=845f2c2812d9ed24b36c02a3d06ee83aeafe8b49
# but binutils-2.19 was enabled around 5.99.22:
# http://cvsweb.NetBSD.org/bsdweb.cgi/src/share/mk/bsd.own.mk#rev1.594
USER_EMUL=		i386 x86_64 sparc sparc64
.else
CONFIGURE_ARGS+=	--disable-bsd-user
USER_EMUL=
.endif
PLIST.nbd=		YES
.elif !empty(OPSYS:M*BSD) || !empty(OPSYS:MDragonFly)
USER_EMUL=		i386 x86_64 sparc sparc64
PLIST.nbd=		YES
.elif !empty(OPSYS:MDarwin)
USER_EMUL=
CONFIGURE_ARGS+=	--disable-bsd-user
CONFIGURE_ARGS+=	--disable-darwin-user
PLIST.nbd=		YES
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

# On Darwin, qemu uses Cocoa and CoreAudio
.if empty(OPSYS:MDarwin)
.include "../../mk/oss.buildlink3.mk"
.endif
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/terminfo.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
