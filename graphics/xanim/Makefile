# $NetBSD: Makefile,v 1.14 1999/03/28 07:55:05 rh Exp $
#

DISTNAME=	xanim2801
PKGNAME=	xanim-2.80.1
CATEGORIES=	graphics x11
MASTER_SITES=	ftp://xanim.va.pubnix.com/\
		ftp://xanim.va.pubnix.com/modules/ \
		http://xanim.resnet.gatech.edu/files/ \
		ftp://ftp.ut.ee/pub/graphics/xanim/ \
		ftp://ftp.ut.ee/pub/graphics/xanim/modules \
		ftp://ftp.ba-stuttgart.de/Mirrors/xanim/ \
		ftp://ftp.ba-stuttgart.de/Mirrors/xanim/modules/ \
		ftp://ftp.lysator.liu.se/mirror/X11/apps/xanim/ \
		ftp://ftp.lysator.liu.se/mirror/X11/apps/xanim/modules \
		ftp://ftp.uni-trier.de/pub/unix/X11/application/xanim/ \
		ftp://ftp.uni-trier.de/pub/unix/X11/application/xanim/modules/
DISTFILES=	${EXTRACT_ONLY} ${EXTRA_FILES}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://xanim.va.pubnix.com/

EXTRACT_ONLY=   ${DISTNAME}.tar.gz

.if (${MACHINE_ARCH} == "i386")
EXTRA_FILES=	xa2.0_cvid_netbsd386.o.Z \
		xa2.0_iv32_netbsd386.o.Z \
		xa1.0_cyuv_netbsd386.o.Z
.elif (${MACHINE_ARCH} == "m68k")
EXTRA_FILES=	xa2.0_cvid_netbsd68k.o.Z \
		xa2.0_iv32_netbsd68k.o.Z \
		xa1.0_cyuv_netbsd68k.o.Z
.elif (${MACHINE_ARCH} == "sparc")
EXTRA_FILES=	xa2.0_cvid_sparcCOFF.o.Z \
		xa2.0_iv32_sparcCOFF.o.Z \
		xa1.0_cyuv_sparcAOUT.o.Z
.endif
# we can't mirror/distribute iv32 or cyuv object modules
MIRROR_DISTFILE=	no

USE_IMAKE=	yes

post-extract:
	@${LN} -s docs/xanim.man ${WRKSRC}
	@${MKDIR} ${WRKSRC}/mods
	@for file in ${EXTRA_FILES}; do \
	  ${CP} ${DISTDIR}/$$file ${WRKSRC}/mods; \
	  ${GUNZIP_CMD} ${WRKSRC}/mods/$$file; \
	done

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xanim ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xanim.0 ${PREFIX}/man/cat1

.include "../../mk/bsd.pkg.mk"
