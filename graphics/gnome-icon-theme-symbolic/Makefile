# $NetBSD: Makefile,v 1.1.1.1 2010/06/05 10:25:43 wiz Exp $
#

DISTNAME=		gnome-icon-theme-symbolic-2.30.0
CATEGORIES=		graphics gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-icon-theme-symbolic/2.30/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Symbolic icons for the GNOME icon sets
#LICENSE=		Creative Commons Attribution-Share Alike 3.0 United States License

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config

.include "../../devel/gettext-lib/buildlink3.mk"
# The list of installed files depends on the version of
# icon-naming-utils, so be sure that this dependency corresponds to
# the current pkgsrc version.
BUILDLINK_API_DEPENDS.icon-naming-utils+=	icon-naming-utils>=0.8.90
.include "../../graphics/icon-naming-utils/buildlink3.mk"
BUILD_DEPENDS+=	librsvg>=2.22.3:../../graphics/librsvg
.include "../../mk/bsd.pkg.mk"
