# $NetBSD: Makefile,v 1.15 1999/07/07 23:11:18 tron Exp $
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

pre-configure:
	@${ECHO} >${WRKSRC}/objarch.tmpl \
	  "MACHINE_OBJ_ARCH = ${MACHINE_OBJ_ARCH}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xanim ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xanim.0 ${PREFIX}/man/cat1

.include "../../mk/bsd.pkg.mk"

MACHINE_OBJ_ARCH=	${MACHINE_ARCH}-${OBJECT_FMT}

.if (${MACHINE_OBJ_ARCH} == "i386-a.out")
EXTRA_FILES=	xa2.0_cvid_netbsd386.o.Z \
		xa2.0_iv32_netbsd386.o.Z \
		xa1.0_cyuv_netbsd386.o.Z
.elif (${MACHINE_OBJ_ARCH} == "i386-ELF")
EXTRA_FILES=	xa2.0_cvid_linuxELF.o.Z \
		xa2.0_iv32_linuxELF.o.Z \
		xa1.0_cyuv_linuxELF.o.Z
.elif (${MACHINE_OBJ_ARCH} == "m68k-a.out")
EXTRA_FILES=	xa2.0_cvid_netbsd68k.o.Z \
		xa2.0_iv32_netbsd68k.o.Z \
		xa1.0_cyuv_netbsd68k.o.Z
.elif (${MACHINE_OBJ_ARCH} == "sparc-a.out")
EXTRA_FILES=	xa2.0_cvid_sparcCOFF.o.Z \
		xa2.0_iv32_sparcCOFF.o.Z \
		xa1.0_cyuv_sparcAOUT.o.Z
.endif
