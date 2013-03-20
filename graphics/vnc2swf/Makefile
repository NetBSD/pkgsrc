# $NetBSD: Makefile,v 1.18 2013/03/20 03:05:50 obache Exp $
#

DISTNAME=		vnc2swf-0.5.0
PKGREVISION=		4
CATEGORIES=		graphics
MASTER_SITES=		http://www.unixuser.org/~euske/vnc2swf/

MAINTAINER=		obache@NetBSD.org
HOMEPAGE=		http://www.unixuser.org/~euske/vnc2swf/
COMMENT=		Record vnc session as flash movie
LICENSE=		gnu-gpl-v2

.include "../../mk/bsd.fast.prefs.mk"

DEPENDS+=		x11vnc-[0-9]*:../../x11/x11vnc
.if ${X11_TYPE} == "modular" || !exists(${X11BASE}/bin/xwininfo)
DEPENDS+=		xwininfo-[0-9]*:../../x11/xwininfo
.endif

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++

USE_TOOLS+=	pax

LDFLAGS.SunOS+=	-lsocket -lnsl

INSTALLATION_DIRS=	bin lib/X11/app-defaults share/doc/vnc2swf

SUBST_CLASSES+=		x11base
SUBST_STAGE.x11base=	pre-configure
SUBST_MESSAGE.x11base=	Change X11base to ${PREFIX} in Makefile
SUBST_FILES.x11base=	Makefile.in
SUBST_SED.x11base=	-e "s|/usr/X11R6|${PREFIX}|"

SUBST_CLASSES+=		toolpath
SUBST_STAGE.toolpath=	pre-configure
SUBST_FILES.toolpath=	recordwin.sh
SUBST_SED.toolpath=	-e "s|VNC2SWF=vnc2swf|VNC2SWF=${PREFIX}/bin/vnc2swf|" \
			-e "s|X11VNC=x11vnc|X11VNC=${PREFIX}/bin/x11vnc|" \
			-e "s|XWININFO=xwininfo|XWININFO=${X11BASE}/bin/xwininfo|" \
			-e "s|AWK=awk|AWK=${AWK}|" \
			-e 's|-mouse|-localhost|'
post-install:
	${INSTALL_DATA} ${WRKSRC}/Vnc2Swf.ad ${DESTDIR}${PREFIX}/lib/X11/app-defaults/Vnc2Swf
	cd ${WRKSRC}/docs && \
	pax -rw -pp -pm . ${DESTDIR}${PREFIX}/share/doc/vnc2swf

.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
