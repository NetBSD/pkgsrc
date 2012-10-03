# $NetBSD: Makefile,v 1.6 2012/10/03 18:28:18 asau Exp $
#

DISTNAME=		encodings-1.0.4
CATEGORIES=		fonts x11
MASTER_SITES=		${MASTER_SITE_XORG:=font/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		X11 Font Index Generator

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-fontrootdir=${PREFIX}/lib/X11/fonts

USE_TOOLS+=		gzip mkfontscale

.include "../../mk/bsd.pkg.mk"
