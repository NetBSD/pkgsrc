# $NetBSD: Makefile,v 1.2 2014/05/21 21:09:20 wiz Exp $

DISTNAME=	# empty
PKGNAME=	modular-xorg-utils-1.0
CATEGORIES=	meta-pkgs x11
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Modular Xorg application meta-package for Xorg development utilities
LICENSE=	2-clause-bsd

META_PACKAGE=	yes

.include "../../mk/bsd.fast.prefs.mk"

# unpackaged packages commented out below
DEPENDS+=	xorg-cf-files-[0-9]*:../../x11/xorg-cf-files
DEPENDS+=	gccmakedep-[0-9]*:../../devel/gccmakedep
DEPENDS+=	imake-[0-9]*:../../devel/imake
# install-check
# lndir
DEPENDS+=	xorg-util-macros-[0-9]*:../../devel/xorg-util-macros
DEPENDS+=	makedepend-[0-9]*:../../devel/makedepend
# modular
# xmkmf

.include "../../mk/bsd.pkg.mk"
