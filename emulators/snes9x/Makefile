# $NetBSD: Makefile,v 1.1.1.1 2000/11/09 16:43:40 wiz Exp $

DISTNAME=		s9xs129
PKGNAME=		snes9x-1.29
WRKSRC=			${WRKDIR}/release
CATEGORIES=		emulators
MASTER_SITES=		http://www.snes9x.com/zips/
EXTRACT_SUFX=		.zip

MAINTAINER=		jmcneill@invisible.yi.org
HOMEPAGE=		http://www.snes9x.com/

BUILD_DEPENDS+=		nasm:../../devel/nasm

# for now, only builds on i386/ELF
ONLY_FOR_PLATFORM=	NetBSD-1.4[A-Z]*-i386 NetBSD-1.[5-9]*-i386

USE_X11=		yes
USE_GMAKE=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/snes9x ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/s9xserver ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/offsets ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/snes9x
	${INSTALL_MAN} ${WRKSRC}/CHANGES.TXT ${PREFIX}/share/doc/snes9x
	${INSTALL_MAN} ${WRKSRC}/COPYRIGHT.TXT ${PREFIX}/share/doc/snes9x
	${INSTALL_MAN} ${WRKSRC}/HARDWARE.TXT ${PREFIX}/share/doc/snes9x
	${INSTALL_MAN} ${WRKSRC}/HOW2PORT.TXT ${PREFIX}/share/doc/snes9x
	${INSTALL_MAN} ${WRKSRC}/PROBLEMS.TXT ${PREFIX}/share/doc/snes9x
	${INSTALL_MAN} ${WRKSRC}/README.TXT ${PREFIX}/share/doc/snes9x
	${INSTALL_MAN} ${WRKSRC}/TODO.TXT ${PREFIX}/share/doc/snes9x

.include "../../mk/bsd.pkg.mk"

.if ( ${OBJECT_FMT} == "a.out" )
MAKE_ENV+=	FILEFORMAT=aoutb
MAKE_FLAGS+=	_ASM_UNDERBARS=1
.else
MAKE_ENV+=	FILEFORMAT=elf
.endif
