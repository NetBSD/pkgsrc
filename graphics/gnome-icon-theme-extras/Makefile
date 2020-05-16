# $NetBSD: Makefile,v 1.7 2020/05/16 17:33:27 nia Exp $
#

DISTNAME=		gnome-icon-theme-extras-3.12.0
CATEGORIES=		graphics gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-icon-theme-extras/3.12/}
EXTRACT_SUFX=		.tar.xz

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
