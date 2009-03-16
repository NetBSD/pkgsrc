# $NetBSD: Makefile,v 1.1.1.1 2009/03/16 10:49:06 jmcneill Exp $
#

DISTNAME=	brasero-2.26.0
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/brasero/2.26/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://projects.gnome.org/brasero/
COMMENT=	Disc-burning software for the GNOME desktop

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	GCONF_SCHEMA_FILE_DIR=${PREFIX}/share/gconf/schemas/
MAKE_ENV+=	GCONF_SCHEMA_FILE_DIR=${PREFIX}/share/gconf/schemas/
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake intltool autoconf automake gawk
USE_DIRS+=	gnome2-1.6

CONFIGURE_ARGS+=	--disable-inotify

GCONF_SCHEMAS+=		brasero.schemas
PKGCONFIG_OVERRIDE+=	libbrasero-media.pc.in

post-extract:
	cp ${FILESDIR}/scsi-netbsd.c ${WRKSRC}/libbrasero-media/

# The gettext version in pkgsrc cannot handle the .po files, so
# we strip out usage of the newer features (context and fuzzy matches)
post-patch:
	for f in ${WRKSRC}/po/*.po; do \
		mv $$f $$f.original ; \
		${AWK} -f ${FILESDIR}/msgfmtstrip $$f.original > $$f ; \
	done

pre-configure:
	cd ${WRKSRC} && automake && autoconf

.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
BUILDLINK_API_DEPENDS.gst-plugins0.10-base+=	gst-plugins0.10-base>=0.10.10
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
BUILDLINK_API_DEPENDS.gstreamer0.10+=		gstreamer0.10>=0.10.15
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/hal/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../sysutils/nautilus/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../mk/bsd.pkg.mk"
