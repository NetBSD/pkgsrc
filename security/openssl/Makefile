# $NetBSD: Makefile,v 1.281 2022/06/21 18:48:39 jperkin Exp $

# Remember to upload-distfiles when updating OpenSSL -- otherwise it
# is not possible for users who have bootstrapped without OpenSSL
# to install it and enable HTTPS fetching.
DISTNAME=	openssl-1.1.1p
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
TEST_TARGET=		tests

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./config
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib
CONFIGURE_ARGS+=	--openssldir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	shared

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MDarwin-[0-8].*-powerpc)
# No {get,make,set}context support before Darwin 9
CONFIGURE_ARGS+=	no-async
.endif

# Fix 64-bit build on at least Mac OS X Snow Leopard
.if ${OPSYS} == "Darwin" && ${MACHINE_ARCH} == "x86_64"
CONFIGURE_ENV+=		KERNEL_BITS=${ABI}
.endif

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
		${RM} -f $${f};						\
		${MV} `${ECHO} $${f} | ${SED} -e 's/openssl-//'` $${f};	\
	done;								\
	${RM} -f openssl-c_rehash.1;					\
	${LN} -s openssl-rehash.1 c_rehash.1

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
