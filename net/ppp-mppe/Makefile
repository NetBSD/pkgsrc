# $NetBSD: Makefile,v 1.27 2004/10/07 02:01:38 jlam Exp $

DISTNAME=	ppp-2.3.9
PKGNAME=	ppp-mppe-2.3.9
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	ftp://cs.anu.edu.au/pub/software/ppp/

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://www.moretonbay.com/vpn/releases/
COMMENT=	PPP daemon and LKM with MPPE - Microsoft Point-to-Point Encryption

CONFLICTS+=	ppp-2.*

ONLY_FOR_PLATFORM=	NetBSD-*-*

HAS_CONFIGURE=  yes
MANCOMPRESSED_IF_MANZ=	yes

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	MANINSTALL

OPENSSL_VERS=	0.9.6m
OPENSSL_SRC=	${PKGSRCDIR}/security/openssl/${WRKDIR:T}/openssl-${OPENSSL_VERS}

post-extract:
	if [ ! -r ${OPENSSL_SRC}/crypto/rc4 ]; then			\
		cd ../../security/openssl && ${MAKE} extract;		\
	fi
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

pre-clean:
	cd ../../security/openssl && ${MAKE} clean

SYSDIR?=	${BSDSRCDIR}/sys
MAKE_ENV+=	SYSDIR="${SYSDIR}"

# until PR 5377 is addressed, we need kernel src around to build lkm's
pre-build:
.if !exists(${SYSDIR}/lib/libkern/libkern.h)
	@${ECHO} "This package requires the kernel source to build its lkm."
	@${ECHO} "Install it in ${SYSDIR} or set the SYSDIR variable to its location."
	@${FALSE}
.endif

.include "../../mk/bsd.pkg.mk"

.for OPT in ${MANINSTALL}
PLIST_SRC+=	${PKGDIR}/PLIST.${OPT}
.endfor
