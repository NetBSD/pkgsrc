# $NetBSD: Makefile,v 1.11 2003/06/02 01:19:59 jschauma Exp $
#

DISTNAME=		doscmd-19960502-2
PKGNAME=		doscmd-19960502.2
WRKSRC=			${WRKDIR}/doscmd
CATEGORIES=		emulators
MASTER_SITES=		ftp://ftp.netbsd.org/pub/NetBSD/arch/i386/doscmd/

MAINTAINER=		tech-pkg@netbsd.org
COMMENT=		MS-DOS emulator (NetBSD/i386 only)

# mmap() portability (no MAP_FIXED), and objcopy problems on NetBSD-1.6-i386 and later
ONLY_FOR_PLATFORM=	NetBSD-1.[345]*-i386

MAKE_ENV=		X11BASE=${X11BASE}

MANCOMPRESSED_IF_MANZ=	yes

do-configure:
	@cd ${WRKSRC} && \
	${SED} "s=%PREFIX%=${PREFIX}=" < doscmd.1 >doscmd.1.new && \
	${MV} doscmd.1.new doscmd.1 && \
	${SED} "s=%PREFIX%=${PREFIX}=" < doscmd_loader.c >dl.new && \
	${MV} dl.new doscmd_loader.c

.include "../../mk/bsd.pkg.mk"
