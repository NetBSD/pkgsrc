# $NetBSD: Makefile,v 1.12 1999/02/20 22:48:42 hubertf Exp $
#

DISTNAME=		SSLeay-0.9.0b
# Lower case differentiates the new (shared lib) pkg from the old one.
# Since the directory name is lower case, it should stay this way.
PKGNAME=		ssleay-0.9.0b
CATEGORIES=		devel security
MASTER_SITES=		ftp://psych.psy.uq.oz.au/pub/Crypto/SSL/

MAINTAINER=		explorer@netbsd.org
HOMEPAGE=		http://www.psy.uq.oz.au/~ftp/Crypto/

NOT_FOR_ARCHS=		alpha *64

USE_PERL5=		yes

RESTRICTED=		"Crypto; export-controlled"
MIRROR_DISTFILE=	no

USE_LIBTOOL=		yes
HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	util/NetBSD.sh
CONFIGURE_ARGS=		${MACHINE_ARCH}
CONFIGURE_ENV+=		PREFIX=${PREFIX} LOCALBASE=${LOCALBASE}

PLIST_SRC=	${PKGDIR}/PLIST

.include "../../mk/bsd.prefs.mk"

.if defined(USE_RSAREF2) && ${USE_RSAREF2} == YES
DEPENDS=		rsaref-2.0:../../security/rsaref
CONFIGURE_ENV+=		USE_RSAREF_DEF=-DRSAref
MAKE_ENV+=		USE_RSAREF=YES
LDFLAGS+=		-L${PREFIX}/lib -lrsaref
.endif

fetch-depends:
.if !defined(USE_RSAREF2) || ${USE_RSAREF2} != YES && ${USE_RSAREF2} != NO
	@${ECHO}
	@${ECHO} The variable USE_RSAREF2 must be set to either YES or NO
	@${ECHO} in order to build this package.  People with no RSA
	@${ECHO} license MUST set this variable to YES.  Users outside
	@${ECHO} the USA MUST set this variable to NO.  RSA licensees may
	@${ECHO} choose -- NO is faster.
	@${FALSE}
.endif

post-extract:
	@${CP} -f ${FILESDIR}/NetBSD.sh ${WRKSRC}/util/
	@chmod +x ${WRKSRC}/util/NetBSD.sh

post-configure:
.if defined(USE_RSAREF2) && ${USE_RSAREF2} == YES
	@${CP} ${WRKSRC}/rsaref/rsaref.h ${WRKSRC}/include/rsaref.h
.endif
	@cd ${WRKSRC}/perl && PREFIX=${PREFIX} ${PREFIX}/bin/perl Makefile.PL

post-build:
	@cd ${WRKSRC}/perl && ${MAKE}

do-install:
	${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/apps/ssleay ${PREFIX}/bin/
	@cd ${PREFIX}/bin && ${SH} ${WRKSRC}/apps/mklinks
	cd ${WRKSRC}/tools && ${INSTALL_SCRIPT} \
		c_hash c_info c_issuer c_name c_rehash ${PREFIX}/bin/
	${SED} -e s,/usr/local,${PREFIX}, ${WRKSRC}/apps/der_chop >${WRKDIR}/der_chop && \
		${INSTALL_SCRIPT} ${WRKDIR}/der_chop ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/apps/CA.sh ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/apps/ssleay.cnf ${PREFIX}/etc/ssleay.cnf.example
	@${LIBTOOL} ${INSTALL_DATA} ${WRKSRC}/libcrypto.la ${PREFIX}/lib/
	@${LIBTOOL} ${INSTALL_DATA} ${WRKSRC}/libssl.la ${PREFIX}/lib/
	${INSTALL_DATA_DIR} ${PREFIX}/include/ssleay
	cd ${WRKSRC}/include && ${INSTALL_DATA} \
		asn1.h asn1_mac.h bio.h blowfish.h bn.h bss_file.c \
		buffer.h cast.h conf.h cryptall.h cryptlib.h crypto.h \
		des.h dh.h dsa.h e_os.h err.h evp.h hmac.h idea.h lhash.h \
		md2.h md5.h mdc2.h objects.h pem.h pkcs7.h rand.h rc2.h \
		rc4.h rc5.h ripemd.h rsa.h sha.h ssl.h ssl2.h ssl23.h \
		ssl3.h stack.h tls1.h txt_db.h x509.h x509_vfy.h \
		${PREFIX}/include/ssleay/
	${LN} -sf ../etc/ssleay.cnf ${PREFIX}/lib/ssleay.cnf
	@cd ${WRKSRC}/perl && ${MAKE} install
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ssleay
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/ssleay
	${INSTALL_DATA_DIR} ${PREFIX}/certs ${PREFIX}/private
	@if [ ! -f ${PREFIX}/etc/ssleay.cnf ]; then \
		${CP} -p ${PREFIX}/etc/ssleay.cnf.example ${PREFIX}/etc/ssleay.cnf; \
	fi

.include  "../../mk/bsd.pkg.mk"
