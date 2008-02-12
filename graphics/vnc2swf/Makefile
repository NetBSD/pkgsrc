# $NetBSD: Makefile,v 1.8 2008/02/12 14:56:41 obache Exp $
#

DISTNAME=		vnc2swf-0.5.0
PKGREVISION=		1
CATEGORIES=		graphics
MASTER_SITES=		http://www.unixuser.org/~euske/vnc2swf/

MAINTAINER=		obache@NetBSD.org
HOMEPAGE=		http://www.unixuser.org/~euske/vnc2swf/
COMMENT=		Record vnc session as flash movie

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		x11vnc-[0-9]*:../../x11/x11vnc

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++

INSTALLATION_DIRS=	bin lib/X11/app-defaults share/doc/html/vnc2swf

SUBST_CLASSES+=		x11base
SUBST_STAGE.x11base=	pre-configure
SUBST_MESSAGE.x11base=	Change X11base to ${PREFIX} in Makefile
SUBST_FILES.x11base=	Makefile.in
SUBST_SED.x11base=	-e "s|/usr/X11R6|${PREFIX}|"

SUBST_CLASSES+=		toolpath
SUBST_STAGE.toolpath=	pre-configure
SUBST_FILES.toolpath=	recordwin.sh
SUBST_SED.toolpath=	-E -e "s|^(VNC2SWF=).*|\1${PREFIX}/bin/vnc2swf|" \
			-e "s|^(X11VNC=).*|\1${PREFIX}/bin/x11vnc|" \
			-e "s|^(XWININFO=).*|\1${X11BASE}/bin/xwininfo|" \
			-e "s|^(AWK=).*|\1${AWK}|" \
			-e 's|-mouse|-localhost|'
post-install:
	${INSTALL_DATA} ${WRKSRC}/Vnc2Swf.ad ${DESTDIR}${PREFIX}/lib/X11/app-defaults/Vnc2Swf
	cd ${WRKSRC}/docs && \
	${PAX} -rw -pp -pm . ${DESTDIR}${PREFIX}/share/doc/html/vnc2swf

.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
