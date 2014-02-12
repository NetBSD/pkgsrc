# $NetBSD: Makefile,v 1.44 2014/02/12 23:18:26 tron Exp $

DISTNAME=		tightvnc-1.3.10
PKGREVISION=		10
CATEGORIES=		net x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=vnc-tight/}
DISTFILES=		${DISTNAME}_unixsrc.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.tightvnc.com/
COMMENT=		Display X and Win32 desktops on remote X/Win32/Java displays

CONFLICTS=		vnc-[0-9]* vncviewer-[0-9]*

WRKSRC=			${WRKDIR}/vnc_unixsrc
CRYPTO=			yes
USE_IMAKE=		yes
USE_TOOLS+=		perl:run
MAKE_JOBS_SAFE=		no

BUILD_TARGET=		World

TOOL_DEPENDS+=		tradcpp-[0-9]*:../../devel/tradcpp

.include "../../mk/bsd.prefs.mk"

CPPFLAGS+=		-DDEFAULT_CPP=\"${PREFIX}/bin/tradcpp\"

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mclang)
CPPFLAGS+=		-Wno-error=return-type
.endif

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
FONTPATH=		${X11BASE}/share/fonts/X11/misc,${X11BASE}/share/fonts/X11/75dpi,${X11BASE}/lib/X11/fonts/misc,${X11BASE}/lib/X11/fonts/75dpi

SUBST_CLASSES+=		hpath
SUBST_STAGE.hpath=	pre-configure
SUBST_MESSAGE.hpath=	fixing hardcoded paths
SUBST_FILES.hpath=	vncserver tightvncserver.conf
SUBST_SED.hpath+=	-e 's|/usr/local/vnc/classes|${PREFIX}/share/vnc/classes|g'
SUBST_SED.hpath+=	-e 's|/etc/tightvncserver.conf|${PKG_SYSCONFDIR}/tightvncserver.conf|g'

REPLACE_PERL=		vncserver

post-extract:
	(${ECHO} "#define DefaultRGBDatabase ${RGBPATH}";\
	 ${ECHO} "#define DefaultFontPath ${FONTPATH}")\
	>> ${WRKSRC}/Xvnc/config/cf/site.def

CONF_FILES+=		${PREFIX}/share/examples/tightvnc/tightvncserver.conf \
			    ${PKG_SYSCONFDIR}/tightvncserver.conf

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/examples/tightvnc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Xvnc/programs/Xserver/Xvnc \
	    ${DESTDIR}${PREFIX}/bin/Xvnc
	${INSTALL_MAN} ${WRKSRC}/Xvnc/programs/Xserver/Xvnc.man \
	    ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/Xvnc.1
	${INSTALL_PROGRAM} ${WRKSRC}/vncconnect/vncconnect \
	    ${DESTDIR}${PREFIX}/bin/vncconnect
	${INSTALL_MAN} ${WRKSRC}/vncconnect/vncconnect.man \
	    ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/vncconnect.1
	${INSTALL_PROGRAM} ${WRKSRC}/vncpasswd/vncpasswd \
	    ${DESTDIR}${PREFIX}/bin/vncpasswd
	${INSTALL_MAN} ${WRKSRC}/vncpasswd/vncpasswd.man \
	    ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/vncpasswd.1
	${INSTALL_SCRIPT} ${WRKSRC}/vncserver ${DESTDIR}${PREFIX}/bin/vncserver
	${INSTALL_MAN} ${WRKSRC}/vncserver.man \
	    ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/vncserver.1
	${INSTALL_DATA} ${WRKSRC}/tightvncserver.conf \
	    ${DESTDIR}${PREFIX}/share/examples/tightvnc/tightvncserver.conf

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
