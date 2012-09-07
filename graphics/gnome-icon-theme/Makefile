# $NetBSD: Makefile,v 1.78 2012/09/07 19:16:46 adam Exp $
#

DISTNAME=		gnome-icon-theme-2.30.3
PKGREVISION=		10
CATEGORIES=		graphics gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-icon-theme/2.30/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Theme consisting of a set of icons for GNOME
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir
NOT_FOR_BULK_PLATFORM=	HPUX-*-*

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config
# otherwise it creates lots of lib/locale dirs, even though it doesn't
# need them (!)
USE_PKGLOCALEDIR=	yes

PKGCONFIG_OVERRIDE=	gnome-icon-theme.pc.in

# The list of installed files depends on the version of
# icon-naming-utils, so be sure that this dependency corresponds to
# the current pkgsrc version.
BUILDLINK_API_DEPENDS.icon-naming-utils+=	icon-naming-utils>=0.8.90

EVAL_PREFIX+=		PREFIX.gtk2=gtk2+
FILES_SUBST+=		GTK_UPDATE_ICON_CACHE="${PREFIX.gtk2}/bin/gtk-update-icon-cache"
FILES_SUBST+=		ICON_THEME_DIR="${PREFIX}/share/icons/gnome"
INSTALL_TEMPLATES+=	../../graphics/gnome-icon-theme/files/icon-cache.tmpl
DEINSTALL_TEMPLATES+=	../../graphics/gnome-icon-theme/files/icon-cache.tmpl
PRINT_PLIST_AWK+=	/^share\/icons\/gnome\/icon-theme.cache$$/ { next; }

post-install:
	${PREFIX}/bin/rsvg-convert ${FILESDIR}/distributor-logo.svg -w 16 -h 16 -o ${DESTDIR}${PREFIX}/share/icons/gnome/16x16/places/start-here.png
	${PREFIX}/bin/rsvg-convert ${FILESDIR}/distributor-logo.svg -w 22 -h 22 -o ${DESTDIR}${PREFIX}/share/icons/gnome/22x22/places/start-here.png
	${PREFIX}/bin/rsvg-convert ${FILESDIR}/distributor-logo.svg -w 24 -h 24 -o ${DESTDIR}${PREFIX}/share/icons/gnome/24x24/places/start-here.png
	${PREFIX}/bin/rsvg-convert ${FILESDIR}/distributor-logo.svg -w 32 -h 32 -o ${DESTDIR}${PREFIX}/share/icons/gnome/32x32/places/start-here.png
	${PREFIX}/bin/rsvg-convert ${FILESDIR}/distributor-logo.svg -w 48 -h 48 -o ${DESTDIR}${PREFIX}/share/icons/gnome/48x48/places/start-here.png
	${PREFIX}/bin/rsvg-convert ${FILESDIR}/distributor-logo.svg -w 256 -h 256 -o ${DESTDIR}${PREFIX}/share/icons/gnome/256x256/places/start-here.png

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/icon-naming-utils/buildlink3.mk"
BUILDLINK_DEPMETHOD.librsvg=	build
BUILDLINK_API_DEPENDS.librsvg+=	librsvg>=2.22.3
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
