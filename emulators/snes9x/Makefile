# $NetBSD: Makefile,v 1.8 2002/06/15 21:09:38 wiz Exp $

DISTNAME=		s9xs137c
PKGNAME=		snes9x-1.37.3
WRKSRC=			${WRKDIR}/release
CATEGORIES=		emulators
MASTER_SITES=		http://www.snes9x.com/zips/
EXTRACT_SUFX=		.zip

MAINTAINER=		jmcneill@invisible.yi.org
HOMEPAGE=		http://www.snes9x.com/
COMMENT=		Super Nintendo Entertainment System (SNES) emulator

BUILD_DEPENDS+=		nasm>=0.98:../../devel/nasm

USE_GMAKE=		yes
USE_PTHREAD=		native pth
USE_X11=		yes

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
# use assembler part only for ELF, since it doesn't link on a.out
MAKE_ENV+=	ZSNESFX=1
MAKE_ENV+=	ZSNESC4=1
MAKE_ENV+=	ASMCPU=1
.if defined(USE_MMX) && ${USE_MMX} == "YES"
MAKE_ENV+=	ASMKREED=1
.endif
.endif
.endif

.if exists(${X11BASE}/lib/libXxf86dga.a)
MAKE_ENV+=	NETBSD_USE_DGA=1
.endif

.include "../../mk/pthread.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
