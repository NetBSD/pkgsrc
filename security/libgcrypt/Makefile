# $NetBSD: Makefile,v 1.99 2020/10/31 13:51:24 wiz Exp $

DISTNAME=	libgcrypt-1.8.7
CATEGORIES=	security
MASTER_SITES=	https://gnupg.org/ftp/gcrypt/libgcrypt/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gnupg.org/software/libgcrypt/
COMMENT=	GNU cryptographic library
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

TEST_TARGET=		check

TEXINFO_REQD=		4.0
INFO_FILES=		yes

.include "../../mk/bsd.prefs.mk"
.include "../../mk/compiler.mk"

.if empty(MACHINE_PLATFORM:MNetBSD-*-i386) && \
    empty(MACHINE_PLATFORM:MNetBSD-*-alpha) && \
    empty(MACHINE_PLATFORM:MNetBSD-*-sparc) && \
    empty(MACHINE_PLATFORM:M*-*-hppa)
CONFIGURE_ARGS+=	--disable-asm
.endif
CONFIGURE_ARGS+=	--disable-aesni-support

.if !empty(MACHINE_PLATFORM:MLinux-*-i386) || \
    !empty(MACHINE_PLATFORM:MSunOS-*-i386)
CONFIGURE_ARGS+=	--disable-pclmul-support
.endif

# SCO OpenServer 5.0.7/3.2 has no socklen_t, but it is defined in pthread.h
# from builtin GNU pth.
.if ${OS_VARIANT} == "SCOOSR5"
CONFIGURE_ENV+=		ac_cv_type_socklen_t=yes
CONFIGURE_ENV+=		gl_cv_socklen_t_equiv=int
.endif

.if !empty(PKGSRC_COMPILER:Mclang)
CFLAGS+=		-fheinous-gnu-extensions
.endif

.if (${MACHINE_ARCH} == "x86_64")
.  if !empty(CC_VERSION:Mgcc-4.[45].*)
CONFIGURE_ARGS+=	--disable-avx2-support
CONFIGURE_ARGS+=	--disable-avx-support
CONFIGURE_ENV+=		gcry_cv_gcc_inline_asm_avx=no
.  endif
.endif

SUBST_CLASSES+=		rpath
SUBST_FILES.rpath=	src/libgcrypt-config.in
SUBST_STAGE.rpath=	pre-configure
SUBST_MESSAGE.rpath=	Fixing rpath flags
SUBST_VARS.rpath=	COMPILER_RPATH_FLAG

.include "options.mk"

BUILDLINK_API_DEPENDS.libgpg-error+=	libgpg-error>=1.13
.include "../../security/libgpg-error/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
