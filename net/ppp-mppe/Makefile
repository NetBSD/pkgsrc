# $NetBSD: Makefile,v 1.2 1999/12/08 13:57:42 rh Exp $

DISTNAME=	ppp-2.3.9
PKGNAME=	ppp-mppe-2.3.9
CATEGORIES=	net
MASTER_SITES=	ftp://cs.anu.edu.au/pub/software/ppp/

MAINTAINER=	dbj@netbsd.org
HOMEPAGE=	http://www.moretonbay.com/vpn/releases/

OPENSSL_VER=	0.9.4

BUILD_DEPENDS= ${BUILD_ROOT}/security/openssl/${WRKDIR:T}/openssl-${OPENSSL_VER}/crypto/rc4:../../security/openssl:extract

HAS_CONFIGURE=  yes
MANCOMPRESSED_IF_MANZ=	yes

post-extract:
	@${MKDIR} ${WRKSRC}/netbsd-1.4
	@${CP} ${BUILD_ROOT}/security/openssl/${WRKDIR:T}/openssl-${OPENSSL_VER}/crypto/sha/sha.h ${WRKSRC}/pppd/sha.h
	@${CP} ${BUILD_ROOT}/security/openssl/${WRKDIR:T}/openssl-${OPENSSL_VER}/crypto/sha/sha1dgst.c ${WRKSRC}/pppd/sha1dgst.c
	@${CP} ${BUILD_ROOT}/security/openssl/${WRKDIR:T}/openssl-${OPENSSL_VER}/crypto/sha/sha_locl.h ${WRKSRC}/pppd/sha_locl.h
	@${CP} ${BUILD_ROOT}/security/openssl/${WRKDIR:T}/openssl-${OPENSSL_VER}/crypto/opensslv.h ${WRKSRC}/pppd/opensslv.h
	@${CP} ${BUILD_ROOT}/security/openssl/${WRKDIR:T}/openssl-${OPENSSL_VER}/crypto/rc4/rc4_skey.c ${WRKSRC}/netbsd-1.4/rc4_skey.c
	@${CP} ${BUILD_ROOT}/security/openssl/${WRKDIR:T}/openssl-${OPENSSL_VER}/crypto/rc4/rc4.h ${WRKSRC}/netbsd-1.4/rc4.h
	@${CP} ${BUILD_ROOT}/security/openssl/${WRKDIR:T}/openssl-${OPENSSL_VER}/crypto/rc4/rc4_locl.h ${WRKSRC}/netbsd-1.4/rc4_locl.h
	@${CP} ${BUILD_ROOT}/security/openssl/${WRKDIR:T}/openssl-${OPENSSL_VER}/crypto/rc4/rc4_enc.c ${WRKSRC}/netbsd-1.4/rc4_enc.c
	@${CP} ${BUILD_ROOT}/security/openssl/${WRKDIR:T}/openssl-${OPENSSL_VER}/crypto/opensslv.h ${WRKSRC}/netbsd-1.4/opensslv.h
	@${CP} ${BUILD_ROOT}/security/openssl/${WRKDIR:T}/openssl-${OPENSSL_VER}/crypto/sha/sha1dgst.c ${WRKSRC}/netbsd-1.4/sha1dgst.c
	@${CP} ${BUILD_ROOT}/security/openssl/${WRKDIR:T}/openssl-${OPENSSL_VER}/crypto/sha/sha_locl.h ${WRKSRC}/netbsd-1.4/sha_locl.h
	@${CP} ${BUILD_ROOT}/security/openssl/${WRKDIR:T}/openssl-${OPENSSL_VER}/crypto/sha/sha.h ${WRKSRC}/netbsd-1.4/sha.h
	@${MV} ${WRKSRC}/pppd/md4.h ${WRKSRC}/pppd/md4.h.hide
	@${MV} ${WRKSRC}/pppd/md5.h ${WRKSRC}/pppd/md5.h.hide

pre-install:
	${INSTALL_PROGRAM_DIR} ${PREFIX}/lkm

SYSDIR?=/sys
MAKE_ENV+=		SYSDIR="${SYSDIR}"

# until PR 5377 is addressed, we need kernel src around to build lkm's
pre-build:
.if !exists(${SYSDIR}/lib/libkern/libkern.h)
	@${ECHO} "This package requires the kernel source to build its lkm."
	@${ECHO} "Install it in ${SYSDIR} or set the SYSDIR variable to its location."
	@${FALSE}
.endif

.include "../../mk/bsd.pkg.mk"
