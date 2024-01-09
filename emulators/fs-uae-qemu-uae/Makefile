# $NetBSD: Makefile,v 1.2 2024/01/09 12:57:05 wiz Exp $

DISTNAME=	qemu-uae-3.8.6
PKGNAME=	fs-uae-${DISTNAME}
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=FrodeSolheim/}
GITHUB_PROJECT=	qemu-uae
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/FrodeSolheim/qemu-uae/
COMMENT=	FS-UAE plugin for PPC and networking support
LICENSE=	gnu-gpl-v2

DEPENDS+=	fs-uae>=3.1.66nb4:../../emulators/fs-uae

HAS_CONFIGURE=		yes
USE_TOOLS+=		pkg-config
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake

CFLAGS+=	-DQEMU_UAE
CFLAGS+=	-fPIC

CONFIGURE_ARGS+=	--target-list=ppc-softmmu
CONFIGURE_ARGS+=	--disable-tools \
			--disable-werror \
			--disable-strip \
			--disable-sdl \
			--disable-stack-protector \
			--disable-gtk \
			--disable-virtfs \
			--disable-vnc \
			--disable-xen \
			--disable-brlapi \
			--disable-curses \
			--disable-curl \
			--disable-rdma \
			--disable-user \
			--disable-uuid \
			--disable-vde \
			--disable-netmap \
			--disable-cap-ng \
			--disable-attr \
			--disable-docs \
			--disable-vhost-net \
			--disable-spice \
			--disable-libiscsi \
			--disable-libnfs \
			--disable-smartcard-nss \
			--disable-libusb \
			--disable-lzo \
			--disable-snappy \
			--disable-guest-agent \
			--disable-seccomp \
			--disable-glusterfs \
			--disable-tpm \
			--disable-libssh2 \
			--disable-vhdx \
			--disable-quorum \
			--disable-numa \
			--disable-coroutine-pool \
			--enable-pie \
			--with-system-pixman \
			--disable-linux-aio

PYTHON_VERSIONS_ACCEPTED=	27

INSTALLATION_DIRS=	share/fs-uae/plugins

do-install:
	${INSTALL_LIB} ${WRKSRC}/qemu-uae.so \
		${DESTDIR}${PREFIX}/share/fs-uae/plugins

.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dtc/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
