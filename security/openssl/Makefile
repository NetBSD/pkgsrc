# $NetBSD: Makefile,v 1.80 2003/09/22 03:15:33 grant Exp $

DISTNAME=		openssl-0.9.6g
PKGREVISION=		2
SVR4_PKGNAME=		ossl
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.openssl.org/source/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.openssl.org/
COMMENT=		Secure Socket Layer and cryptographic library

USE_PERL5=		build

CONFLICTS=		SSLeay-[0-9]* ssleay-[0-9]* base64-[0-9]*	\
			glimpse-[0-9]

CRYPTO=			YES

# openssl supplies IDEA/RC5.  IDEA/RC5 need license for commercial use.
LICENCE=		fee-based-commercial-use

.include "../../mk/bsd.prefs.mk"

USE_BUILDLINK2=		YES
USE_PKGINSTALL=		YES
HAS_CONFIGURE=		YES
CONFIGURE_SCRIPT=	./config
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--openssldir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	shared

.if defined(USE_RSAREF2) && ${USE_RSAREF2} == "YES"
.  include "../../security/rsaref/buildlink2.mk"
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

PLIST_SRC=		${PKGDIR}/PLIST.${LOWER_OPSYS:C/([.0-9]*)$//}
PLIST_SRC+=		${PLIST_RSAREF}
PLIST_SRC+=		${PKGDIR}/PLIST.common

PKG_SYSCONFSUBDIR=	openssl
CONF_FILES=		${PREFIX}/share/examples/openssl/openssl.cnf	\
			${PKG_SYSCONFDIR}/openssl.cnf
OWN_DIRS=		${PKG_SYSCONFDIR}/certs ${PKG_SYSCONFDIR}/private

.if ${OPSYS} == "NetBSD"
PKG_SYSCONFDIR.${PKGBASE}?=	/etc/openssl
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
