# $NetBSD: Makefile,v 1.17 2016/01/24 16:14:45 jperkin Exp $
#

DISTNAME=	libbf-0.8.2b
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.funet.fi/pub/mirrors/ftp.psy.uq.oz.au/libeay/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.schneier.com/blowfish.html
COMMENT=	Blowfish block cipher library

WRKSRC=		${WRKDIR}/bf
CRYPTO=		YES

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386" && ${OBJECT_FMT} == "ELF"
BF_ENC=asm/bx86-elf.o
.else
BF_ENC=bf_enc.o
.endif

MAKEFLAGS+=	BF_ENC=${BF_ENC:Q}

INSTALLATION_DIRS=	bin include lib share/doc/blowfish

do-install:
	cd ${WRKSRC} &&							\
	${INSTALL_DATA} libblowfish.a ${DESTDIR}${PREFIX}/lib &&			\
	${INSTALL_DATA} blowfish.h ${DESTDIR}${PREFIX}/include &&			\
	${INSTALL_PROGRAM} bftest bfspeed ${DESTDIR}${PREFIX}/bin
.for doc in blowfish.doc COPYRIGHT README VERSION
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DESTDIR}${PREFIX}/share/doc/blowfish
.endfor

.include "../../mk/bsd.pkg.mk"
