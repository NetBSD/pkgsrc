# $NetBSD: Makefile,v 1.3 2013/05/16 06:38:20 richard Exp $

DISTNAME=	# empty
PKGNAME=	modular-xorg-1.12.4
CATEGORIES=	meta-pkgs x11
MASTER_SITES=	${MASTER_SITE_XORG:=/}
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Modular Xorg meta-package

META_PACKAGE=	yes

DEPENDS+=	modular-xorg-libs>=1.0:../../meta-pkgs/modular-xorg-libs
DEPENDS+=	modular-xorg-drivers>=1.12:../../meta-pkgs/modular-xorg-drivers
DEPENDS+=	modular-xorg-apps>=1.5:../../meta-pkgs/modular-xorg-apps
DEPENDS+=	modular-xorg-fonts>=1.1:../../meta-pkgs/modular-xorg-fonts
DEPENDS+=	modular-xorg-server>=1.12.4:../../x11/modular-xorg-server
DEPENDS+=	xorg-docs-[0-9]*:../../misc/xorg-docs

.include "../../mk/bsd.pkg.mk"
