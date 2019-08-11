# $NetBSD: Makefile,v 1.106 2019/08/11 13:17:49 wiz Exp $

DISTNAME=		gnome-icon-theme-3.12.0
PKGREVISION=		4
CATEGORIES=		graphics gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-icon-theme/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.gnome.org/
COMMENT=		Theme consisting of a set of icons for GNOME
LICENSE=		cc-by-sa-v3.0 AND gnu-lgpl-v3

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config
# otherwise it creates lots of lib/locale dirs, even though it doesn't
# need them (!)
USE_PKGLOCALEDIR=	yes
TOOLS_NOOP+=		gtk-update-icon-cache

PKGCONFIG_OVERRIDE=	gnome-icon-theme.pc.in

# The list of installed files depends on the version of
# icon-naming-utils, so be sure that this dependency corresponds to
# the current pkgsrc version.
BUILDLINK_API_DEPENDS.icon-naming-utils+=	icon-naming-utils>=0.8.90

ICON_THEMES=	yes

post-install:
	${LOCALBASE}/bin/rsvg-convert ${FILESDIR}/distributor-logo.svg -w 16 -h 16 -o ${DESTDIR}${PREFIX}/share/icons/gnome/16x16/places/start-here.png
	${LOCALBASE}/bin/rsvg-convert ${FILESDIR}/distributor-logo.svg -w 22 -h 22 -o ${DESTDIR}${PREFIX}/share/icons/gnome/22x22/places/start-here.png
	${LOCALBASE}/bin/rsvg-convert ${FILESDIR}/distributor-logo.svg -w 24 -h 24 -o ${DESTDIR}${PREFIX}/share/icons/gnome/24x24/places/start-here.png
	${LOCALBASE}/bin/rsvg-convert ${FILESDIR}/distributor-logo.svg -w 32 -h 32 -o ${DESTDIR}${PREFIX}/share/icons/gnome/32x32/places/start-here.png
	${LOCALBASE}/bin/rsvg-convert ${FILESDIR}/distributor-logo.svg -w 48 -h 48 -o ${DESTDIR}${PREFIX}/share/icons/gnome/48x48/places/start-here.png
	${LOCALBASE}/bin/rsvg-convert ${FILESDIR}/distributor-logo.svg -w 256 -h 256 -o ${DESTDIR}${PREFIX}/share/icons/gnome/256x256/places/start-here.png

BUILDLINK_DEPMETHOD.gettext-lib=	build
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/icon-naming-utils/buildlink3.mk"
.include "../../graphics/librsvg/tool.mk"
.include "../../mk/bsd.pkg.mk"
