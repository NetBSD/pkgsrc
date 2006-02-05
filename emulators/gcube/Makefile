# $NetBSD: Makefile,v 1.10 2006/02/05 23:09:01 joerg Exp $
#

DISTNAME=		gcube-0.4-src
PKGNAME=		${DISTNAME:S/-src//}
PKGREVISION=		1
CATEGORIES=		emulators
MASTER_SITES=		http://gcube.exemu.net/downloads/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://gcube.exemu.net/
COMMENT=		Opensource Nintendo GameCube(TM) emulator

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		gmake
WRKSRC=			${WRKDIR}/0.4

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_ARCH:Mi386)
BUILD_DEPENDS+=		nasm-[0-9]*:../../devel/nasm
CFLAGS+=		-DASM_X86=1
.endif

INSTALLATION_DIRS=	share/doc/${PKGBASE} bin

do-install:
.for prog in isopack gcube bin2dol gcmap tplx
	${INSTALL_PROGRAM} ${WRKSRC}/${prog} ${PREFIX}/bin
.endfor
.for f in README ChangeLog COPYING
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/${PKGBASE}
.endfor

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
