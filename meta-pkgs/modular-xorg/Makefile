# $NetBSD: Makefile,v 1.1.1.1 2011/05/26 23:27:22 wiz Exp $

DISTNAME=	# empty
PKGNAME=	modular-xorg-1.0
CATEGORIES=	meta-pkgs x11
MASTER_SITES=	${MASTER_SITE_XORG:=/}
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Modular Xorg meta-package

META_PACKAGE=	yes

DEPENDS+=	modular-xorg-libs>=1.0:../../meta-pkgs/modular-xorg-libs
DEPENDS+=	modular-xorg-drivers>=1.4:../../meta-pkgs/modular-xorg-drivers
DEPENDS+=	modular-xorg-apps>=1.5:../../meta-pkgs/modular-xorg-apps
DEPENDS+=	modular-xorg-fonts>=1.1:../../meta-pkgs/modular-xorg-fonts
DEPENDS+=	modular-xorg-server>=1.6.5:../../x11/modular-xorg-server

.include "../../mk/bsd.pkg.mk"
