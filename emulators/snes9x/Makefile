# $NetBSD: Makefile,v 1.21 2004/12/05 13:56:11 wiz Exp $

DISTNAME=		s9xs139
PKGNAME=		snes9x-1.39
PKGREVISION=		3
CATEGORIES=		emulators
MASTER_SITES=		http://www.snes9x.com/zips/
EXTRACT_SUFX=		.zip

MAINTAINER=		jmcneill@NetBSD.org
HOMEPAGE=		http://www.snes9x.com/
COMMENT=		Super Nintendo Entertainment System (SNES) emulator

BUILD_DEPENDS+=		nasm>=0.98:../../devel/nasm

WRKSRC=			${WRKDIR}/release
USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_X11=		yes
PTHREAD_OPTS=		require

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/snes9x ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/offsets ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/snes9x
	${INSTALL_MAN} ${WRKSRC}/CHANGES.TXT ${PREFIX}/share/doc/snes9x
	${INSTALL_MAN} ${WRKSRC}/COPYRIGHT.TXT ${PREFIX}/share/doc/snes9x
	${INSTALL_MAN} ${WRKSRC}/HARDWARE.TXT ${PREFIX}/share/doc/snes9x
	${INSTALL_MAN} ${WRKSRC}/HOW2PORT.TXT ${PREFIX}/share/doc/snes9x
	${INSTALL_MAN} ${WRKSRC}/PROBLEMS.TXT ${PREFIX}/share/doc/snes9x
	${INSTALL_MAN} ${WRKSRC}/README.TXT ${PREFIX}/share/doc/snes9x
	${INSTALL_MAN} ${WRKSRC}/TODO.TXT ${PREFIX}/share/doc/snes9x

.include "../../mk/bsd.prefs.mk"

MAKE_ENV+=	THREAD_SOUND=1
.if ( ${MACHINE_ARCH} == "i386" )
MAKE_ENV+=	USING_I386=1
.if ( ${OBJECT_FMT} == "a.out" )
MAKE_ENV+=	FILEFORMAT=aoutb
MAKE_ENV+=	_ASM_UNDERBARS=1
.else
MAKE_ENV+=	FILEFORMAT=elf
.endif
MAKE_ENV+=	ZSNESFX=1
MAKE_ENV+=	ZSNESC4=1
MAKE_ENV+=	ASMCPU=1
.if !empty(USE_MMX:M[Yy][Ee][Ss])
MAKE_ENV+=	ASMKREED=1
.endif
BUILD_DEFS+=	USE_MMX
.endif

.if exists(${X11BASE}/lib/libXxf86dga.a)
MAKE_ENV+=	NETBSD_USE_DGA=1
.endif

.if exists(/usr/include/usb.h) || exists(/usr/include/usbhid.h)
MAKE_ENV+=	USBJOY=1
.if exists(/usr/include/usbhid.h)
MAKE_ENV+=	USBHID_H=1
.endif
.endif

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
