# $NetBSD: Makefile,v 1.1.1.1 2007/05/20 15:46:14 joerg Exp $

DISTNAME=	# empty
PKGNAME=	modular-xorg-apps-1.0
CATEGORIES=	meta-pkgs x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/app/
DISTFILES=	# empty

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Modular Xorg application meta-package

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	xbiff-[0-9]*:../../mail/xbiff
DEPENDS+=	appres-[0-9]*:../../x11/appres
DEPENDS+=	beforelight-[0-9]*:../../x11/beforelight
DEPENDS+=	bitmap-[0-9]*:../../x11/bitmap
DEPENDS+=	editres-[0-9]*:../../x11/editres
DEPENDS+=	iceauth-[0-9]*:../../x11/iceauth
DEPENDS+=	ico-[0-9]*:../../x11/ico
DEPENDS+=	listres-[0-9]*:../../x11/listres
DEPENDS+=	luit-[0-9]*:../../x11/luit
DEPENDS+=	setxkbmap-[0-9]*:../../x11/setxkbmap
DEPENDS+=	x11perf-[0-9]*:../../x11/x11perf
DEPENDS+=	xauth-[0-9]*:../../x11/xauth
DEPENDS+=	xcalc-[0-9]*:../../x11/xcalc
DEPENDS+=	xclock-[0-9]*:../../x11/xclock
DEPENDS+=	xconsole-[0-9]*:../../x11/xconsole
DEPENDS+=	xdpyinfo-[0-9]*:../../x11/xdpyinfo
DEPENDS+=	xev-[0-9]*:../../x11/xev
DEPENDS+=	xeyes-[0-9]*:../../x11/xeyes
DEPENDS+=	xfontsel-[0-9]*:../../x11/xfontsel
DEPENDS+=	xgamma-[0-9]*:../../x11/xgamma
DEPENDS+=	xhost-[0-9]*:../../x11/xhost
DEPENDS+=	xinit-[0-9]*:../../x11/xinit
DEPENDS+=	xkill-[0-9]*:../../x11/xkill
DEPENDS+=	xload-[0-9]*:../../x11/xload
DEPENDS+=	xlogo-[0-9]*:../../x11/xlogo
DEPENDS+=	xmag-[0-9]*:../../x11/xmag
DEPENDS+=	xman-[0-9]*:../../x11/xman
DEPENDS+=	xmessage-[0-9]*:../../x11/xmessage
DEPENDS+=	xmodmap-[0-9]*:../../x11/xmodmap
DEPENDS+=	xmore-[0-9]*:../../x11/xmore
DEPENDS+=	xplsprinters-[0-9]*:../../x11/xplsprinters
DEPENDS+=	xprehashprinterlist-[0-9]*:../../x11/xprehashprinterlist
DEPENDS+=	xprop-[0-9]*:../../x11/xprop
DEPENDS+=	xrandr-[0-9]*:../../x11/xrandr
DEPENDS+=	xrdb-[0-9]*:../../x11/xrdb
DEPENDS+=	xrefresh-[0-9]*:../../x11/xrefresh
DEPENDS+=	xset-[0-9]*:../../x11/xset
DEPENDS+=	xsetmode-[0-9]*:../../x11/xsetmode
DEPENDS+=	xsetpointer-[0-9]*:../../x11/xsetpointer
DEPENDS+=	xsetroot-[0-9]*:../../x11/xsetroot
DEPENDS+=	xsm-[0-9]*:../../x11/xsm
DEPENDS+=	xvinfo-[0-9]*:../../x11/xvinfo
DEPENDS+=	xwininfo-[0-9]*:../../x11/xwininfo
DEPENDS+=	xwud-[0-9]*:../../x11/xwud

NO_BUILD=		yes
NO_CHECKSUM=		yes
NO_MTREE=		yes
NO_CONFIGURE=		yes

do-install:

.include "../../mk/bsd.pkg.mk"
