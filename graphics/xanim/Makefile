# $NetBSD: Makefile,v 1.27 2002/09/20 03:13:09 jlam Exp $

DISTNAME=	xanim2801
PKGNAME=	xanim-2.80.1
PKGREVISION=	1
CATEGORIES=	graphics x11
MASTER_SITES=	ftp://xanim.va.pubnix.com/\
		ftp://xanim.va.pubnix.com/modules/ \
		ftp://ftp.ut.ee/pub/graphics/xanim/ \
		ftp://ftp.ut.ee/pub/graphics/xanim/modules/ \
		ftp://ftp.ba-stuttgart.de/Mirrors/xanim/ \
		ftp://ftp.ba-stuttgart.de/Mirrors/xanim/modules/ \
		http://smurfland.cit.buffalo.edu/xanim/files/ \
		http://smurfland.cit.buffalo.edu/xanim/files/modules/
DISTFILES=	${EXTRACT_ONLY} ${EXTRA_FILES}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://xanim.va.pubnix.com/
COMMENT=	play most popular animation formats and show pictures

EXTRACT_ONLY=   ${DISTNAME}${EXTRACT_SUFX}

RESTRICTED=		Can't mirror/distribute iv32 or cyuv object modules
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

USE_BUILDLINK2=	YES
USE_X11BASE=	YES
USE_IMAKE=	YES

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

.include "../../mk/bsd.prefs.mk"

MACHINE_OBJ_ARCH=	${MACHINE_ARCH}-${OBJECT_FMT}

.if (${MACHINE_OBJ_ARCH} == "i386-a.out") || make(makesum)
EXTRA_FILES+=	xa2.0_cvid_netbsd386.o.Z \
		xa2.0_iv32_netbsd386.o.Z \
		xa1.0_cyuv_netbsd386.o.Z
.endif
.if (${MACHINE_OBJ_ARCH} == "i386-ELF") || make(makesum)
EXTRA_FILES+=	xa2.0_cvid_linuxELF.o.Z \
		xa2.0_iv32_linuxELF.o.Z \
		xa1.0_cyuv_linuxELF.o.Z
.endif
.if (${MACHINE_OBJ_ARCH} == "m68k-a.out") || make(makesum)
EXTRA_FILES+=	xa2.0_cvid_netbsd68k.o.Z \
		xa2.0_iv32_netbsd68k.o.Z \
		xa1.0_cyuv_netbsd68k.o.Z
.endif
.if (${MACHINE_OBJ_ARCH} == "sparc-a.out") || make(makesum)
EXTRA_FILES+=	xa2.0_cvid_sparcCOFF.o.Z \
		xa2.0_iv32_sparcCOFF.o.Z \
		xa1.0_cyuv_sparcAOUT.o.Z
.endif
.if (${MACHINE_OBJ_ARCH} == "powerpc-ELF") || make(makesum)
EXTRA_FILES+=	xa2.0_cvid_linuxPPC.o.Z \
		xa1.0_cyuv_linuxPPC.o.Z
.endif

.include "../../mk/bsd.pkg.mk"
