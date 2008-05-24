# $NetBSD: Makefile,v 1.3 2008/05/24 21:45:20 tnn Exp $
#

DISTNAME=		encodings-1.0.2
CATEGORIES=		fonts x11
MASTER_SITES=		${MASTER_SITE_XORG:=font/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		X11 Font Index Generator

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes

USE_TOOLS+=		gzip mkfontscale

.include "../../mk/bsd.pkg.mk"
