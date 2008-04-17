# $NetBSD: Makefile,v 1.4 2008/04/17 21:13:11 wiz Exp $
#

DISTNAME=		mkfontdir-1.0.4
CATEGORIES=		fonts x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/app/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		X11 Font Index Generator

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		mkfontscale>=1.0.1:../../fonts/mkfontscale

GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
