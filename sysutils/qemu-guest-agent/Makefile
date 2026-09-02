# $NetBSD: Makefile,v 1.15 2026/09/02 19:04:35 wiz Exp $

PKGREVISION= 1
.include "../../emulators/qemu/Makefile.common"

PKGNAME=	${DISTNAME:S/qemu/qemu-guest-agent/}
CATEGORIES=	sysutils emulators

COMMENT=	QEMU guest agent

# meson.build: unsupported OS for QEMU guest agent
NOT_FOR_PLATFORM=	Darwin-*-*

USE_LANGUAGES+=		c c++
USE_TOOLS+=		pkg-config perl
UNLIMIT_RESOURCES=	datasize
HAS_CONFIGURE=		yes

RCD_SCRIPTS=		qemu-guest-agent

CONFLICTS+=		qemu-[0-9]*

# https://github.com/qemu/qemu/commit/56208a0d473c6db263cc333c787ca48b502d72ab
GCC_REQD+=		7

.include "options.mk"

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--enable-guest-agent
CONFIGURE_ARGS+=	--disable-tools
CONFIGURE_ARGS+=	--disable-xkbcommon
CONFIGURE_ARGS+=	--disable-attr
CONFIGURE_ARGS+=	--disable-install-blobs
CONFIGURE_ARGS+=	--disable-brlapi
CONFIGURE_ARGS+=	--disable-bzip2
CONFIGURE_ARGS+=	--disable-cap-ng
CONFIGURE_ARGS+=	--disable-coroutine-pool
CONFIGURE_ARGS+=	--disable-curses
CONFIGURE_ARGS+=	--disable-fdt
CONFIGURE_ARGS+=	--disable-gcrypt
CONFIGURE_ARGS+=	--disable-libnfs
CONFIGURE_ARGS+=	--disable-libusb
CONFIGURE_ARGS+=	--disable-lzo
CONFIGURE_ARGS+=	--disable-netmap
CONFIGURE_ARGS+=	--disable-nettle
CONFIGURE_ARGS+=	--disable-numa
CONFIGURE_ARGS+=	--disable-rbd
CONFIGURE_ARGS+=	--disable-rdma
CONFIGURE_ARGS+=	--disable-seccomp
CONFIGURE_ARGS+=	--disable-smartcard
CONFIGURE_ARGS+=	--disable-snappy
CONFIGURE_ARGS+=	--disable-spice
CONFIGURE_ARGS+=	--disable-system
CONFIGURE_ARGS+=	--disable-tpm
CONFIGURE_ARGS+=	--disable-user
CONFIGURE_ARGS+=	--disable-vhost-net
CONFIGURE_ARGS+=	--disable-virtfs
CONFIGURE_ARGS+=	--disable-vnc

PKG_SYSCONFSUBDIR=	qemu

INSTALLATION_DIRS=	${PKGMANDIR}/man1 share/doc/qemu

PYTHON_FOR_BUILD_ONLY=	tool

do-build:
	${RUN}cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		ninja -j ${_MAKE_JOBS_N:U1} -C build

# Some dependencies aren't correct and this tries to be re-made on install,
# failing due to configure bugs.
post-build:
	${TOUCH} ${WRKSRC}/config-host.mak

do-install:
	${RUN}cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${INSTALL_ENV} \
		ninja -j ${_MAKE_JOBS_N:U1} -C build install
	# not needed for guest agent
	${RM} -f ${DESTDIR}${PREFIX}/include/qemu-plugin.h
	${RM} -f ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/qemu.1
	${RM} -f ${DESTDIR}${PREFIX}/${PKGMANDIR}/man7/qemu-block-drivers.7
	${RM} -f ${DESTDIR}${PREFIX}/${PKGMANDIR}/man7/qemu-cpu-models.7
	${RM} -f ${DESTDIR}${PREFIX}/${PKGMANDIR}/man7/qemu-qmp-ref.7
	${RM} -rf ${DESTDIR}${PREFIX}/share/doc/qemu
	${RM} -rf ${DESTDIR}${PREFIX}/share/qemu/keymaps
	${RM} -rf ${DESTDIR}${PREFIX}/share/qemu/trace-events-all

do-test:
	${RUN}cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${TEST_ENV} \
		ninja -j ${_MAKE_JOBS_N:U1} -C build test

.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
