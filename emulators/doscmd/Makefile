# $NetBSD: Makefile,v 1.7 2001/02/17 18:38:16 wiz Exp $
#

DISTNAME=		doscmd-19960502-2
PKGNAME=		doscmd-19960502.2
CATEGORIES=		emulators
MASTER_SITES=		ftp://ftp.netbsd.org/pub/NetBSD/arch/i386/doscmd/

MAINTAINER=		packages@netbsd.org
COMMENT=		MS-DOS emulator (NetBSD/i386 only)

ONLY_FOR_PLATFORM=	NetBSD-*-i386

WRKSRC=			${WRKDIR}/doscmd

MAKE_ENV=		X11BASE=${X11BASE}

MANCOMPRESSED_IF_MANZ=	yes

do-configure:
	@cd ${WRKSRC} && \
	${SED} "s=%PREFIX%=${PREFIX}=" < doscmd.1 >doscmd.1.new && \
	${MV} doscmd.1.new doscmd.1 && \
	${SED} "s=%PREFIX%=${PREFIX}=" < doscmd_loader.c >dl.new && \
	${MV} dl.new doscmd_loader.c

.include "../../mk/bsd.pkg.mk"
