# $NetBSD: Makefile,v 1.96 2004/10/03 00:18:11 tv Exp $

DISTNAME=		openssl-0.9.6m
PKGREVISION=	1
SVR4_PKGNAME=		ossl
CATEGORIES=		security
MASTER_SITES=		http://mirrors.isc.org/pub/openssl/source/ \
			http://www.mirrors.wiretapped.net/security/cryptography/libraries/tls/openssl/ \
			http://sunsite.rediris.es/pub/mirror/OpenSSL/ \
			http://ftp.wayne.edu/pub/openssl/source/ \
			http://www.binarycode.org/openssl/source/ \
			ftp://ftp.openssl.org/source/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.openssl.org/
COMMENT=		Secure Socket Layer and cryptographic library

CONFLICTS=		SSLeay-[0-9]* ssleay-[0-9]*

CRYPTO=			YES

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../../mk/compiler.mk"
.include "../../mk/bsd.prefs.mk"

USE_PERL5=		build
USE_BUILDLINK3=		YES
USE_PKGINSTALL=		YES
HAS_CONFIGURE=		YES
CONFIGURE_SCRIPT=	./config
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--openssldir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	shared
# IDEA, RC5, and MDC2 are disabled due to licensing and/or patent issues.
CONFIGURE_ARGS+=	no-idea no-rc5 no-mdc2

# Global and legacy options
.if defined(USE_RSAREF2) && !empty(USE_RSAREF2:M[yY][eE][sS])
PKG_DEFAULT_OPTIONS+=	rsaref
.endif

PKG_OPTIONS_VAR=	PKG_OPTIONS.openssl
PKG_SUPPORTED_OPTIONS=	rsaref
.include "../../mk/bsd.options.mk"

###
### Use the RSA reference package instead of the built-in code for the
### RSA algorithm (NOT RECOMMENDED!).
###
.if !empty(PKG_OPTIONS:Mrsaref)
.  include "../../security/rsaref/buildlink3.mk"
CONFIGURE_ARGS+=	rsaref
PLIST_RSAREF=		${PKGDIR}/PLIST.rsaref
.endif

.if ${OPSYS} == "SunOS" && ${MACHINE_ARCH} == "sparc"
CONFIGURE_SCRIPT=	./Configure
.  if !empty(CC:M*gcc*)
CONFIGURE_ARGS+=	solaris-${SPARC_TARGET_ARCH}-gcc
.  else
CONFIGURE_ARGS+=	solaris-${SPARC_TARGET_ARCH}-cc
.  endif
.elif ${OPSYS} == "IRIX"
CONFIGURE_ARGS+=	no-asm
.  if ${ABI} == "64"
CONFIGURE_SCRIPT=	./Configure
CONFIGURE_ARGS+=	irix64-mips4-cc
.  endif
.endif

CONFIGURE_ARGS+=	${CFLAGS} ${LDFLAGS}
CONFIGURE_ENV+=		PERL="${PERL5}"
CONFIGURE_ENV+=		MACHINE_ARCH=${MACHINE_ARCH}

PLIST_OPSYS=		${PKGDIR}/PLIST.${LOWER_OPSYS:C/([.0-9]*)$//}	
.if exists(${PLIST_OPSYS})
PLIST_SHLIB=		${PLIST_OPSYS}
.else
PLIST_SHLIB=		${PKGDIR}/PLIST.shlib
.endif

PLIST_SRC=		${PLIST_SHLIB}
PLIST_SRC+=		${PLIST_RSAREF}
PLIST_SRC+=		${PKGDIR}/PLIST.common

PKG_SYSCONFSUBDIR=	openssl
CONF_FILES=		${PREFIX}/share/examples/openssl/openssl.cnf	\
			${PKG_SYSCONFDIR}/openssl.cnf
OWN_DIRS=		${PKG_SYSCONFDIR}/certs ${PKG_SYSCONFDIR}/private

.if ${OPSYS} == "NetBSD"
PKG_SYSCONFDIR.openssl?=	/etc/openssl
.  if !exists(/usr/libexec/ld.elf_so) && !exists(/usr/libexec/ld.so)
PKG_FAIL_REASON=	${PKGNAME} requires shared object support
.  endif
.endif

.if ${OPSYS} == "Darwin"
LD_PATH_VARNAME=	DYLD_LIBRARY_PATH
.else
LD_PATH_VARNAME=	LD_LIBRARY_PATH
.endif
TEST_ENV+=		${LD_PATH_VARNAME}=${WRKSRC}
TEST_TARGET=		tests

pre-configure:
	cd ${WRKSRC} && ${PERL5} util/perlpath.pl ${PERL5}

.include  "../../mk/bsd.pkg.mk"
