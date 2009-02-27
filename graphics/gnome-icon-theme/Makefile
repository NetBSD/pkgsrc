# $NetBSD: Makefile,v 1.61 2009/02/27 07:38:08 hira Exp $
#

DISTNAME=		gnome-icon-theme-2.24.0
PKGREVISION=		2
CATEGORIES=		graphics gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-icon-theme/2.24/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Theme consisting of a set of icons for GNOME

PKG_DESTDIR_SUPPORT=	user-destdir
NOT_FOR_BULK_PLATFORM=	HPUX-*-*

GNU_CONFIGURE=		yes
USE_DIRS+=		xdg-1.1
USE_TOOLS+=		gmake intltool msgfmt perl pkg-config
USE_PKGLOCALEDIR=	yes

PKGCONFIG_OVERRIDE=	gnome-icon-theme.pc.in

# The list of installed files depends on the version of
# icon-naming-utils, so be sure that this dependency corresponds to
# the current pkgsrc version.
BUILDLINK_API_DEPENDS.icon-naming-utils+=	icon-naming-utils>=0.8.90

# XXX this is used by applications. We "own" the subtree share/icons/gnome,
# so we control the subdirs not belonging to a single application.
post-install:
	${MKDIR} ${DESTDIR}${PREFIX}/share/icons/gnome/48x48/mimetypes
	${INSTALL_DATA} ${FILESDIR}/distributor-logo.svg ${DESTDIR}${PREFIX}/share/icons/gnome/scalable/places/distributor-logo.svg
	${PREFIX}/bin/rsvg-convert ${FILESDIR}/distributor-logo.svg -w 16 -h 16 -o ${DESTDIR}${PREFIX}/share/icons/gnome/16x16/places/distributor-logo.png
	${PREFIX}/bin/rsvg-convert ${FILESDIR}/distributor-logo.svg -w 22 -h 22 -o ${DESTDIR}${PREFIX}/share/icons/gnome/22x22/places/distributor-logo.png
	${PREFIX}/bin/rsvg-convert ${FILESDIR}/distributor-logo.svg -w 24 -h 24 -o ${DESTDIR}${PREFIX}/share/icons/gnome/24x24/places/distributor-logo.png
	${PREFIX}/bin/rsvg-convert ${FILESDIR}/distributor-logo.svg -w 32 -h 32 -o ${DESTDIR}${PREFIX}/share/icons/gnome/32x32/places/distributor-logo.png

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/icon-naming-utils/buildlink3.mk"
BUILD_DEPENDS+=	librsvg>=2.22.3:../../graphics/librsvg
.include "../../mk/bsd.pkg.mk"
