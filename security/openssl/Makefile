# $NetBSD: Makefile,v 1.125 2007/05/03 14:23:42 tron Exp $

OPENSSL_SNAPSHOT?=	# empty
OPENSSL_STABLE?=	# empty
OPENSSL_VERS?=		0.9.7i

.if empty(OPENSSL_SNAPSHOT)
DISTNAME=	openssl-${OPENSSL_VERS}
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

PKGREVISION=	3
SVR4_PKGNAME=	ossl
CATEGORIES=	security
MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.openssl.org/
COMMENT=	Secure Socket Layer and cryptographic library

CONFLICTS=	SSLeay-[0-9]* ssleay-[0-9]*

CRYPTO=		yes

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../../mk/bsd.prefs.mk"
.include "../../mk/compiler.mk"

USE_TOOLS+=		gmake perl
TEST_TARGET=		tests

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./config
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--openssldir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	shared

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
CONFIGURE_ARGS+=	solaris-${OPENSSL_MACHINE_ARCH}-gcc
.    else
CONFIGURE_ARGS+=	solaris-${OPENSSL_MACHINE_ARCH}-cc
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
.elif ${OPSYS} == "Darwin"
.include "../../mk/dlopen.buildlink3.mk"

SUBST_CLASSES+=		dl
SUBST_MESSAGE.dl=	Adding dynamic link compatibility library.
SUBST_STAGE.dl=		post-configure
SUBST_FILES.dl=		Makefile apps/Makefile crypto/Makefile \
			crypto/pkcs7/Makefile fips/Makefile test/Makefile
SUBST_SED.dl=		-e "s,^EX_LIBS=,EX_LIBS=${DL_LDFLAGS} ,g"
.endif

.include "../../security/openssl/options.mk"

CONFIGURE_ARGS+=	${CFLAGS} ${LDFLAGS}
CONFIGURE_ENV+=		PERL=${PERL5:Q}

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

# Some shells don't accept empty word lists in for loops.  For those
# Makefiles where this occurs, edit the file so that we avoid running
# the loop.
#
# Also, fix the path to perl in various scripts.
#
pre-configure:
	cd ${WRKSRC};							\
	for file in fips/*/Makefile; do					\
		if ${GREP} "^EXHEADER=[ 	]*$$" $$file >/dev/null; then \
			${ECHO} "Fixing 'install' target in $$file.";	\
			${MV} -f $$file $$file.preawk;			\
			${AWK} '/^install:/ { printf "install:\n\nnot-install:\n"; next } { print }' \
				$$file.preawk > $$file;			\
		fi;							\
	done
	cd ${WRKSRC} && ${PERL5} util/perlpath.pl ${PERL5}

.include "../../mk/bsd.pkg.mk"
