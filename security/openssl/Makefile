# $NetBSD: Makefile,v 1.8 1999/08/24 07:46:41 simonb Exp $
#

DISTNAME=		openssl-0.9.2b
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.openssl.org/source/

PATCH_SITES=		${MASTER_SITES}
PATCHFILES=		openssl-0.9.2b-rsaoaep.patch

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.openssl.org/

CONFLICTS=		SSLeay-* ssleay-*

USE_PERL5=		yes

RESTRICTED=		"Crypto; export-controlled"
MIRROR_DISTFILE=	no
# matches what's in `Configure' (except sparc64)
ONLY_FOR_PLATFORM=	NetBSD-*-alpha NetBSD-*-arm32 NetBSD-*-i386 \
			NetBSD-*-m68k NetBSD-*-mips NetBSD-*-mipseb \
			NetBSD-*-mipsel NetBSD-*-ns32k NetBSD-*-powerpc \
			NetBSD-*-sparc NetBSD-*-vax

CONFIGURE_ARGS=		-fPIC -DPIC ${LDFLAGS}
#CONFIGURE_ENV=		PREFIX=${PREFIX}
MAKE_ENV=		LD_LIBRARY_PATH=${WRKSRC} MAKELIB=${FILESDIR}/makelib

.if !exists(/usr/libexec/ld.elf_so) && !exists(/usr/libexec/ld.so)
IGNORE=			requires shared object support
.endif

.include "../../mk/bsd.prefs.mk"

.if defined(USE_RSAREF2) && ${USE_RSAREF2} == YES
DEPENDS=		rsaref-2.0p2:../../security/rsaref
CONFIGURE_ARGS+=	-DRSAref -L${PREFIX}/lib -lrsaref ${LDFLAGS}
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

# The Perl stuff doesn't work yet (nor did it work properly in SSLeay...)
do-configure:
	@cd ${WRKSRC} && ${LOCALBASE}/bin/perl util/perlpath.pl ${LOCALBASE}/bin
	@cd ${WRKSRC} && ${LOCALBASE}/bin/perl util/ssldir.pl ${PREFIX}
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ./config ${CONFIGURE_ARGS}
#	@cd ${WRKSRC}/perl && ${SETENV} ${CONFIGURE_ENV} ${LOCALBASE}/bin/perl \
#		Makefile.PL

#post-build:
#	@cd ${WRKSRC}/perl && ${MAKE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/apps/openssl ${PREFIX}/bin/
	@cd ${PREFIX}/bin && \
	for file in asn1parse base64 bf bf-cbc bf-cfb bf-ecb bf-ofb ca \
	cast cast-cbc cast5-cbc cast5-cfb cast5-ecb cast5-ofb ciphers crl \
	crl2pkcs7 des des-cbc des-cfb des-ecb des-ede des-ede-cbc des-ede-cfb \
	des-ede-ofb des-ede3 des-ede3-cbc des-ede3-cfb des-ede3-ofb \
	des-ofb des3 desx dgst dh dsa dsaparam enc errstr gendh gendsa \
	genrsa idea idea-cbc idea-cfb idea-ecb idea-ofb md2 mdc2 nseq \
	pkcs7 rc2 rc2-cbc rc2-cfb rc2-ecb rc2-ofb rc4 rc5 rc5-cbc rc5-cfb \
	rc5-ecb rc5-ofb req rmd160 rsa s_client s_server s_time sess_id \
	sha sha1 verify x509 ssleay; do \
		${LN} -sf openssl $$file; \
	done
	cd ${WRKSRC}/tools && ${INSTALL_SCRIPT} \
		c_hash c_info c_issuer c_name c_rehash ${PREFIX}/bin/
	${SED} -e s,/usr/local,${PREFIX}, ${WRKSRC}/apps/der_chop >${WRKDIR}/der_chop && \
		${INSTALL_SCRIPT} ${WRKDIR}/der_chop ${PREFIX}/bin/
	cd ${WRKSRC}/apps && ${INSTALL_SCRIPT} CA.sh CA.pl ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/apps/openssl.cnf ${PREFIX}/etc/openssl.cnf.example
	cd ${WRKSRC} && \
		${INSTALL_DATA} libcrypto.so.?.0 libssl.so.?.0 ${PREFIX}/lib/
	${INSTALL_DATA_DIR} ${PREFIX}/include/openssl
	cd ${WRKSRC}/include && \
	for file in asn1.h asn1_mac.h bio.h blowfish.h bn.h buffer.h \
	cast.h comp.h conf.h cryptall.h crypto.h des.h dh.h dsa.h err.h \
	evp.h hmac.h idea.h lhash.h md2.h md5.h mdc2.h objects.h \
	opensslv.h pem.h pem2.h pkcs7.h rand.h rc2.h rc4.h rc5.h ripemd.h \
	rsa.h sha.h ssl.h ssl2.h ssl23.h ssl3.h stack.h tls1.h tmdiff.h \
	txt_db.h x509.h x509_vfy.h x509v3.h; do \
		${INSTALL_DATA} $$file ${PREFIX}/include/openssl/; \
	done
#	@cd ${WRKSRC}/perl && ${MAKE} install
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/openssl
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/openssl
	${INSTALL_DATA_DIR} ${PREFIX}/certs ${PREFIX}/private
	@if [ ! -f ${PREFIX}/etc/openssl.cnf ]; then \
		${CP} -p ${PREFIX}/etc/openssl.cnf.example ${PREFIX}/etc/openssl.cnf; \
	fi

.include  "../../mk/bsd.pkg.mk"

test: all
	@cd ${WRKSRC}/test && ${SETENV} LD_LIBRARY_PATH=${WRKSRC} ${MAKE} tests
	@${ECHO} "*** Tests successful. ***"
