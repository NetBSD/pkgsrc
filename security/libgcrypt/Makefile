# $NetBSD: Makefile,v 1.116 2025/03/03 21:32:27 nia Exp $

DISTNAME=	libgcrypt-1.11.0
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNUPG:=libgcrypt/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gnupg.org/software/libgcrypt/
COMMENT=	GNU cryptographic library
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
TEST_TARGET=		check
TEXINFO_REQD+=		4.0
INFO_FILES=		yes

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mclang)
CFLAGS+=		-fheinous-gnu-extensions
.endif

# Parts of the code actively reject optimisation.  The configure script
# strips out most flags but oddly does not handle -O so do it ourselves.
CFLAGS:=		${CFLAGS:C/^-O$//g}

SUBST_CLASSES+=		rpath
SUBST_FILES.rpath=	src/libgcrypt-config.in
SUBST_STAGE.rpath=	pre-configure
SUBST_MESSAGE.rpath=	Fixing rpath flags
SUBST_VARS.rpath=	COMPILER_RPATH_FLAG

PKGCONFIG_OVERRIDE+=	src/libgcrypt.pc.in

.include "options.mk"

.if ${USE_CROSS_COMPILE:tl} == "yes"
CONFIGURE_ARGS+=	CC_FOR_BUILD=${NATIVE_CC:Q}

# libgpg-error installs scripts in the _target_ system, that are
# expected to be run on the _build_ system when compiling downstream
# dependencies like libgcrypt.  I don't see a way to use pkg-config or
# anything reasonable to override this, so, we do the nonsense thing
# instead.
CONFIGURE_ARGS+=	GPGRT_CONFIG=${CROSS_DESTDIR:Q}${PREFIX}/bin/gpgrt-config
CONFIGURE_ARGS+=	GPG_ERROR_CONFIG=${CROSS_DESTDIR:Q}${PREFIX}/bin/gpg-error-config
.endif

.if ${OPSYS} == "Darwin"
# Their ASM is broken on Darwin and leads to undefined symbols at runtime.
CONFIGURE_ARGS+=	--disable-asm
.  if ${OPSYS_VERSION} < 100500
.    include "../../devel/macports-legacy-support/buildlink3.mk"
.  endif
.endif

.if ${MACHINE_PLATFORM:MDarwin-*-powerpc}
CPPFLAGS+=	-D__powerpc__
.endif

BUILDLINK_API_DEPENDS.libgpg-error+=	libgpg-error>=1.13
.include "../../security/libgpg-error/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
