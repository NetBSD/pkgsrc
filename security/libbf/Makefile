# $NetBSD: Makefile,v 1.3 2001/02/17 17:49:47 wiz Exp $
#

DISTNAME=	libbf-0.8.2b
WRKSRC=		${WRKDIR}/bf
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.psy.uq.oz.au/pub/Crypto/libeay/ \
		ftp://ftp.funet.fi/pub/mirrors/ftp.psy.uq.oz.au/libeay/ \
		ftp://ftp.ntnu.no/pub/unix/security/ \
		ftp://ftp.sunsite.org.uk/Mirrors/ftp.psy.uq.oz.au/pub/Crypto/libeay/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.counterpane.com/blowfish.html
COMMENT=	blowfish block cipher library

CRYPTO=		YES

.include "../../mk/bsd.prefs.mk"

.if ${LOWER_ARCH} == "i386" && ${OBJECT_FMT} == "ELF"
BF_ENC=asm/bx86-elf.o
.else
BF_ENC=bf_enc.o
.endif

MAKEFLAGS+=	BF_ENC=${BF_ENC}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/blowfish
	cd ${WRKSRC} &&							\
	${INSTALL_DATA} libblowfish.a ${PREFIX}/lib &&			\
	${INSTALL_DATA} blowfish.h ${PREFIX}/include &&			\
	${INSTALL_PROGRAM} bftest bfspeed ${PREFIX}/bin
.for doc in blowfish.doc COPYRIGHT README VERSION
	${INSTALL_DATA} ${WRKSRC}/${doc} ${PREFIX}/share/doc/blowfish
.endfor

.include "../../mk/bsd.pkg.mk"
