# $NetBSD: Makefile,v 1.189 2018/08/16 18:54:43 adam Exp $

DISTNAME=	qemu-3.0.0
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://download.qemu-project.org/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.qemu-project.org/
COMMENT=	CPU emulator using dynamic translation
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1 AND mit AND modified-bsd

USE_CURSES=		resize_term wide
USE_LANGUAGES+=		c c++
USE_TOOLS+=		bison flex gmake makeinfo perl:build pkg-config
FAKE_NCURSES=		yes
UNLIMIT_RESOURCES=	datasize
HAS_CONFIGURE=		yes

BUILD_DEPENDS+=		texi2html-[0-9]*:../../textproc/texi2html

SUBST_CLASSES+=			prefix
SUBST_STAGE.prefix=		pre-configure
SUBST_MESSAGE.prefix=		Setting PREFIX
SUBST_FILES.prefix+=		configure
SUBST_VARS.prefix+=		PREFIX

.include "options.mk"

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--interp-prefix=${PREFIX}/share/qemu
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--python=${PYTHONBIN}
CONFIGURE_ARGS+=	--smbd=${PREFIX}/sbin/smbd
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--enable-curses
CONFIGURE_ARGS+=	--enable-jemalloc
CONFIGURE_ARGS+=	--disable-opengl
CONFIGURE_ENV+=		mansuffix=/${PKGMANDIR}

.if defined(PKGSRC_USE_SSP)
# do not add flags to everything
PKGSRC_USE_SSP=		no
CONFIGURE_ARGS+=	--enable-stack-protector
.endif

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
NOT_PAX_MPROTECT_SAFE+=	bin/qemu-system-or1k
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

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # not yet ported yet as of 2.10.0

INSTALLATION_DIRS=	${PKGMANDIR}/man1 share/doc/qemu

UE_ARCHS+=		alpha arm armeb cris i386 m68k microblaze mips mipsel
UE_ARCHS+=		or1k ppc ppc64 ppc64abi32 sh4 sh4eb sparc sparc32plus
UE_ARCHS+=		sparc64 x86_64 microblazeel s390x unicore32

.if ${OPSYS} == "NetBSD"
USER_EMUL=		i386 x86_64 sparc sparc64
PLIST.nbd=		YES
.elif !empty(OPSYS:M*BSD) || ${OPSYS} == "DragonFly"
USER_EMUL=		i386 x86_64 sparc sparc64
PLIST.nbd=		YES
.elif ${OPSYS} == "Darwin"
USER_EMUL=
CONFIGURE_ARGS+=	--disable-bsd-user
PLIST.nbd=		YES
.elif ${OPSYS} == "Linux"
USER_EMUL=		${UE_ARCHS}
PLIST.nbd=		YES
PLIST.ivshmem=		YES
.elif !empty(MACHINE_PLATFORM:MSunOS-5.11-*)
PLIST.nbd=		YES
CONFIGURE_ARGS+=	--disable-coroutine-pool
.endif

PLIST_VARS+=		${UE_ARCHS} nbd ivshmem
.for pvar in ${USER_EMUL}
PLIST.${pvar}=		YES
.endfor

TEST_TARGET=		check

post-install:
	${INSTALL_DATA} ${FILESDIR}/Makefile.multinode-NetBSD \
		${DESTDIR}${PREFIX}/share/doc/qemu/

# On Darwin, qemu uses Cocoa and CoreAudio
.if ${OPSYS} != "Darwin"
.include "../../mk/oss.buildlink3.mk"
.endif
.include "../../archivers/lzo/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/jemalloc/buildlink3.mk"
.include "../../devel/snappy/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
