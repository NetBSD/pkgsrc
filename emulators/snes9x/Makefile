# $NetBSD: Makefile,v 1.2 2000/11/09 17:25:54 wiz Exp $

DISTNAME=		s9xs129
PKGNAME=		snes9x-1.29
WRKSRC=			${WRKDIR}/release
CATEGORIES=		emulators
MASTER_SITES=		http://www.snes9x.com/zips/
EXTRACT_SUFX=		.zip

MAINTAINER=		jmcneill@invisible.yi.org
HOMEPAGE=		http://www.snes9x.com/

BUILD_DEPENDS+=		nasm:../../devel/nasm

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

.if ( ${MACHINE_ARCH} == "i386" )
.if ( ${OBJECT_FMT} == "a.out" )
MAKE_ENV+=	FILEFORMAT=aoutb
MAKE_ENV+=	_ASM_UNDERBARS=1
.else
MAKE_ENV+=	FILEFORMAT=elf
# use assembler part only for ELF, since it doesn't link on a.out
MAKE_ENV+=	ZSNESFX=1
MAKE_ENV+=	ASMCPU=1
.endif
# XXX: this check should be redone -- DGA doesn't only exist on i386
MAKE_ENV+=	NETBSD_USE_DGA=1
.endif
