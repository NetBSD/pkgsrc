# $NetBSD: Makefile,v 1.3 2004/10/03 00:14:40 tv Exp $
#

DISTNAME=		gcube-v0.2-src
PKGNAME=		gcube-0.2
PKGREVISION=	1
CATEGORIES=		emulators
MASTER_SITES=		http://gcube.exemu.net/downloads/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://gcube.exemu.net/
COMMENT=		Opensource Nintendo GameCube(TM) emulator

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_X11=		yes
WRKSRC=			${WRKDIR}

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
.include "../../mk/bsd.pkg.mk"
