# $NetBSD: Makefile,v 1.301 2024/06/05 07:47:33 adam Exp $

# Remember to upload-distfiles when updating OpenSSL -- otherwise it
# is not possible for users who have bootstrapped without OpenSSL
# to install it and enable HTTPS fetching.
DISTNAME=	openssl-3.3.1
CATEGORIES=	security
MASTER_SITES=	https://www.openssl.org/source/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.openssl.org/
COMMENT=	Secure Socket Layer and cryptographic library
LICENSE=	openssl

USE_GCC_RUNTIME=	yes

USE_TOOLS+=		fgrep gmake perl
USE_TOOLS.SunOS+=	gm4
BUILD_TARGET=		depend all
TEST_TARGET=		test

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./config
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--libdir=lib
CONFIGURE_ARGS+=	--openssldir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	shared
MAKE_FLAGS+=		MANSUFFIX=
MAKE_FLAGS+=		MANDIR=${PREFIX}/${PKGMANDIR}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" && \
	((${MACHINE_ARCH} == "arm") || \
	(${MACHINE_ARCH} == "hppa") || \
	(${MACHINE_ARCH} == "i386") || \
	(${MACHINE_ARCH} == "m68k") || \
	(${MACHINE_ARCH} == "mips") || \
	(${MACHINE_ARCH} == "powerpc") || \
	(${MACHINE_ARCH} == "riscv32") || \
	(${MACHINE_ARCH} == "sh3eb") || \
	(${MACHINE_ARCH} == "sh3el") || \
	(${MACHINE_ARCH} == "sparc") || \
	(${MACHINE_ARCH} == "vax"))
# Use OpenSSL's built-in fallbacks (not actually clang-specific)
# see src/crypto/external/bsd/openssl/lib/libcrypto/arch/*/crypto.inc
CFLAGS+=		-DBROKEN_CLANG_ATOMICS	# no atomic 64 bit ops
.endif

.if ${MACHINE_PLATFORM:MDarwin-[0-8].*-powerpc}
# No {get,make,set}context support before Darwin 9
CONFIGURE_ARGS+=	no-async
.endif

.if ${OPSYS} == "Darwin" && ${OPSYS_VERSION} < 101200
# While it does check for this, it does so using a header that is only
# available in OS X versions starting with Leopard.
CFLAGS+=		-DOPENSSL_NO_APPLE_CRYPTO_RANDOM=1
.endif

PLIST_VARS+=		devcrypto afalg
# the AF_ALG engine is supported only on Linux, where it
# is used instead of the BSD /dev/crypto engine.
.if ${OPSYS} == "Linux"
PLIST.afalg=		yes
.endif
.if exists(/dev/crypto) && ${OPSYS} != "SunOS"
PLIST.devcrypto=	yes
.else
CONFIGURE_ARGS+=	no-devcryptoeng
.endif

# Fix 64-bit build on at least Mac OS X Snow Leopard
.if ${OPSYS} == "Darwin" && ${MACHINE_ARCH} == "x86_64"
CONFIGURE_ENV+=		KERNEL_BITS=${ABI}
.endif

.if ${USE_CROSS_COMPILE:tl} == "yes"

OPENSSL_ARCH.aarch64=	arm64
OPENSSL_ARCH.x86_64=	amd64
CONFIGURE_ENV+=		MACHINE=${OPENSSL_ARCH.${MACHINE_ARCH}:U${MACHINE_GNU_ARCH}:Q}
CONFIGURE_ENV+=		RELEASE=${OS_VERSION:Q}
CONFIGURE_ENV+=		SYSTEM=${OPSYS:Q}
CONFIGURE_ENV+=		BUILD=${OPSYS:Q}\ ${OS_VERSION:Q}

# We don't carry a runtime dependency on Perl, but OpenSSL does provide
# a Perl script that you can use if you do install Perl.
SUBST_CLASSES+=			perlcross
SUBST_MESSAGE.perlcross=	Fixing Perl interpreter path for cross-build
SUBST_STAGE.perlcross=		pre-install
SUBST_FILES.perlcross+=		tools/c_rehash
SUBST_FILES.perlcross+=		apps/CA.pl
SUBST_FILES.perlcross+=		apps/tsget.pl
SUBST_SED.perlcross=		-e s,${PERL5:Q},${LOCALBASE:Q}/bin/perl5,g
CHECK_INTERPRETER_SKIP+=	bin/c_rehash

.endif                         # USE_CROSS_COMPILE

.include "options.mk"

CONFIGURE_ENV+=		PERL=${PERL5:Q}

# If the config script cannot guess the host system correctly then we need to
# specify it manually and call the Configure script directly.
OPENSSL_HOST.SunOS-i386=	solaris-x86-gcc
.if ${PKGSRC_COMPILER:Msunpro}
OPENSSL_HOST.SunOS-x86_64=	solaris64-x86_64-cc
.else
OPENSSL_HOST.SunOS-x86_64=	solaris64-x86_64-gcc
.endif
OPENSSL_HOST.Darwin-aarch64=	darwin64-arm64-cc

# Ensure consistent socket interfaces are used across the codebase.
CPPFLAGS.SunOS+=	-D_XOPEN_SOURCE=600 -D__EXTENSIONS__

LDFLAGS.SunOS+=		-lrt
CPPFLAGS.OpenBSD+=	-D__STDC_NO_ATOMICS__

.if defined(OPENSSL_HOST.${OPSYS}-${MACHINE_ARCH})
CONFIG_SHELL=		${PERL5}
CONFIGURE_SCRIPT=	./Configure
CONFIGURE_ARGS+=	${OPENSSL_HOST.${OPSYS}-${MACHINE_ARCH}}
.endif

PKGCONFIG_OVERRIDE+=		libcrypto.pc libssl.pc openssl.pc
PKGCONFIG_OVERRIDE_STAGE=	post-build

PKG_SYSCONFSUBDIR=	openssl
CONF_FILES=		${PREFIX}/share/examples/openssl/openssl.cnf	\
			${PKG_SYSCONFDIR}/openssl.cnf
OWN_DIRS=		${PKG_SYSCONFDIR}/certs ${PKG_SYSCONFDIR}/private

INSTALLATION_DIRS+=	share/examples/openssl

#
# Note that this package cannot be updated solely from Darwin, it relies on
# shlib-dylib.awk to convert the normal .so entries to dylib, which doesn't
# work the other way around.  The lib/engines-1.1 plugins also need special
# handling.
#
OPSYSVARS+=		SOEXT
SOEXT.Darwin=		dylib
SOEXT.*=		so
PLIST_SUBST+=		SOEXT=${SOEXT}

PRINT_PLIST_AWK+=	/^lib\/engines/ { gsub(/\.${SOEXT}$$/, ".$${SOEXT}"); }

# Remove CC from the environment, to fix GCC version handling on HP-UX,
# SunOS and Linux/sparc.
#
# See https://github.com/openssl/openssl/issues/11060.
do-configure:
	${RUN} cd ${WRKSRC} && ${SETENV} ${_CONFIGURE_SCRIPT_ENV:NCC=*}	\
		${CONFIG_SHELL} ${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}

#
# Get rid of ridiculous namespace collisions like passwd.1 and just leave the
# openssl-*.1 style variants.  On a more practical note this avoids creating
# a conflict with moreutils (ts.1).
#
post-install:
	cd ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1;			\
	for f in openssl-*; do						\
		${RM} -f `${ECHO} $${f} | ${SED} -e 's/openssl-//'`;	\
	done
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/*				\
		${DESTDIR}${PREFIX}/share/examples/openssl

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
