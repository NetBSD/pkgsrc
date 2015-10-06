# $NetBSD: Makefile,v 1.8 2015/10/06 11:29:55 tnn Exp $

DISTNAME=	# empty
PKGNAME=	modular-xorg-1.12.4
PKGREVISION=	1
CATEGORIES=	meta-pkgs x11
MASTER_SITES=	${MASTER_SITE_XORG:=/}
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Modular Xorg meta-package
LICENSE=	2-clause-bsd

META_PACKAGE=	yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
DEPENDS+=	modular-xorg-xquartz-[0-9]*:../../x11/modular-xorg-xquartz
.else
DEPENDS+=	modular-xorg-server>=1.12.4:../../x11/modular-xorg-server
DEPENDS+=	modular-xorg-drivers>=1.12:../../meta-pkgs/modular-xorg-drivers
.endif

DEPENDS+=	modular-xorg-libs>=1.0:../../meta-pkgs/modular-xorg-libs
DEPENDS+=	modular-xorg-apps>=1.5:../../meta-pkgs/modular-xorg-apps
DEPENDS+=	modular-xorg-fonts>=1.1:../../meta-pkgs/modular-xorg-fonts
DEPENDS+=	modular-xorg-utils>=1.0:../../meta-pkgs/modular-xorg-utils
DEPENDS+=	xorg-docs-[0-9]*:../../misc/xorg-docs

.include "../../mk/bsd.pkg.mk"
