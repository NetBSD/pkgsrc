# $NetBSD: Makefile,v 1.12 1998/08/20 15:17:02 tsarna Exp $
#

DISTNAME=       xanim27070
PKGNAME=        xanim-2.70.7.0
CATEGORIES=	graphics x11
MASTER_SITES=	ftp://xanim.va.pubnix.com/\
		ftp://xanim.va.pubnix.com/modules/
DISTFILES=	${EXTRACT_ONLY} ${EXTRA_FILES}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://xanim.va.pubnix.com/

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

post-extract:
	ln -s docs/xanim.man ${WRKSRC}
	@for file in ${EXTRA_FILES}; do \
	  ${CP} ${DISTDIR}/$$file ${WRKSRC}; \
	  ${GUNZIP_CMD} ${WRKSRC}/$$file; \
	done

.include "../../mk/bsd.pkg.mk"
