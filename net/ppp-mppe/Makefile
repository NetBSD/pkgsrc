# $NetBSD: Makefile,v 1.5 2000/10/21 22:50:53 wiz Exp $

DISTNAME=	ppp-2.3.9
PKGNAME=	ppp-mppe-2.3.9
CATEGORIES=	net
MASTER_SITES=	ftp://cs.anu.edu.au/pub/software/ppp/

MAINTAINER=	dbj@netbsd.org
HOMEPAGE=	http://www.moretonbay.com/vpn/releases/

OPENSSL_VERS=	0.9.5a
OPENSSL_SRC=	${BUILD_ROOT}/security/openssl/${WRKDIR:T}/openssl-${OPENSSL_VERS}

BUILD_DEPENDS= ${OPENSSL_SRC}/crypto/rc4:../../security/openssl:extract

HAS_CONFIGURE=  yes
MANCOMPRESSED_IF_MANZ=	yes

post-extract:
	@${LN} -sf ${OPENSSL_SRC}/include/openssl ${WRKSRC}/pppd/openssl
	@${CP} ${OPENSSL_SRC}/crypto/md32_common.h ${WRKSRC}/pppd/md32_common.h
	@${CP} ${OPENSSL_SRC}/crypto/sha/sha.h ${WRKSRC}/pppd/sha.h
	@${CP} ${OPENSSL_SRC}/crypto/sha/sha1dgst.c ${WRKSRC}/pppd/sha1dgst.c
	@${CP} ${OPENSSL_SRC}/crypto/sha/sha_locl.h ${WRKSRC}/pppd/sha_locl.h
	@${MV} ${WRKSRC}/pppd/md4.h ${WRKSRC}/pppd/md4.h.hide
	@${MV} ${WRKSRC}/pppd/md5.h ${WRKSRC}/pppd/md5.h.hide

	@${MKDIR} ${WRKSRC}/netbsd-1.4
	@${CP} ${OPENSSL_SRC}/crypto/rc4/rc4_skey.c ${WRKSRC}/netbsd-1.4/rc4_skey.c
	@${CP} ${OPENSSL_SRC}/crypto/rc4/rc4.h ${WRKSRC}/netbsd-1.4/rc4.h
	@${CP} ${OPENSSL_SRC}/crypto/rc4/rc4_locl.h ${WRKSRC}/netbsd-1.4/rc4_locl.h
	@${CP} ${OPENSSL_SRC}/crypto/rc4/rc4_enc.c ${WRKSRC}/netbsd-1.4/rc4_enc.c
	@${CP} ${OPENSSL_SRC}/crypto/sha/sha1dgst.c ${WRKSRC}/netbsd-1.4/sha1dgst.c
	@${CP} ${OPENSSL_SRC}/crypto/sha/sha_locl.h ${WRKSRC}/netbsd-1.4/sha_locl.h
	@${CP} ${OPENSSL_SRC}/crypto/sha/sha.h ${WRKSRC}/netbsd-1.4/sha.h

pre-install:
	${INSTALL_PROGRAM_DIR} ${PREFIX}/lkm

SYSDIR?=	/sys
MAKE_ENV+=	SYSDIR="${SYSDIR}"

# until PR 5377 is addressed, we need kernel src around to build lkm's
pre-build:
.if !exists(${SYSDIR}/lib/libkern/libkern.h)
	@${ECHO} "This package requires the kernel source to build its lkm."
	@${ECHO} "Install it in ${SYSDIR} or set the SYSDIR variable to its location."
	@${FALSE}
.endif

.include "../../mk/bsd.pkg.mk"
