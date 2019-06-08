# $NetBSD: Makefile,v 1.6 2019/06/08 20:01:58 leot Exp $
#

DISTNAME=		gnome-icon-theme-extras-2.30.1
PKGREVISION=		2
CATEGORIES=		graphics gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-icon-theme-extras/2.30/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.gnome.org/
COMMENT=		Extra icons for the GNOME icon sets
#LICENSE=		Creative Commons Attribution-Share Alike 3.0 United States License

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config

.include "../../devel/gettext-lib/buildlink3.mk"
# The list of installed files depends on the version of
# icon-naming-utils, so be sure that this dependency corresponds to
# the current pkgsrc version.
BUILDLINK_API_DEPENDS.icon-naming-utils+=	icon-naming-utils>=0.8.90
.include "../../graphics/icon-naming-utils/buildlink3.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
