# $NetBSD: Makefile,v 1.46 2023/05/03 07:20:29 wiz Exp $

DISTNAME=	# empty
PKGNAME=	modular-xorg-apps-1.14.1.15
CATEGORIES=	meta-pkgs x11
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	Modular Xorg application meta-package
LICENSE=	2-clause-bsd

META_PACKAGE=	yes

.include "../../mk/bsd.prefs.mk"

DEPENDS+=	xbiff-[0-9]*:../../mail/xbiff
DEPENDS+=	twm-[0-9]*:../../wm/twm
DEPENDS+=	appres-[0-9]*:../../x11/appres
DEPENDS+=	bdftopcf-[0-9]*:../../fonts/bdftopcf
DEPENDS+=	beforelight-[0-9]*:../../x11/beforelight
DEPENDS+=	bitmap-[0-9]*:../../x11/bitmap
DEPENDS+=	editres-[0-9]*:../../x11/editres
DEPENDS+=	font-util-[0-9]*:../../fonts/font-util
DEPENDS+=	iceauth-[0-9]*:../../x11/iceauth
DEPENDS+=	ico-[0-9]*:../../x11/ico
DEPENDS+=	listres-[0-9]*:../../x11/listres
DEPENDS+=	luit-[0-9]*:../../x11/luit
DEPENDS+=	mkcomposecache-[0-9]*:../../x11/mkcomposecache
.if ${OPSYS} != "Darwin"
DEPENDS+=	modular-xorg-xephyr-[0-9]*:../../x11/modular-xorg-xephyr
.endif
DEPENDS+=	oclock-[0-9]*:../../time/oclock
DEPENDS+=	setxkbmap-[0-9]*:../../x11/setxkbmap
DEPENDS+=	transset-[0-9]*:../../x11/transset
DEPENDS+=	viewres-[0-9]*:../../x11/viewres
DEPENDS+=	x11perf-[0-9]*:../../x11/x11perf
DEPENDS+=	xauth-[0-9]*:../../x11/xauth
DEPENDS+=	xbacklight-[0-9]*:../../x11/xbacklight
DEPENDS+=	xcalc-[0-9]*:../../x11/xcalc
DEPENDS+=	xclipboard-[0-9]*:../../x11/xclipboard
DEPENDS+=	xclock-[0-9]*:../../time/xclock
DEPENDS+=	xcmsdb-[0-9]*:../../x11/xcmsdb
DEPENDS+=	xconsole-[0-9]*:../../x11/xconsole
DEPENDS+=	xcursorgen-[0-9]*:../../x11/xcursorgen
DEPENDS+=	xcursor-themes-[0-9]*:../../x11/xcursor-themes
DEPENDS+=	xditview-[0-9]*:../../x11/xditview
DEPENDS+=	xdm-[0-9]*:../../x11/xdm
DEPENDS+=	xdpyinfo-[0-9]*:../../x11/xdpyinfo
DEPENDS+=	xedit-[0-9]*:../../x11/xedit
DEPENDS+=	xev-[0-9]*:../../x11/xev
DEPENDS+=	xeyes-[0-9]*:../../x11/xeyes
DEPENDS+=	xf86dga-[0-9]*:../../x11/xf86dga
DEPENDS+=	xfd-[0-9]*:../../x11/xfd
DEPENDS+=	xfontsel-[0-9]*:../../x11/xfontsel
DEPENDS+=	xfsinfo-[0-9]*:../../x11/xfsinfo
DEPENDS+=	xgamma-[0-9]*:../../x11/xgamma
DEPENDS+=	xgc-[0-9]*:../../graphics/xgc
DEPENDS+=	xhost-[0-9]*:../../x11/xhost
DEPENDS+=	xinit-[0-9]*:../../x11/xinit
DEPENDS+=	xkbevd-[0-9]*:../../x11/xkbevd
DEPENDS+=	xkbprint-[0-9]*:../../x11/xkbprint
DEPENDS+=	xkbutils-[0-9]*:../../x11/xkbutils
DEPENDS+=	xkill-[0-9]*:../../x11/xkill
DEPENDS+=	xload-[0-9]*:../../x11/xload
DEPENDS+=	xlogo-[0-9]*:../../x11/xlogo
DEPENDS+=	xlsatoms-[0-9]*:../../x11/xlsatoms
DEPENDS+=	xlsclients-[0-9]*:../../x11/xlsclients
DEPENDS+=	xlsfonts-[0-9]*:../../x11/xlsfonts
DEPENDS+=	xmag-[0-9]*:../../x11/xmag
DEPENDS+=	xman-[0-9]*:../../x11/xman
DEPENDS+=	xmessage-[0-9]*:../../x11/xmessage
DEPENDS+=	xmh-[0-9]*:../../x11/xmh
DEPENDS+=	xmodmap-[0-9]*:../../x11/xmodmap
DEPENDS+=	xmore-[0-9]*:../../x11/xmore
DEPENDS+=	xpr-[0-9]*:../../x11/xpr
DEPENDS+=	xprop-[0-9]*:../../x11/xprop
DEPENDS+=	xrandr-[0-9]*:../../x11/xrandr
DEPENDS+=	xrdb-[0-9]*:../../x11/xrdb
DEPENDS+=	xrefresh-[0-9]*:../../x11/xrefresh
DEPENDS+=	xscope-[0-9]*:../../x11/xscope
DEPENDS+=	xset-[0-9]*:../../x11/xset
DEPENDS+=	xsetroot-[0-9]*:../../x11/xsetroot
DEPENDS+=	xsm-[0-9]*:../../x11/xsm
DEPENDS+=	xstdcmap-[0-9]*:../../x11/xstdcmap
DEPENDS+=	{xterm,mxterm}-[0-9]*:../../x11/xterm
DEPENDS+=	xtrans-[0-9]*:../../x11/xtrans
DEPENDS+=	xvinfo-[0-9]*:../../x11/xvinfo
DEPENDS+=	xwininfo-[0-9]*:../../x11/xwininfo
DEPENDS+=	xwd-[0-9]*:../../x11/xwd
DEPENDS+=	xwud-[0-9]*:../../x11/xwud

.include "../../mk/bsd.pkg.mk"
