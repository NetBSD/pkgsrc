# $NetBSD: Makefile,v 1.201 2015/01/08 16:58:25 wiz Exp $

DISTNAME=	openssl-1.0.1k
MASTER_SITES=	http://ftp.openssl.org/source/
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.openssl.org/
COMMENT=	Secure Socket Layer and cryptographic library
LICENSE=	openssl

CONFLICTS=	SSLeay-[0-9]* ssleay-[0-9]*

CRYPTO=		yes

BUILD_DEPENDS+=	{p5-Perl4-CoreLibs-[0-9]*,perl<5.16}:../../devel/p5-Perl4-CoreLibs

USE_GCC_RUNTIME=	yes

.include "../../mk/bsd.prefs.mk"
.include "../../mk/compiler.mk"

USE_TOOLS+=		fgrep gmake perl
TEST_TARGET=		tests
MAKE_JOBS_SAFE=		no

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./config
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--install_prefix=${DESTDIR}
CONFIGURE_ARGS+=	--openssldir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	shared no-fips

.if ${OPSYS} == "SunOS"
.  if ${MACHINE_ARCH} == "sparc"
OPENSSL_MACHINE_ARCH=	${SPARC_TARGET_ARCH}
.  elif ${MACHINE_ARCH} == "i386"
OPENSSL_MACHINE_ARCH=	x86
.  elif ${MACHINE_ARCH} == "x86_64"
OPENSSL_MACHINE_ARCH=	${MACHINE_ARCH}
.  endif
# only override the configure target if we know the platform, falling
# back to ./config's autodetection if not.
.  if defined(OPENSSL_MACHINE_ARCH) && !empty(OPENSSL_MACHINE_ARCH)
CONFIGURE_SCRIPT=	./Configure
.    if !empty(CC_VERSION:Mgcc*)
CONFIGURE_ARGS+=	solaris${${ABI}==64:?64:}-${OPENSSL_MACHINE_ARCH}-gcc
.    else
CONFIGURE_ARGS+=	solaris${${ABI}==64:?64:}-${OPENSSL_MACHINE_ARCH}-cc
.    endif
.  endif
.elif ${OPSYS} == "IRIX"
CONFIGURE_ARGS+=	no-asm
.  if ${ABI} == "64"
CONFIGURE_SCRIPT=	./Configure
.    if !empty(CC_VERSION:Mgcc*)
CONFIGURE_ARGS+=	irix64-mips4-gcc
.    else
CONFIGURE_ARGS+=	irix64-mips4-cc
.    endif
.  endif
.elif ${OPSYS} == "OSF1"
USE_PLIST_SHLIB=	no
CONFIGURE_SCRIPT=	./Configure
.  if !empty(CC_VERSION:Mgcc*)
CONFIGURE_ARGS+=	tru64-alpha-gcc
.  else
CONFIGURE_ARGS+=	tru64-alpha-cc
.  endif
.elif ${OPSYS} == "Darwin"
CONFIGURE_SCRIPT=	./Configure
.  if defined(ABI) && ${ABI} == "64"
CONFIGURE_ARGS+=	darwin64-${MACHINE_ARCH}-cc
.  elif ${MACHINE_ARCH} == "powerpc"
CONFIGURE_ARGS+=	darwin-ppc-cc
.  else
CONFIGURE_ARGS+=	darwin-${MACHINE_ARCH}-cc
.  endif

.include "../../mk/dlopen.buildlink3.mk"

SUBST_CLASSES+=		dl
SUBST_MESSAGE.dl=	Adding dynamic link compatibility library.
SUBST_STAGE.dl=		post-configure
SUBST_FILES.dl=		Makefile apps/Makefile crypto/Makefile \
			crypto/pkcs7/Makefile test/Makefile
SUBST_SED.dl=		-e 's,^EX_LIBS=,EX_LIBS=${DL_LDFLAGS:Q} ,g'

.elif ${OPSYS} == "AIX"
CONFIGURE_SCRIPT=      ./Configure
.if defined(ABI) && ${ABI} == "64"
.if !empty(CC_VERSION:Mgcc*)
CONFIGURE_ARGS+=       aix64-gcc
.else
CONFIGURE_ARGS+=       aix64-cc
.endif
.else
.if !empty(CC_VERSION:Mgcc*)
CONFIGURE_ARGS+=       aix-gcc
.else
CONFIGURE_ARGS+=       aix-cc
.endif
.endif
.elif ${OPSYS} == "Interix"

SUBST_CLASSES+=		soname
SUBST_STAGE.soname=	post-configure
SUBST_FILES.soname=	Makefile.shared
SUBST_SED.soname=	-e 's/-Wl,-soname=/-Wl,-h,/g'

.elif ${OPSYS} == "HPUX"

CONFIGURE_SCRIPT=	./Configure

.  if ${ABI} == "64"
.    if ${MACHINE_ARCH} == "hppa"
CONFIGURE_ARGS+=	hpux64-parisc2-${CC}
.    else
CONFIGURE_ARGS+=	hpux64-ia64-${CC}
.    endif
.  else
.    if ${MACHINE_ARCH} == "hppa"
CONFIGURE_ARGS+=	hpux-parisc-${CC}
.    else
CONFIGURE_ARGS+=	hpux-ia64-${CC}
.    endif
.  endif
.elif ${OPSYS} == "Linux"
.  if ${MACHINE_ARCH} == "powerpc64"
CONFIGURE_SCRIPT=	./Configure
CONFIGURE_ARGS+=	linux-ppc64
.  endif
.elif ${OS_VARIANT} == "SCOOSR5"
# SIGILL in _sha1_block_data_order_ssse3().
CONFIGURE_ARGS+=	no-sse2
.endif

.include "../../security/openssl/options.mk"

CONFIGURE_ARGS+=	${CFLAGS} ${LDFLAGS}
CONFIGURE_ENV+=		PERL=${PERL5:Q}

PKGCONFIG_OVERRIDE+=		libcrypto.pc libssl.pc openssl.pc
PKGCONFIG_OVERRIDE_STAGE=	post-build

PLIST_SRC+=		${PKGDIR}/PLIST.common
USE_PLIST_SHLIB?=	yes
.if ${USE_PLIST_SHLIB} == "yes"
PLIST_SRC+=		${PKGDIR}/PLIST.shlib
.endif
PLIST_SUBST+=		SHLIB_VERSION=${OPENSSL_VERS:C/[^0-9]*$//}
PLIST_SUBST+=		SHLIB_MAJOR=${OPENSSL_VERS:C/\..*$//}

PKG_SYSCONFSUBDIR=	openssl
CONF_FILES=		${PREFIX}/share/examples/openssl/openssl.cnf	\
			${PKG_SYSCONFDIR}/openssl.cnf
OWN_DIRS=		${PKG_SYSCONFDIR}/certs ${PKG_SYSCONFDIR}/private

INSTALLATION_DIRS+=	share/examples/openssl

# Fix the path to perl in various scripts.
pre-configure:
	cd ${WRKSRC} && ${PERL5} util/perlpath.pl ${PERL5}

.include "../../mk/bsd.pkg.mk"
