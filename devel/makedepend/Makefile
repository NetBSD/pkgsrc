# $NetBSD: Makefile,v 1.3 2008/05/24 21:45:20 tnn Exp $
#

DISTNAME=		makedepend-1.0.1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_XORG:=util/}
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
