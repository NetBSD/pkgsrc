# $NetBSD: Makefile,v 1.10 2004/11/04 12:18:54 xtraeme Exp $
#

DISTNAME=	mips64emul-0.2.2
CATEGORIES=	emulators
MASTER_SITES=	http://www.mdstud.chalmers.se/~md1gavan/mips64emul/src/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.mdstud.chalmers.se/~md1gavan/mips64emul/
COMMENT=	MIPS 32/64-bit emulator

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	yes
USE_X11=	yes
HAS_CONFIGURE=	yes

INSTALLATION_DIRS=	bin share/doc/${PKGBASE}

GLOBAL_LDFLAGS=	-L${X11BASE}/lib ${COMPILER_RPATH_FLAG}${X11BASE}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mips64emul ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/mips64emul.1 ${PREFIX}/man/man1
.for f in README HISTORY BUGS TODO RELEASE LICENSE 
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/${PKGBASE}
.endfor
	${INSTALL_DATA} ${WRKSRC}/doc/*.gif ${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/doc/*.png ${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/doc/*.c ${PREFIX}/share/doc/${PKGBASE}

SUBST_CLASSES=		x11
SUBST_STAGE.x11=	post-patch
SUBST_FILES.x11=	configure
SUBST_SED.x11=		-e "s|-L/usr/X11R6/lib|${GLOBAL_LDFLAGS}|g" \
			-e "s|/usr/X11R6|${X11BASE}|g"
SUBST_MESSAGE.x11=	"Fixing linking flags."

.include "../../mk/bsd.pkg.mk"
