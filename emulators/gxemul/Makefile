# $NetBSD: Makefile,v 1.33 2008/01/03 19:58:38 joerg Exp $
#

DISTNAME=	gxemul-0.4.6
CATEGORIES=	emulators
MASTER_SITES=	http://gavare.se/gxemul/src/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://gavare.se/gxemul/
COMMENT=	Machine emulator

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c
HAS_CONFIGURE=	yes
BUILD_TARGET=	build

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/${PKGBASE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gxemul ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/gxemul.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.for f in README HISTORY TODO RELEASE LICENSE
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
.endfor
	cd ${WRKSRC}/doc && ${PAX} -rwppm . ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

PKG_OPTIONS_VAR=	PKG_OPTIONS.gxemul
PKG_SUPPORTED_OPTIONS=	x11
PKG_SUGGESTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mx11)
GLOBAL_LDFLAGS=		-L${X11BASE}/lib ${COMPILER_RPATH_FLAG}${X11BASE}/lib
SUBST_CLASSES+=		x11
SUBST_STAGE.x11=	post-patch
SUBST_FILES.x11=	configure
SUBST_SED.x11=		-e 's|-L/usr/X11R6/lib|${GLOBAL_LDFLAGS:Q}|g'
SUBST_SED.x11+=		-e 's|/usr/X11R6|${X11BASE}|g'
SUBST_MESSAGE.x11=	Fixing X linking flags.

.include "../../x11/libX11/buildlink3.mk"
.endif

.include "../../mk/bsd.pkg.mk"
