# $NetBSD: Makefile,v 1.55 2002/08/10 04:50:31 fredb Exp $

DISTNAME=		openssl-0.9.6g
SVR4_PKGNAME=		ossl
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.openssl.org/source/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.openssl.org/
COMMENT=		Secure Socket Layer and cryptographic library

USE_PERL5=		build

CONFLICTS=		SSLeay-[0-9]* ssleay-[0-9]* base64-[0-9]*	\
			glimpse-[0-9]

CRYPTO=			YES

# openssl supplies IDEA/RC5.  IDEA/RC5 need license for commercial use.
LICENCE=		fee-based-commercial-use

CONFIGURE_SCRIPT=	config
CONFIGURE_ARGS=		shared --openssldir=${PKG_SYSCONFDIR} --prefix=${PREFIX}
CONFIGURE_ENV=		CC="${CC}"

PLIST_SRC=		${PKGDIR}/PLIST.${LOWER_OPSYS}
PLIST_SRC+=		${PLIST_RSAREF}
PLIST_SRC+=		${PKGDIR}/PLIST.common

PKG_SYSCONFSUBDIR=	openssl
CONF_FILES=		${PREFIX}/share/examples/openssl/openssl.cnf	\
			${PKG_SYSCONFDIR}/openssl.cnf
OWN_DIRS=		${PKG_SYSCONFDIR}/certs ${PKG_SYSCONFDIR}/private

do-configure:
	cd ${WRKSRC}							\
		&& ${PERL5} util/perlpath.pl ${PERL5}			\
		&& ${SETENV} ${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT}	\
			${CONFIGURE_ARGS}

test: all
	@cd ${WRKSRC}/test 						\
		&& ${SETENV} ${LD_PATH_VARNAME}=${WRKSRC}		\
			${MAKE_PROGRAM} tests	\
		&& ${ECHO} "*** Tests successful. ***"

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
PATCH_SITES=		${MASTER_SITE_LOCAL}
PATCHFILES=		openssl-0.9.6g-20020810-netbsd.patch.gz

PKG_SYSCONFDIR.${PKGBASE}?=	/etc/openssl
.endif

.if ${OPSYS} == "Darwin"
LD_PATH_VARNAME=	DYLD_LIBRARY_PATH
.else
LD_PATH_VARNAME=	LD_LIBRARY_PATH
.endif

.if ${OPSYS} == "NetBSD" && !exists(/usr/libexec/ld.elf_so) && !exists(/usr/libexec/ld.so)
IGNORE=			${PKGNAME} requires shared object support
.endif

.if defined(USE_RSAREF2) && ${USE_RSAREF2} == YES
DEPENDS=		rsaref-2.0p3:../../security/rsaref
CONFIGURE_ARGS+=	rsaref
PLIST_RSAREF=		${PKGDIR}/PLIST.rsaref
.endif

.if (${OPSYS} == SunOS) && (${MACHINE_ARCH} == sparc)
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ARGS+=	solaris-${SPARC_TARGET_ARCH}-${CC}
.endif

.include  "../../mk/bsd.pkg.install.mk"
.include  "../../mk/bsd.pkg.mk"
