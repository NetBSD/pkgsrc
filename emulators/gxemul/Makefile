# $NetBSD: Makefile,v 1.4 2005/04/29 00:59:00 xtraeme Exp $
#

DISTNAME=	gxemul-0.3.2
CATEGORIES=	emulators
MASTER_SITES=	http://gavare.se/gxemul/src/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://gavare.se/gxemul/
COMMENT=	Machine emulator

PKG_INSTALLATION_TYPES=	overwrite pkgviews

HAS_CONFIGURE=	yes
BUILD_TARGET=	build

INSTALLATION_DIRS=	bin share/doc/${PKGBASE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gxemul ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/gxemul.1 ${PREFIX}/man/man1
.for f in README HISTORY BUGS TODO RELEASE LICENSE
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/${PKGBASE}
.endfor
	${INSTALL_DATA} ${WRKSRC}/doc/*.gif ${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/doc/*.png ${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/doc/*.c ${PREFIX}/share/doc/${PKGBASE}

PKG_OPTIONS_VAR=	PKG_OPTIONS.gxemul
PKG_SUPPORTED_OPTIONS=	X11
PKG_DEFAULT_OPTIONS?=	X11
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:MX11)
USE_X11=		yes
GLOBAL_LDFLAGS=		-L${X11BASE}/lib ${COMPILER_RPATH_FLAG}${X11BASE}/lib
SUBST_CLASSES=		x11
SUBST_STAGE.x11=	post-patch
SUBST_FILES.x11=	configure
SUBST_SED.x11=		-e "s|-L/usr/X11R6/lib|${GLOBAL_LDFLAGS}|g" \
			-e "s|/usr/X11R6|${X11BASE}|g"
SUBST_MESSAGE.x11=	"Fixing X linking flags."
.endif

.include "../../mk/bsd.pkg.mk"
