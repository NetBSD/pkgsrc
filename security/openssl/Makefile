# $NetBSD: Makefile,v 1.101 2005/02/02 23:43:42 jlam Exp $

OPENSSL_SNAPSHOT?=	# empty
OPENSSL_STABLE?=	# empty
OPENSSL_VERS?=		0.9.7e

.if empty(OPENSSL_SNAPSHOT)
DISTNAME=	openssl-${OPENSSL_VERS}
PKGREVISION=	1
MASTER_SITES=	http://mirrors.isc.org/pub/openssl/source/ \
		http://www.mirrors.wiretapped.net/security/cryptography/libraries/tls/openssl/ \
		http://sunsite.rediris.es/pub/mirror/OpenSSL/ \
		http://ftp.wayne.edu/pub/openssl/source/ \
		http://www.binarycode.org/openssl/source/ \
		ftp://ftp.openssl.org/source/
.else
.  if !empty(OPENSSL_STABLE:M[yY][eE][sS])
DISTNAME=	openssl-${OPENSSL_VERS:C/[a-z]$//}-stable-SNAP-${OPENSSL_SNAPSHOT}
PKGNAME=	openssl-${OPENSSL_VERS}beta${OPENSSL_SNAPSHOT}
MASTER_SITES=	ftp://ftp.openssl.org/snapshot/
.  else
DISTNAME=	openssl-SNAP-${OPENSSL_SNAPSHOT}
PKGNAME=	openssl-${OPENSSL_VERS}alpha${OPENSSL_SNAPSHOT}
MASTER_SITES=	ftp://ftp.openssl.org/snapshot/
.  endif
.endif

SVR4_PKGNAME=	ossl
CATEGORIES=	security
MAINTAINER=	jlam@NetBSD.org
HOMEPAGE=	http://www.openssl.org/
COMMENT=	Secure Socket Layer and cryptographic library

CONFLICTS=	SSLeay-[0-9]* ssleay-[0-9]*

CRYPTO=		yes

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../../mk/bsd.prefs.mk"
.include "../../mk/compiler.mk"

USE_PERL5=		build	# perl is used throughout the build
USE_BUILDLINK3=		yes
USE_PKGINSTALL=		yes
USE_GNU_TOOLS+=		make
TEST_TARGET=		tests

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./config
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--openssldir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	shared

# IDEA, RC5, and MDC2 are disabled due to licensing and/or patent issues.
CONFIGURE_ARGS+=	no-idea no-rc5 no-mdc2

.if ${OPSYS} == "SunOS" && ${MACHINE_ARCH} == "sparc"
CONFIGURE_SCRIPT=	./Configure
.  if !empty(CC_VERSION:Mgcc*)
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

PLIST_OPSYS=		${PKGDIR}/PLIST.${LOWER_OPSYS:C/([.0-9]*)$//}
.if exists(${PLIST_OPSYS})
PLIST_SHLIB=		${PLIST_OPSYS}
.else
PLIST_SHLIB=		${PKGDIR}/PLIST.shlib
.endif
PLIST_SRC=		${PLIST_SHLIB}
PLIST_SRC+=		${PKGDIR}/PLIST.common
PLIST_SUBST+=		SHLIB_VERSION=${OPENSSL_VERS:C/[^0-9]*$//}
PLIST_SUBST+=		SHLIB_MAJOR=${OPENSSL_VERS:C/\..*$//}

.if ${OPSYS} == "NetBSD"
PKG_SYSCONFDIR.openssl?=	/etc/openssl
.endif

PKG_SYSCONFSUBDIR=	openssl
CONF_FILES=		${PREFIX}/share/examples/openssl/openssl.cnf	\
			${PKG_SYSCONFDIR}/openssl.cnf
OWN_DIRS=		${PKG_SYSCONFDIR}/certs ${PKG_SYSCONFDIR}/private

pre-configure:
	cd ${WRKSRC} && ${PERL5} util/perlpath.pl ${PERL5}

.include  "../../mk/bsd.pkg.mk"
