# $NetBSD: Makefile,v 1.3 2015/01/10 12:23:05 prlw1 Exp $

DISTNAME=		adwaita-icon-theme-3.14.1
CATEGORIES=		graphics gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=/sources/adwaita-icon-theme/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		prlw1@cam.ac.uk
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Standard GNOME icons
LICENSE=		cc-by-sa-v3.0 OR gnu-lgpl-v3

TOOL_DEPENDS+=		librsvg>=2.22.3:../../graphics/librsvg
# for gtk-encode-symbolic-svg
TOOL_DEPENDS+=		gtk3+>=3:../../x11/gtk3

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config
# otherwise it creates lots of superfluous lib/locale dirs
USE_PKGLOCALEDIR=	yes
TOOLS_NOOP+=		gtk-update-icon-cache

PKGCONFIG_OVERRIDE+=	adwaita-icon-theme.pc.in

# should be created by the upstream installation Makefile targets,
# but isn't
INSTALLATION_DIRS+=	share/icons/Adwaita/96x96/places

EVAL_PREFIX+=		PREFIX.svg=librsvg
EVAL_PREFIX+=		PREFIX.gtk2=gtk2+
FILES_SUBST+=		GTK_UPDATE_ICON_CACHE="${PREFIX.gtk2}/bin/gtk-update-icon-cache"
FILES_SUBST+=		ICON_THEME_DIR="${PREFIX}/share/icons/Adwaita"
INSTALL_TEMPLATES+=	../../graphics/adwaita-icon-theme/files/icon-cache.tmpl
DEINSTALL_TEMPLATES+=	../../graphics/adwaita-icon-theme/files/icon-cache.tmpl
PRINT_PLIST_AWK+=	/^share\/icons\/gnome\/icon-theme.cache$$/ { next; }

post-install:
.for s in 16 22 24 32 48 96 256
	 ${PREFIX.svg}/bin/rsvg-convert ${FILESDIR}/distributor-logo.svg \
	 -w ${s} -h ${s} -o \
	 ${DESTDIR}${PREFIX}/share/icons/Adwaita/${s}x${s}/places/start-here.png
.endfor

BUILDLINK_DEPMETHOD.gettext-lib=        build
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
