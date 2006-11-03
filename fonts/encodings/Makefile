# $NetBSD: Makefile,v 1.1.1.1 2006/11/03 19:10:40 joerg Exp $
#

DISTNAME=		encodings-1.0.1
CATEGORIES=		fonts x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/font/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		X11 Font Index Generator

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes

USE_TOOLS+=		gzip mkfontscale

.include "../../mk/bsd.pkg.mk"
