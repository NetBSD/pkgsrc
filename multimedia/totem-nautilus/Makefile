# $NetBSD: Makefile,v 1.1.1.1 2008/04/28 17:20:20 drochner Exp $
#

DISTNAME=	totem-2.22.2
PKGNAME=	totem-nautilus-2.22.2
CATEGORIES=	multimedia gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/totem/2.22/}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.gnome.org/projects/totem/
COMMENT=	Movie player for the GNOME Desktop

DISTINFO_FILE=	${.CURDIR}/../../multimedia/totem/distinfo
PATCHDIR=	${.CURDIR}/../../multimedia/totem/patches

# this does too much, we'd need dir-target pairs
#BUILD_DIRS=	data lib src/backend src/plugins/properties src

GNU_CONFIGURE=		YES
USE_DIRS+=		gnome2-1.5
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
USE_LANGUAGES=		c c++

do-install:
	cd ${WRKSRC}/src && ${LIBTOOL} --mode=install ${INSTALL_DATA} \
	 libtotem-properties-page.la ${PREFIX}/lib/nautilus/extensions-2.0

BUILDLINK_API_DEPENDS.glib2+=			glib2>=2.8.0
BUILDLINK_API_DEPENDS.gnome-icon-theme+=	gnome-icon-theme>=2.10.0
BUILDLINK_API_DEPENDS.gtk2+=			gtk2+>=2.6.0

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/nautilus/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-good/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../multimedia/totem-pl-parser/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
