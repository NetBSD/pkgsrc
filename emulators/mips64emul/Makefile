# $NetBSD: Makefile,v 1.3 2004/06/28 04:01:11 xtraeme Exp $
#

DISTNAME=	mips64emul-${DIST_VER}
CATEGORIES=	emulators
MASTER_SITES=	http://www.mdstud.chalmers.se/~md1gavan/mips64emul/src/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.mdstud.chalmers.se/~md1gavan/mips64emul/
COMMENT=	MIPS 32/64-bit emulator

USE_BUILDLINK3=	yes
USE_X11=	yes
HAS_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/mips64emul-${DIST_VER}

INSTALLATION_DIRS=	bin share/doc/${PKGBASE}

DIST_VER=	20040627

GLOBAL_LDFLAGS=	-L${X11BASE}/lib \
		${_COMPILER_LD_FLAG}${RPATH_FLAG}${X11BASE}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mips64emul ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/mips64emul.1 ${PREFIX}/man/man1
.for f in README HISTORY BUGS TODO RELEASE LICENSE 
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/${PKGBASE}
.endfor

SUBST_CLASSES=		x11
SUBST_STAGE.x11=	post-patch
SUBST_FILES.x11=	configure
SUBST_SED.x11=		-e "s|-L/usr/X11R6/lib|${GLOBAL_LDFLAGS}|g"
SUBST_MESSAGE.x11=	"Fixing linking flags."

.include "../../mk/bsd.pkg.mk"
