# $NetBSD: Makefile,v 1.2 2007/03/21 22:59:19 wiz Exp $
#

DISTNAME=		makedepend-1.0.1
CATEGORIES=		devel
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/util/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Dependency generator for make

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "../../x11/xproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
