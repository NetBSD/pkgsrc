# Makefile for:		xanim
# Version required:     2.70.6.4
#
# $NetBSD: Makefile,v 1.8 1998/03/20 06:15:38 mycroft Exp $
#

DISTNAME=       xanim27064
PKGNAME=        xanim-2.70.6.4
CATEGORIES=	graphics x11
MASTER_SITES=	ftp://xanim.va.pubnix.com/\
		ftp://xanim.va.pubnix.com/modules/
DISTFILES=	${EXTRACT_ONLY} ${EXTRA_FILES}

MAINTAINER=	packages@netbsd.org

EXTRACT_ONLY=   ${DISTNAME}.tar.gz

.if (${MACHINE_ARCH} == "i386")
EXTRA_FILES=    xa2.0_cvid_netbsd386.o.Z \
		xa2.0_iv32_netbsd386.o.Z \
		xa1.0_cyuv_netbsd386.o.Z
.elif (${MACHINE_ARCH} == "m68k")
EXTRA_FILES=    xa2.0_cvid_netbsd68k.o.Z \
		xa2.0_iv32_netbsd68k.o.Z \
		xa1.0_cyuv_netbsd68k.o.Z
.elif (${MACHINE_ARCH} == "sparc")
EXTRA_FILES=    xa2.0_cvid_sparcCOFF.o.Z \
		xa2.0_iv32_sparcCOFF.o.Z \
		xa1.0_cyuv_sparcAOUT.o.Z
.endif
# we can't mirror/distribute iv32 or cyuv object modules
MIRROR_DISTFILE=	no

USE_IMAKE=	yes
CAT1=		xanim.0

post-extract:
	@for file in ${EXTRA_FILES}; do \
	  ${CP} ${DISTDIR}/$$file ${WRKSRC}; \
	  ${GUNZIP_CMD} ${WRKSRC}/$$file; \
	done

.include <bsd.port.mk>
