# $NetBSD: Makefile,v 1.53 2002/08/04 15:47:43 fredb Exp $

DISTNAME=		openssl-0.9.6e
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

CONF_FILES=		${PREFIX}/share/examples/openssl/openssl.cnf	\
			${PKG_SYSCONFDIR}/openssl.cnf
PKG_SYSCONFSUBDIR=	openssl
PLIST_SRC=		${WRKDIR}/.PLIST_SRC
PLIST_SUBST=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

do-configure:
	cd ${WRKSRC}							\
		&& ${PERL5} util/perlpath.pl ${LOCALBASE}/bin		\
		&& ${SETENV} ${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT}	\
			${CONFIGURE_ARGS}

post-build:
	${CAT} ${PKGDIR}/PLIST.${LOWER_OPSYS} ${PLIST_RSAREF}		\
		${PKGDIR}/PLIST.common  > ${PLIST_SRC}

test: all
	@cd ${WRKSRC}/test 						\
		&& ${SETENV} ${LD_PATH_VARNAME}=${WRKSRC} ${MAKE} tests	\
		&& ${ECHO} "*** Tests successful. ***"

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
PATCH_SITES=		${MASTER_SITE_LOCAL}
PATCHFILES=		openssl-0.9.6e-20020804-netbsd.patch.gz
PATCH_DIST_STRIP=	-p1

PKG_SYSCONFBASE=	/etc
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

.include  "../../mk/bsd.pkg.mk"
