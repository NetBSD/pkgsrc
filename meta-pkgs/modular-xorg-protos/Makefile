# $NetBSD: Makefile,v 1.2 2013/05/31 00:45:30 rodent Exp $

DISTNAME=	# empty
PKGNAME=	modular-xorg-protos-1.1
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
DEPENDS+=	compositeproto-[0-9]*:../../x11/compositeproto
DEPENDS+=	damageproto-[0-9]*:../../x11/damageproto
DEPENDS+=	fixesproto-[0-9]*:../../x11/fixesproto
DEPENDS+=	inputproto-[0-9]*:../../x11/inputproto
DEPENDS+=	kbproto-[0-9]*:../../x11/kbproto
DEPENDS+=	randrproto-[0-9]*:../../x11/randrproto
DEPENDS+=	renderproto-[0-9]*:../../x11/renderproto
DEPENDS+=	windowswmproto-[0-9]*:../../wm/windowswmproto
DEPENDS+=	xextproto-[0-9]*:../../x11/xextproto
DEPENDS+=	xineramaproto-[0-9]*:../../x11/xineramaproto
DEPENDS+=	xproto-[0-9]*:../../x11/xproto

.include "../../mk/bsd.pkg.mk"
