# New ports collection makefile for:	xanim
# Version required:     2.70.6.4
# Date created:         Sat Nov 5 11:43:03 PST 1994
# Whom:                 piero
#
# $NetBSD: Makefile,v 1.6 1998/02/14 16:55:10 frueauf Exp $
# FreeBSD Id: Makefile,v 1.12 1997/06/09 22:27:11 max Exp
#

DISTNAME=       xanim27064
PKGNAME=        xanim-2.70.6.4
CATEGORIES=	graphics x11
MASTER_SITES=	ftp://xanim.va.pubnix.com/\
		ftp://xanim.va.pubnix.com/modules/
DISTFILES=	${EXTRACT_ONLY} ${EXTRA_FILES}

MAINTAINER=	packages@netbsd.org

EXTRACT_ONLY=   ${DISTNAME}.tar.gz

ONLY_FOR_ARCHS=	i386 m68k sparc
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
	  cp ${DISTDIR}/$$file ${WRKSRC}; \
	  uncompress ${WRKSRC}/$$file; \
	done

.include <bsd.port.mk>
