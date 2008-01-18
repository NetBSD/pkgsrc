# $NetBSD: Makefile,v 1.26 2008/01/18 05:08:49 tnn Exp $
#

DISTNAME=		tightvnc-1.3.9
PKGREVISION=		2
CATEGORIES=		net x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=vnc-tight/}
DISTFILES=		${DISTNAME}_unixsrc.tar.bz2

MAINTAINER=		riz@NetBSD.org
HOMEPAGE=		http://www.tightvnc.com/
COMMENT=		Display X and Win32 desktops on remote X/Win32/Java displays

CONFLICTS=		vnc-[0-9]*

WRKSRC=			${WRKDIR}/vnc_unixsrc
CRYPTO=			yes
USE_IMAKE=		yes
USE_TOOLS+=		perl:run
NO_INSTALL_MANPAGES=	yes

BUILD_TARGET=		World

.include "../../mk/bsd.prefs.mk"

# XXX - this should go into Xvnc's NetBSD.cf, but imake doesn't
# seem to pick it up. Someone with strong X-fu needs to look at it.
.if !empty(MACHINE_PLATFORM:MNetBSD-*-x86_64)
_WRAP_EXTRA_ARGS.CC+=	-DDDXTIME -D_XSERVER64 -DGCCUSESGAS
.endif

.if ${X11_TYPE} == "modular"
DEPENDS+=		rgb>=1.0.1:../../x11/rgb
RGBPATH=		${PREFIX}/share/X11/rgb
.else
RGBPATH=		${X11BASE}/lib/X11/rgb
.endif
FONTPATH=		${X11BASE}/lib/X11/fonts/misc,${X11BASE}/lib/X11/fonts/75dpi

SUBST_CLASSES+=		hpath
SUBST_STAGE.hpath=	pre-configure
SUBST_MESSAGE.hpath=	fixing hardcoded paths
SUBST_FILES.hpath=	vncserver
SUBST_SED.hpath+=	-e 's|/usr/local/vnc/classes|${PREFIX}/share/vnc/classes|g'

REPLACE_PERL=		vncserver

post-extract:
	(${ECHO} "#define DefaultRGBDatabase ${RGBPATH}";\
	 ${ECHO} "#define DefaultFontPath ${FONTPATH}")\
	>> ${WRKSRC}/Xvnc/config/cf/site.def

# We have to frob a few things, and we want our own permissions, so it's easier
# to do the install ourselves.
post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Xvnc/programs/Xserver/Xvnc \
	    ${PREFIX}/bin/Xvnc
	${INSTALL_MAN} ${WRKSRC}/Xvnc/programs/Xserver/Xvnc.man \
	    ${PREFIX}/${PKGMANDIR}/man1/Xvnc.1
	${INSTALL_PROGRAM} ${WRKSRC}/vncconnect/vncconnect \
	    ${PREFIX}/bin/vncconnect
	${INSTALL_MAN} ${WRKSRC}/vncconnect/vncconnect.man \
	    ${PREFIX}/${PKGMANDIR}/man1/vncconnect.1
	${INSTALL_PROGRAM} ${WRKSRC}/vncpasswd/vncpasswd \
	    ${PREFIX}/bin/vncpasswd
	${INSTALL_MAN} ${WRKSRC}/vncpasswd/vncpasswd.man \
	    ${PREFIX}/${PKGMANDIR}/man1/vncpasswd.1
	${INSTALL_SCRIPT} ${WRKSRC}/vncserver ${PREFIX}/bin/vncserver
	${INSTALL_MAN} ${WRKSRC}/vncserver.man \
	    ${PREFIX}/${PKGMANDIR}/man1/vncserver.1

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
