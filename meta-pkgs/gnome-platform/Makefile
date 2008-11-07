# $NetBSD: Makefile,v 1.10 2008/11/07 14:16:53 wiz Exp $

DISTNAME=	gnome-platform-2.24.1
PKGREVISION=	1
CATEGORIES=	meta-pkgs x11 gnome
MASTER_SITES=	# empty

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Meta-package for core platform libraries of the GNOME desktop

META_PACKAGE=	yes

# see http://ftp.gnome.org/pub/GNOME/platform/2.24/2.24.1/sources/

DEPENDS+=	GConf>=2.24.0:../../devel/GConf
DEPENDS+=	ORBit2>=2.14.16:../../net/ORBit2
DEPENDS+=	at-spi>=1.24.0:../../devel/at-spi
DEPENDS+=	atk>=1.24.0:../../devel/atk
DEPENDS+=	libaudiofile>=0.2.6:../../audio/libaudiofile
DEPENDS+=	esound>=0.2.40:../../audio/esound
DEPENDS+=	glib2>=2.18.2:../../devel/glib2
DEPENDS+=	gnome-mime-data>=2.18.0:../../databases/gnome-mime-data
DEPENDS+=	gnome-vfs>=2.24.0:../../sysutils/gnome-vfs
DEPENDS+=	gnome-vfs-monikers>=2.15.3:../../sysutils/gnome-vfs-monikers
DEPENDS+=	gtk2+>=2.14.4:../../x11/gtk2
DEPENDS+=	gtk-doc>=1.10:../../textproc/gtk-doc
DEPENDS+=	intltool>=0.40.5:../../textproc/intltool
DEPENDS+=	libIDL>=0.8.11:../../net/libIDL
DEPENDS+=	libart>=2.3.20:../../graphics/libart
DEPENDS+=	libbonobo>=2.24.0:../../devel/libbonobo
DEPENDS+=	libbonoboui>=2.24.0:../../devel/libbonoboui
DEPENDS+=	libglade>=2.6.3:../../devel/libglade
DEPENDS+=	libgnome>=2.24.1:../../devel/libgnome
DEPENDS+=	libgnomecanvas>=2.20.1.1:../../graphics/libgnomecanvas
DEPENDS+=	libgnomeui>=2.24.0:../../devel/libgnomeui
DEPENDS+=	pango>=1.22.1:../../devel/pango

# XXX gnome-keyring is distributed with the "desktop" set, but is required
# by libgnomeui. List it here to avoid circular dependency.
DEPENDS+=	gnome-keyring>=2.24.1:../../security/gnome-keyring

.include "../../mk/bsd.pkg.mk"
