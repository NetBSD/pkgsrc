# $NetBSD: Makefile,v 1.49 2001/11/29 01:12:46 hubertf Exp $

DISTNAME=		openssl-0.9.6
PKGREVISION=		2
SVR4_PKGNAME=		ossl
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.openssl.org/source/ \
			ftp://ftp.uni-trier.de/pub/unix/security/openssl/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.openssl.org/
COMMENT=		Secure Socket Layer and cryptographic library

BUILD_DEPENDS+=		perl>=${PERL5_REQD}:../../lang/perl5

CONFLICTS=		SSLeay-[0-9]* ssleay-[0-9]* base64-[0-9]* \
			glimpse-[0-9]

CRYPTO=			YES

# openssl supplies IDEA/RC5.  IDEA/RC5 need license for commercial use.
LICENCE=		fee-based-commercial-use

# matches what's in `Configure' (except sparc64)
ONLY_FOR_PLATFORM=	NetBSD-*-alpha NetBSD-*-arm32 NetBSD-*-i386 \
			NetBSD-*-m68k NetBSD-*-mips NetBSD-*-mipseb \
			NetBSD-*-mipsel NetBSD-*-ns32k NetBSD-*-powerpc \
			NetBSD-*-sparc NetBSD-*-vax \
			SunOS-* Linux-*-*

CONFIGURE_SCRIPT=	config
CONFIGURE_ARGS=		-fPIC -DPIC --openssldir=${PREFIX} --prefix=${PREFIX} \
			${LDFLAGS}
CONFIGURE_ENV=		CC="${CC}"

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
PATCH_SITES=		${MASTER_SITE_LOCAL}
PATCHFILES=		openssl-0.9.6-20010914-netbsd.patch.gz

MAKE_ENV=		LD_LIBRARY_PATH=${WRKSRC} MAKELIB=${FILESDIR}/makelib
.endif

PLIST_SRC=		${WRKDIR}/.PLIST_SRC

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

# The Perl stuff doesn't work yet (nor did it work properly in SSLeay...)
do-configure:
	@cd ${WRKSRC} && ${PERL5} util/perlpath.pl ${LOCALBASE}/bin
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} \
	  ${CONFIGURE_ARGS}

#post-build:
#	@cd ${WRKSRC}/perl && ${MAKE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/apps/openssl ${PREFIX}/bin
	@cd ${PREFIX}/bin && \
	for file in asn1parse base64 bf bf-cbc bf-cfb bf-ecb bf-ofb ca \
	cast cast-cbc cast5-cbc cast5-cfb cast5-ecb cast5-ofb ciphers crl \
	crl2pkcs7 des des-cbc des-cfb des-ecb des-ede des-ede-cbc des-ede-cfb \
	des-ede-ofb des-ede3 des-ede3-cbc des-ede3-cfb des-ede3-ofb \
	des-ofb des3 desx dgst dh dsa dsaparam enc errstr gendh gendsa \
	genrsa idea idea-cbc idea-cfb idea-ecb idea-ofb md2 mdc2 nseq \
	pkcs12 pkcs7 pkcs8 rc2 rc2-cbc rc2-cfb rc2-ecb rc2-ofb rc4 rc5 \
	rc5-cbc rc5-cfb rc5-ecb rc5-ofb req rmd160 rsa s_client s_server \
	s_time sess_id sha sha1 speed verify version x509; do \
		${RM} -f $$file ; \
		${LN} -sf openssl $$file; \
	done
	cd ${WRKSRC}/tools && ${INSTALL_SCRIPT} \
		c_hash c_info c_issuer c_name c_rehash ${PREFIX}/bin
	${SED} -e s,/usr/local,${PREFIX}, ${WRKSRC}/apps/der_chop >${WRKDIR}/der_chop && \
		${INSTALL_SCRIPT} ${WRKDIR}/der_chop ${PREFIX}/bin
	cd ${WRKSRC}/apps && ${INSTALL_SCRIPT} CA.sh CA.pl ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/apps/openssl.cnf ${PREFIX}/etc/openssl.cnf.example
	cd ${WRKSRC} && ${INSTALL_DATA} libcrypto.a libssl.a ${PREFIX}/lib
