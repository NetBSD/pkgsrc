# $NetBSD: Makefile,v 1.76 2003/08/25 16:34:00 jschauma Exp $

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

USE_BUILDLINK2=		YES
USE_PKGINSTALL=		YES
CONFIGURE_SCRIPT=	config
CONFIGURE_ARGS=		shared --openssldir=${PKG_SYSCONFDIR} --prefix=${PREFIX}
CONFIGURE_ENV=		CC="${CC}" PERL="${PERL5}"

PLIST_SRC=		${PKGDIR}/PLIST.${LOWER_OPSYS:C/([.0-9]*)$//}
PLIST_SRC+=		${PLIST_RSAREF}
PLIST_SRC+=		${PKGDIR}/PLIST.common

PKG_SYSCONFSUBDIR=	openssl
CONF_FILES=		${PREFIX}/share/examples/openssl/openssl.cnf	\
			${PKG_SYSCONFDIR}/openssl.cnf
OWN_DIRS=		${PKG_SYSCONFDIR}/certs ${PKG_SYSCONFDIR}/private

SEDFILES=		Configure Makefile.org Makefile.ssl 		\
			apps/Makefile.ssl crypto/Makefile.ssl		\
			ssl/Makefile.ssl test/Makefile.ssl

post-patch:
	for i in ${SEDFILES}; do					\
		${SED} -e "s/@MAKE@/${MAKE}/" ${WRKSRC}/$$i > 		\
			${WRKSRC}/$$i.tmp && 				\
		${MV} ${WRKSRC}/$$i.tmp ${WRKSRC}/$$i;			\
	done;

do-configure:
	cd ${WRKSRC}							\
		&& ${PERL5} util/perlpath.pl ${PERL5}			\
		&& ${SETENV} ${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT}	\
			${CONFIGURE_ARGS}

do-test:
	@cd ${WRKSRC}/test 						\
		&& ${SETENV} ${LD_PATH_VARNAME}=${WRKSRC}		\
			${MAKE_PROGRAM} tests	\
		&& ${ECHO} "*** Tests successful. ***"

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
PATCH_SITES=		${MASTER_SITE_LOCAL}
PATCHFILES=		openssl-0.9.6g-20020810-netbsd.patch.gz

PKG_SYSCONFDIR.${PKGBASE}?=	/etc/openssl

.  if !exists(/usr/libexec/ld.elf_so) && !exists(/usr/libexec/ld.so)
PKG_FAIL_REASON=	${PKGNAME} requires shared object support
.  endif
.endif	# ${OPSYS} == "NetBSD"

.if ${OPSYS} == "Darwin"
LD_PATH_VARNAME=	DYLD_LIBRARY_PATH
.else
LD_PATH_VARNAME=	LD_LIBRARY_PATH
.endif

.if defined(USE_RSAREF2) && ${USE_RSAREF2} == "YES"
.  include "../../security/rsaref/buildlink2.mk"
CONFIGURE_ARGS+=	rsaref -L${BUILDLINK_PREFIX.rsaref}/lib
PLIST_RSAREF=		${PKGDIR}/PLIST.rsaref
.endif

.if ${OPSYS} == "SunOS" && ${MACHINE_ARCH} == "sparc"
CONFIGURE_SCRIPT=	Configure
.  if !empty(CC:M*gcc*)
CONFIGURE_ARGS+=	solaris-${SPARC_TARGET_ARCH}-gcc
.  else
CONFIGURE_ARGS+=	solaris-${SPARC_TARGET_ARCH}-cc
.  endif
.elif ${OPSYS} == "IRIX"
CONFIGURE_ARGS+=	no-asm
.  if ${ABI} == "64"
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ARGS+=	irix64-mips4-cc
.  endif
.endif

.include  "../../mk/bsd.pkg.mk"
