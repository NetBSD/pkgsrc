# $NetBSD: Makefile,v 1.4 1999/05/24 20:39:40 tv Exp $
#

DISTNAME=		doscmd-19960502-2
PKGNAME=		doscmd-19960502.2
CATEGORIES=		emulators
MASTER_SITES=		ftp://ftp.netbsd.org/pub/NetBSD/arch/i386/doscmd/

MAINTAINER=		tsarna@netbsd.org

ONLY_FOR_PLATFORM=	NetBSD-*-i386

WRKSRC=			${WRKDIR}/doscmd

MAKE_ENV=		X11BASE=${X11BASE}

.include "../../mk/bsd.prefs.mk"

.ifdef MANZ
MANCOMPRESSED=
.endif

do-configure:
	@cd ${WRKSRC} && \
	${SED} "s=%PREFIX%=${PREFIX}=" < doscmd.1 >doscmd.1.new && \
	${MV} doscmd.1.new doscmd.1 && \
	${SED} "s=%PREFIX%=${PREFIX}=" < doscmd_loader.c >dl.new && \
	${MV} dl.new doscmd_loader.c

.include "../../mk/bsd.pkg.mk"
