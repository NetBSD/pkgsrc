# $NetBSD: Makefile,v 1.1 2024/06/28 18:35:17 wiz Exp $

.include "../../lang/gcc14/Makefile.common"

PKGNAME=	${GCC_PKGNAME}-libjit-${GCC14_DIST_VERSION}
COMMENT=	GNU Compiler Collection 14 (gcclibjit library)

# /usr/bin/ld: ./../intl/libintl.a(bindtextdom.o): relocation R_X86_64_32 against symbol `libintl_nl_default_dirname' can not be used when making a shared object; recompile with -fPIC
CFLAGS+=	-fPIC

INSTALLATION_DIRS=	lib

CONFIGURE_ARGS+=	--enable-languages=jit
CONFIGURE_ARGS+=	--without-static-standard-libraries
CONFIGURE_ARGS+=	--disable-bootstrap
CONFIGURE_ARGS+=	--enable-host-shared

MAKE_FLAGS+=		BOOT_CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=		BOOT_CXXFLAGS=${CXXFLAGS:Q}
MAKE_FLAGS+=		BOOT_LDFLAGS=${LDFLAGS:Q}
MAKE_FLAGS+=		LDFLAGS_FOR_TARGET=${LDFLAGS:Q}
MAKE_FLAGS+=		CFLAGS=${CFLAGS:Q}

BUILD_TARGET=		all-gcc

INSTALL_DIRS=		${WRKSRC}/${OBJDIR}/gcc
INSTALL_TARGET=		jit.install-common jit.install-info

.include "../../mk/bsd.pkg.mk"
