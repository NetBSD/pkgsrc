# $NetBSD: Makefile,v 1.1 2024/07/22 20:01:49 tnn Exp $

DISTNAME=		espressif-binutils-gdb-${GITHUB_TAG}
PKGNAME=		xtensa-esp-elf-binutils-2.41.0
CATEGORIES=		cross
MASTER_SITES=		${MASTER_SITE_GITHUB:=espressif/}
GITHUB_PROJECT=		binutils-gdb
GITHUB_TAG=		esp-2.41.0_20240305

# Espressif overlays
DISTFILES=	${DEFAULT_DISTFILES}
DISTFILES+=	crosstool-NG-esp-13.2.0_20240530-src.tar.xz
SITES.crosstool-NG-esp-13.2.0_20240530-src.tar.xz=	-https://github.com/espressif/crosstool-NG/releases/download/esp-13.2.0_20240530/crosstool-NG-esp-13.2.0_20240530-src.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/espressif/binutils-gdb
COMMENT=	Cross binutils for Espressif ESP32 bare metal environment
LICENSE=	gnu-gpl-v2 AND gnu-gpl-v3 AND gnu-lgpl-v2 AND gnu-lgpl-v3

INFO_FILES=		yes
GNU_CONFIGURE=		yes
GNU_CONFIGURE_STRICT=	no # several sub-configures know --enable-nls
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake makeinfo bison
MKPIE_SUPPORTED=	no	# strange errors with libiberty. checking for fcntl.h ... no

TOOL_DEPENDS+=		gtexinfo>=5.1:../../devel/gtexinfo
_TOOLS_USE_PKGSRC.makeinfo=	yes

OBJDIR=			../build
CONFIGURE_DIRS=		${OBJDIR}
CONFIGURE_SCRIPT=	${WRKSRC}/configure
GNU_CONFIGURE_PREFIX=	${PREFIX}/xtensa-esp-elf

CONFIGURE_ARGS+=	--disable-werror
CONFIGURE_ARGS+=	--target=xtensa-esp-elf
CONFIGURE_ARGS+=	--enable-multilib
CONFIGURE_ARGS+=	--disable-nls
CONFIGURE_ARGS+=	--disable-gdb

CHECK_SHLIBS_SKIP+=		xtensa-esp-elf/lib/xtensa*.so
CHECK_PORTABILITY_SKIP+=	sim/testsuite/bfin/run-tests.sh

SUBST_CLASSES+=		prefix
SUBST_FILES.prefix=	bfd/xtensa-dynconfig.c
SUBST_STAGE.prefix=	 pre-configure
SUBST_MESSAGE.prefix=	Substitute GNU_CONFIGURE_PREFIX in patch
SUBST_VARS.prefix+=	GNU_CONFIGURE_PREFIX

pre-configure:
	${RUN} cd ${WRKSRC} && ${MKDIR} ${OBJDIR}

pre-build:
	${RUN} cd ${WRKDIR}/crosstool-NG-esp-13.2.0_20240530-src/xtensa-dynconfig && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} CONF_DIR=${WRKDIR}/crosstool-NG-esp-13.2.0_20240530-src/overlays

post-install:
	set -e; for f in ${WRKDIR}/crosstool-NG-esp-13.2.0_20240530-src/xtensa-dynconfig/*.so; do	\
		${INSTALL_PROGRAM} $$f ${DESTDIR}${GNU_CONFIGURE_PREFIX}/lib;				\
	done

.include "../../mk/bsd.pkg.mk"
