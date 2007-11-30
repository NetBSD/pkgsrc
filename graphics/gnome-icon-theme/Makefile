# $NetBSD: Makefile,v 1.54 2007/11/30 16:04:07 drochner Exp $
#

DISTNAME=		gnome-icon-theme-2.20.0
PKGREVISION=		1
CATEGORIES=		graphics gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-icon-theme/2.20/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Theme consisting of a set of icons for GNOME

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_DIRS+=		xdg-1.1
USE_TOOLS+=		gmake intltool msgfmt perl pkg-config
USE_PKGLOCALEDIR=	yes

PKGCONFIG_OVERRIDE=	gnome-icon-theme.pc.in

# The list of installed files depends on the version of
# icon-naming-utils, so be sure that this dependency corresponds to
# the current pkgsrc version.
BUILDLINK_API_DEPENDS.icon-naming-utils+=	icon-naming-utils>=0.8.6

# XXX this is used by applications. We "own" the subtree share/icons/gnome,
# so we control the subdirs not belonging to a single application.
post-install:
	${MKDIR} ${DESTDIR}${PREFIX}/share/icons/gnome/48x48/mimetypes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/icon-naming-utils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
