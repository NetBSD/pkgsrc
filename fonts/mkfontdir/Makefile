# $NetBSD: Makefile,v 1.8 2012/06/03 18:34:38 wiz Exp $
#

DISTNAME=		mkfontdir-1.0.7
CATEGORIES=		fonts x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		X11 Font Index Generator

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		mkfontscale>=1.0.1:../../fonts/mkfontscale

GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
