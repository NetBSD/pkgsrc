# $NetBSD: Makefile,v 1.8 2012/10/31 11:17:27 asau Exp $
#

DISTNAME=		makedepend-1.0.4
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_XORG:=util/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Dependency generator for make

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "../../meta-pkgs/modular-xorg/hacks.mk"

.include "../../x11/xproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
