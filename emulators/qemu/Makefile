# $NetBSD: Makefile,v 1.154.2.1 2016/11/07 19:11:35 bsiegert Exp $

DISTNAME=	qemu-2.7.0
CATEGORIES=	emulators
MASTER_SITES=	http://wiki.qemu.org/download/
EXTRACT_SUFX=	.tar.bz2
PKGREVISION=	1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.qemu.org/
COMMENT=	CPU emulator using dynamic translation
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1 AND mit AND modified-bsd

CONFLICTS+=		qemu-bin-[0-9]*
NOT_FOR_PLATFORM+=	NetBSD-1.[0-6]*-*
# qemu 1 does not work on NetBSD-5; see http://gnats.netbsd.org/46565.
# As a workaround, use emulators/qemu0.
NOT_FOR_PLATFORM+=	NetBSD-5*-*

USE_TOOLS+=		bison gmake makeinfo perl:build pkg-config
USE_NCURSES=		yes			# requires resize_term()
UNLIMIT_RESOURCES=	datasize
HAS_CONFIGURE=		yes

BUILD_DEPENDS+=		texi2html-[0-9]*:../../textproc/texi2html

.include "options.mk"

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--interp-prefix=${PREFIX}/share/qemu
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--python=${PYTHONBIN}
CONFIGURE_ARGS+=	--smbd=${PREFIX}/sbin/smbd
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--enable-curses
#HF#CONFIGURE_ARGS+=	--disable-fdt			# HF: build on OS X
CONFIGURE_ARGS+=	--disable-opengl
CONFIGURE_ENV+=		mansuffix=/${PKGMANDIR}

NOT_PAX_MPROTECT_SAFE+=	bin/qemu-system-aarch64
NOT_PAX_MPROTECT_SAFE+=	bin/qemu-system-alpha
NOT_PAX_MPROTECT_SAFE+=	bin/qemu-system-arm
NOT_PAX_MPROTECT_SAFE+=	bin/qemu-system-cris
NOT_PAX_MPROTECT_SAFE+=	bin/qemu-system-i386
NOT_PAX_MPROTECT_SAFE+=	bin/qemu-system-lm32
NOT_PAX_MPROTECT_SAFE+=	bin/qemu-system-m68k
NOT_PAX_MPROTECT_SAFE+=	bin/qemu-system-microblaze
NOT_PAX_MPROTECT_SAFE+=	bin/qemu-system-microblazeel
NOT_PAX_MPROTECT_SAFE+=	bin/qemu-system-mips
NOT_PAX_MPROTECT_SAFE+=	bin/qemu-system-mips64
NOT_PAX_MPROTECT_SAFE+=	bin/qemu-system-mips64el
NOT_PAX_MPROTECT_SAFE+=	bin/qemu-system-mipsel
NOT_PAX_MPROTECT_SAFE+=	bin/qemu-system-moxie
NOT_PAX_MPROTECT_SAFE+=	bin/qemu-system-or32
NOT_PAX_MPROTECT_SAFE+=	bin/qemu-system-ppc
NOT_PAX_MPROTECT_SAFE+=	bin/qemu-system-ppc64
NOT_PAX_MPROTECT_SAFE+=	bin/qemu-system-ppcemb
NOT_PAX_MPROTECT_SAFE+=	bin/qemu-system-s390x
NOT_PAX_MPROTECT_SAFE+=	bin/qemu-system-sh4
NOT_PAX_MPROTECT_SAFE+=	bin/qemu-system-sh4eb
NOT_PAX_MPROTECT_SAFE+=	bin/qemu-system-sparc
NOT_PAX_MPROTECT_SAFE+=	bin/qemu-system-sparc64
NOT_PAX_MPROTECT_SAFE+=	bin/qemu-system-tricore
NOT_PAX_MPROTECT_SAFE+=	bin/qemu-system-unicore32
NOT_PAX_MPROTECT_SAFE+=	bin/qemu-system-x86_64
NOT_PAX_MPROTECT_SAFE+=	bin/qemu-system-xtensa
NOT_PAX_MPROTECT_SAFE+=	bin/qemu-system-xtensaeb

PKG_SYSCONFSUBDIR=	qemu

REPLACE_PERL+=		scripts/texi2pod.pl

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # not yet ported yet as of 1.7.0

BUILDLINK_PASSTHRU_DIRS+= /usr/lib
BUILDLINK_PASSTHRU_RPATHDIRS+= /usr/lib

INSTALLATION_DIRS=	${PKGMANDIR}/man1 share/doc/qemu

UE_ARCHS+=		alpha arm armeb cris i386 m68k microblaze mips mipsel
UE_ARCHS+=		or32 ppc ppc64 ppc64abi32 sh4 sh4eb sparc sparc32plus
UE_ARCHS+=		sparc64 x86_64 microblazeel s390x unicore32

.if ${OPSYS} == "NetBSD"
.  if (!empty(OS_VERSION:M5.99.*) || !empty(OS_VERSION:M[6-9].*))
# XXX
# i386 and x86_64 user emul require newer binutils for PROVIDE_HIDDEN()
# http://git.qemu.org/qemu.git/commit/?id=845f2c2812d9ed24b36c02a3d06ee83aeafe8b49
# but binutils-2.19 was enabled around 5.99.22:
# http://cvsweb.NetBSD.org/bsdweb.cgi/src/share/mk/bsd.own.mk#rev1.594
USER_EMUL=		i386 x86_64 sparc sparc64
.  else
CONFIGURE_ARGS+=	--disable-bsd-user
USER_EMUL=
.  endif
PLIST.nbd=		YES
.elif !empty(OPSYS:M*BSD) || !empty(OPSYS:MDragonFly)
USER_EMUL=		i386 x86_64 sparc sparc64
PLIST.nbd=		YES
.elif !empty(OPSYS:MDarwin)
USER_EMUL=
CONFIGURE_ARGS+=	--disable-bsd-user
PLIST.nbd=		YES
.elif !empty(OPSYS:MLinux)
USER_EMUL=		${UE_ARCHS}
PLIST.nbd=		YES
.elif !empty(MACHINE_PLATFORM:MSunOS-5.11-*)
PLIST.nbd=		YES
CONFIGURE_ARGS+=	--disable-coroutine-pool
.endif

PLIST_VARS+=		${UE_ARCHS} nbd ivshmem
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
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
