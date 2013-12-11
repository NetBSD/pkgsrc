# $NetBSD: Makefile,v 1.8 2013/12/11 16:29:47 wiz Exp $

DISTNAME=	# empty
PKGNAME=	modular-xorg-protos-1.6
CATEGORIES=	meta-pkgs x11
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Modular Xorg application meta-package for prototypes
LICENSE=	2-clause-bsd

META_PACKAGE=	yes

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "Darwin"
DEPENDS+=	applewmproto-[0-9]*:../../wm/applewmproto
.endif
DEPENDS+=	bigreqsproto-[0-9]*:../../x11/bigreqsproto
DEPENDS+=	compositeproto-[0-9]*:../../x11/compositeproto
DEPENDS+=	damageproto-[0-9]*:../../x11/damageproto
DEPENDS+=	dri2proto-[0-9]*:../../x11/dri2proto
DEPENDS+=	dri3proto-[0-9]*:../../x11/dri3proto
DEPENDS+=	fixesproto-[0-9]*:../../x11/fixesproto
DEPENDS+=	fontsproto-[0-9]*:../../x11/fontsproto
DEPENDS+=	glproto-[0-9]*:../../x11/glproto
DEPENDS+=	inputproto-[0-9]*:../../x11/inputproto
DEPENDS+=	kbproto-[0-9]*:../../x11/kbproto
DEPENDS+=	presentproto-[0-9]*:../../x11/presentproto
DEPENDS+=	randrproto-[0-9]*:../../x11/randrproto
DEPENDS+=	recordproto-[0-9]*:../../x11/recordproto
DEPENDS+=	renderproto-[0-9]*:../../x11/renderproto
DEPENDS+=	resourceproto-[0-9]*:../../x11/resourceproto
DEPENDS+=	scrnsaverproto-[0-9]*:../../x11/scrnsaverproto
DEPENDS+=	videoproto-[0-9]*:../../x11/videoproto
DEPENDS+=	windowswmproto-[0-9]*:../../wm/windowswmproto
DEPENDS+=	xcb-proto-[0-9]*:../../x11/xcb-proto
DEPENDS+=	xcmiscproto-[0-9]*:../../x11/xcmiscproto
DEPENDS+=	xextproto-[0-9]*:../../x11/xextproto
DEPENDS+=	xf86driproto-[0-9]*:../../x11/xf86driproto
DEPENDS+=	xf86vidmodeproto-[0-9]*:../../x11/xf86vidmodeproto
DEPENDS+=	xineramaproto-[0-9]*:../../x11/xineramaproto
DEPENDS+=	xproto-[0-9]*:../../x11/xproto

.include "../../mk/bsd.pkg.mk"