.if ${OPSYS} == "NetBSD"
	cd ${WRKSRC} && ${INSTALL_DATA} libcrypto.so.200.0 libssl.so.200.0 ${PREFIX}/lib
.if ${OBJECT_FMT} == "ELF"
.for shared_lib in libcrypto.so.200.0 libssl.so.200.0
	cd ${PREFIX}/lib && ${LN} -s ${shared_lib} ${shared_lib:R} && \
		${LN} -s ${shared_lib} ${shared_lib:R:R}
.endfor
.endif
.endif
.if exists(/usr/bin/ranlib)
	/usr/bin/ranlib ${PREFIX}/lib/libcrypto.a
	/usr/bin/ranlib ${PREFIX}/lib/libssl.a
.endif
.if defined(USE_RSAREF2) && ${USE_RSAREF2} == YES
	# libRSAglue.a is only useful if you are using the RSAREF2 library.
	cd ${WRKSRC} && ${INSTALL_DATA} libRSAglue.a ${PREFIX}/lib
.endif
	${INSTALL_DATA_DIR} ${PREFIX}/include/openssl
	cd ${WRKSRC}/include/openssl && \
	for file in \
	asn1.h asn1_mac.h bio.h blowfish.h bn.h buffer.h cast.h comp.h conf.h \
	crypto.h des.h dh.h dsa.h e_os.h e_os2.h ebcdic.h err.h evp.h hmac.h \
	idea.h lhash.h md2.h md4.h md5.h mdc2.h obj_mac.h objects.h \
	opensslconf.h opensslv.h pem.h pem2.h pkcs12.h pkcs7.h rand.h rc2.h \
	rc4.h rc5.h ripemd.h rsa.h safestack.h sha.h ssl.h ssl2.h ssl23.h \
	ssl3.h stack.h symhacks.h tls1.h tmdiff.h txt_db.h x509.h x509_vfy.h \
	x509v3.h ; do \
		${INSTALL_DATA} $$file ${PREFIX}/include/openssl; \
	done
#	@cd ${WRKSRC}/perl && ${MAKE} install
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/openssl
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/openssl/apps
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/openssl/crypto
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/openssl/ssl
	${INSTALL_DATA} ${WRKSRC}/doc/apps/* \
		${PREFIX}/share/doc/openssl/apps
	${INSTALL_DATA} ${WRKSRC}/doc/crypto/* \
		${PREFIX}/share/doc/openssl/crypto
	${INSTALL_DATA} ${WRKSRC}/doc/ssl/* \
		${PREFIX}/share/doc/openssl/ssl
	for file in README c-indentation.el openssl.txt openssl_button.gif \
	openssl_button.html ssleay.txt ; do \
		${INSTALL_DATA} ${WRKSRC}/doc/$$file \
			${PREFIX}/share/doc/openssl; \
	done
	${INSTALL_DATA_DIR} ${PREFIX}/certs
	${INSTALL_DATA_DIR} ${PREFIX}/private
	@if [ ! -f ${PREFIX}/etc/openssl.cnf ]; then \
		${CP} -p ${PREFIX}/etc/openssl.cnf.example ${PREFIX}/etc/openssl.cnf; \
	fi

post-install:
	${CAT} ${PKGDIR}/PLIST.common ${PKGDIR}/PLIST.${LOWER_OPSYS} \
		${PLIST_RSAREF} > ${PLIST_SRC}

.include  "../../mk/bsd.pkg.mk"

test: all
	@cd ${WRKSRC}/test && ${SETENV} LD_LIBRARY_PATH=${WRKSRC} \
		MAKELIB=${FILESDIR}/makelib ${MAKE} tests
	@${ECHO} "*** Tests successful. ***"
