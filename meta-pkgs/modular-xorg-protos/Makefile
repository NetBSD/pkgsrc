# $NetBSD: Makefile,v 1.5 2013/09/04 18:03:48 wiz Exp $

DISTNAME=	# empty
PKGNAME=	modular-xorg-protos-1.4
CATEGORIES=	meta-pkgs x11
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Modular Xorg application meta-package for prototypes

META_PACKAGE=	yes

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "Darwin"
DEPENDS+=	applewmproto-[0-9]*:../../wm/applewmproto
.endif
DEPENDS+=	bigreqsproto-[0-9]*:../../x11/bigreqsproto
DEPENDS+=	compositeproto-[0-9]*:../../x11/compositeproto
DEPENDS+=	damageproto-[0-9]*:../../x11/damageproto
DEPENDS+=	dri2proto-[0-9]*:../../x11/dri2proto
DEPENDS+=	fixesproto-[0-9]*:../../x11/fixesproto
DEPENDS+=	fontsproto-[0-9]*:../../x11/fontsproto
DEPENDS+=	glproto-[0-9]*:../../x11/glproto
DEPENDS+=	inputproto-[0-9]*:../../x11/inputproto
DEPENDS+=	kbproto-[0-9]*:../../x11/kbproto
DEPENDS+=	randrproto-[0-9]*:../../x11/randrproto
DEPENDS+=	recordproto-[0-9]*:../../x11/recordproto
DEPENDS+=	renderproto-[0-9]*:../../x11/renderproto
DEPENDS+=	resourceproto-[0-9]*:../../x11/resourceproto
DEPENDS+=	scrnsaverproto-[0-9]*:../../x11/scrnsaverproto
DEPENDS+=	videoproto-[0-9]*:../../x11/videoproto
DEPENDS+=	windowswmproto-[0-9]*:../../wm/windowswmproto
DEPENDS+=	xcmiscproto-[0-9]*:../../x11/xcmiscproto
DEPENDS+=	xextproto-[0-9]*:../../x11/xextproto
DEPENDS+=	xf86driproto-[0-9]*:../../x11/xf86driproto
DEPENDS+=	xf86vidmodeproto-[0-9]*:../../x11/xf86vidmodeproto
DEPENDS+=	xineramaproto-[0-9]*:../../x11/xineramaproto
DEPENDS+=	xproto-[0-9]*:../../x11/xproto

.include "../../mk/bsd.pkg.mk"
