# $NetBSD: Makefile,v 1.300 2022/07/10 14:36:25 ryoon Exp $

DISTNAME=	qemu-7.0.0
PKGREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	https://download.qemu.org/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.qemu.org/
COMMENT=	CPU emulator using dynamic translation
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1 AND mit AND modified-bsd

TOOL_DEPENDS+=	ninja-build-[0-9]*:../../devel/ninja-build

USE_CURSES=		resize_term wide
USE_LANGUAGES+=		c c++
USE_TOOLS+=		bison flex makeinfo perl:build pod2man pkg-config
UNLIMIT_RESOURCES=	datasize
HAS_CONFIGURE=		yes

# https://github.com/qemu/qemu/commit/56208a0d473c6db263cc333c787ca48b502d72ab
GCC_REQD+=		7

PYTHON_VERSIONS_INCOMPATIBLE=	27

TOOL_DEPENDS+=		${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx
TOOL_DEPENDS+=		${PYPKGPREFIX}-sphinx-rtd-theme>=0.4.3:../../textproc/py-sphinx-rtd-theme

SUBST_CLASSES+=			sphinx-build
SUBST_STAGE.sphinx-build=	pre-configure
SUBST_MESSAGE.sphinx-build=	Fix hardcoded sphinx-build
SUBST_FILES.sphinx-build+=	configure
SUBST_FILES.sphinx-build+=	docs/meson.build
SUBST_FILES.sphinx-build+=	roms/skiboot/doc/Makefile
SUBST_FILES.sphinx-build+=	roms/u-boot/doc/Makefile
SUBST_SED.sphinx-build+=	-e 's/sphinx-build/sphinx-build-${PYVERSSUFFIX}/g'

.include "options.mk"

.include "../../mk/bsd.prefs.mk"

# When upgrading Qemu, you need to determine if this PALcode binary for
# the Alpha emulator needs to be re-built.  If it does not, then you do
# not need to bump the version of this PALcode binary blob (which is
# supplied as a separate distfile).  Contact thorpej@ for details.
PALCODE_CLIPPER=	palcode-clipper-qemu-5.2.0nb8

DISTFILES=		${DEFAULT_DISTFILES}
DISTFILES+=		${PALCODE_CLIPPER}
SITES.${PALCODE_CLIPPER}= http://ftp.NetBSD.org/pub/NetBSD/arch/alpha/qemu/

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--interp-prefix=${PREFIX}/share/qemu
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--python=${PYTHONBIN}
CONFIGURE_ARGS+=	--smbd=${PREFIX}/sbin/smbd
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--enable-curses
CONFIGURE_ARGS+=	--enable-docs
CONFIGURE_ARGS+=	--enable-jemalloc
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
NOT_PAX_MPROTECT_SAFE+=	bin/qemu-system-hppa
NOT_PAX_MPROTECT_SAFE+=	bin/qemu-system-i386
NOT_PAX_MPROTECT_SAFE+=	bin/qemu-system-m68k
NOT_PAX_MPROTECT_SAFE+=	bin/qemu-system-microblaze
NOT_PAX_MPROTECT_SAFE+=	bin/qemu-system-microblazeel
NOT_PAX_MPROTECT_SAFE+=	bin/qemu-system-mips
NOT_PAX_MPROTECT_SAFE+=	bin/qemu-system-mips64
NOT_PAX_MPROTECT_SAFE+=	bin/qemu-system-mips64el
NOT_PAX_MPROTECT_SAFE+=	bin/qemu-system-mipsel
NOT_PAX_MPROTECT_SAFE+=	bin/qemu-system-nios2
NOT_PAX_MPROTECT_SAFE+=	bin/qemu-system-or1k
NOT_PAX_MPROTECT_SAFE+=	bin/qemu-system-ppc
NOT_PAX_MPROTECT_SAFE+=	bin/qemu-system-ppc64
NOT_PAX_MPROTECT_SAFE+=	bin/qemu-system-riscv32
NOT_PAX_MPROTECT_SAFE+=	bin/qemu-system-riscv64
NOT_PAX_MPROTECT_SAFE+=	bin/qemu-system-s390x
NOT_PAX_MPROTECT_SAFE+=	bin/qemu-system-sh4
NOT_PAX_MPROTECT_SAFE+=	bin/qemu-system-sh4eb
NOT_PAX_MPROTECT_SAFE+=	bin/qemu-system-sparc
NOT_PAX_MPROTECT_SAFE+=	bin/qemu-system-sparc64
NOT_PAX_MPROTECT_SAFE+=	bin/qemu-system-tricore
NOT_PAX_MPROTECT_SAFE+=	bin/qemu-system-x86_64
NOT_PAX_MPROTECT_SAFE+=	bin/qemu-system-xtensa
NOT_PAX_MPROTECT_SAFE+=	bin/qemu-system-xtensaeb

PKG_SYSCONFSUBDIR=	qemu

INSTALLATION_DIRS=	${PKGMANDIR}/man1 share/doc/qemu

.include "../../mk/oss.buildlink3.mk"

.if ${OSS_TYPE} != "none"
SUBST_CLASSES+=		oss
SUBST_STAGE.oss=	pre-configure
SUBST_MESSAGE.oss=	Correcting the path to the OSS device.
SUBST_FILES.oss+=	audio/ossaudio.c
SUBST_SED.oss+=		-e "s,/dev/dsp,${DEVOSSAUDIO},g"
.endif

UE_ARCHS+=		aarch64 aarch64_be
UE_ARCHS+=		alpha arm armeb cris
UE_ARCHS+=		hexagon hppa
UE_ARCHS+=		i386
UE_ARCHS+=		m68k microblaze microblazeel
UE_ARCHS+=		mips mips64 mips64el mipsel mipsn32 mipsn32el
UE_ARCHS+=		nios2
UE_ARCHS+=		or1k ppc ppc64 ppc64le
UE_ARCHS+=		riscv32 riscv64
UE_ARCHS+=		s390x sh4 sh4eb sparc sparc32plus sparc64
UE_ARCHS+=		x86_64 xtensa xtensaeb

.if ${OPSYS} == "NetBSD"
PLIST.nbd=			yes
.  if !exists(/usr/include/machine/trap.h)	\
	|| "1"=="1"	# XXX usermode emulation is broken
CONFIGURE_ARGS+=		--disable-bsd-user
.  else
CONFIGURE_ARGS+=		--enable-bsd-user
USER_EMUL=			i386 x86_64
.  endif
.elif !empty(OPSYS:M*BSD) || ${OPSYS} == "DragonFly"
USER_EMUL=			i386 x86_64
PLIST.nbd=			yes
.elif ${OPSYS} == "Darwin"
USER_EMUL=
CONFIGURE_ARGS+=		--disable-bsd-user
PLIST.nbd=			yes
.elif ${OPSYS} == "Linux"
USER_EMUL=			${UE_ARCHS}
PLIST.bridge-helper=		yes
PLIST.ga=			yes
PLIST.nbd=			yes
PLIST.pr-helper=		yes
.elif !empty(MACHINE_PLATFORM:MSunOS-5.11-*)
PLIST.ga=			yes
PLIST.nbd=			yes
CONFIGURE_ARGS+=		--disable-coroutine-pool
.endif

PLIST_VARS+=		plugins
.if ${OPSYS} != "SunOS"
PLIST.plugins=		yes
CONFIGURE_ARGS+=	--enable-plugins
.else
CONFIGURE_ARGS+=	--disable-plugins
.endif

PLIST_VARS+=		${UE_ARCHS} bridge-helper ga keymap nbd pr-helper
.for pvar in ${USER_EMUL}
PLIST.${pvar}=		yes
.endfor

# different versions of Sphinx generate different static files
PLIST_SRC=	PLIST ${WRKDIR}/PLIST.STATIC

PRINT_PLIST_AWK+=	/\/_static\// { next; }

TEST_TARGET=		check

PYTHON_FOR_BUILD_ONLY=	tool

post-extract:
	cp ${WRKDIR}/${PALCODE_CLIPPER} ${WRKSRC}/pc-bios/palcode-clipper
	cp ${FILESDIR}/hw-mips-mipssim_virtio.c ${WRKSRC}/hw/mips/mipssim_virtio.c

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		ninja -j ${_MAKE_JOBS_N:U1} -C build

do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${INSTALL_ENV} \
		ninja -j ${_MAKE_JOBS_N:U1} -C build install

# Some dependencies aren't correct and this tries to be re-made on install,
# failing due to configure bugs.
post-build:
	${TOUCH} ${WRKSRC}/config-host.mak

post-install:
	${INSTALL_DATA} ${FILESDIR}/Makefile.multinode-NetBSD \
		${DESTDIR}${PREFIX}/share/doc/qemu/
	${RM} -f ${DESTDIR}${PREFIX}/share/doc/qemu/interop/.buildinfo
	${RM} -f ${DESTDIR}${PREFIX}/share/doc/qemu/specs/.buildinfo
	${RM} -f ${WRKDIR}/PLIST.STATIC
	cd ${DESTDIR}${PREFIX} && \
	${FIND} share/doc/qemu -path '*/_static/*' -type f -print > ${WRKDIR}/PLIST.STATIC

.include "../../archivers/lzo/buildlink3.mk"
.include "../../archivers/zstd/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/jemalloc/buildlink3.mk"
.include "../../devel/snappy/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../net/libslirp/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
