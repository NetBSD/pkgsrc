# $NetBSD: Makefile,v 1.5 2008/05/29 10:48:59 drochner Exp $

DISTNAME=	gnome-platform-2.22.2
CATEGORIES=	meta-pkgs x11 gnome
MASTER_SITES=	# empty

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Meta-package for core platform libraries of the GNOME desktop

DEPENDS+=	GConf>=2.22.0:../../devel/GConf
DEPENDS+=	ORBit2>=2.14.12:../../net/ORBit2
DEPENDS+=	at-spi>=1.22.1:../../devel/at-spi
DEPENDS+=	atk>=1.22.0:../../devel/atk
DEPENDS+=	libaudiofile>=0.2.6:../../audio/libaudiofile
DEPENDS+=	esound>=0.2.38:../../audio/esound
DEPENDS+=	gail>=1.22.1:../../devel/gail
DEPENDS+=	glib2>=2.16.3:../../devel/glib2
DEPENDS+=	gnome-mime-data>=2.18.0:../../databases/gnome-mime-data
DEPENDS+=	gnome-vfs>=2.22.0:../../sysutils/gnome-vfs
DEPENDS+=	gnome-vfs-monikers>=2.15.3:../../sysutils/gnome-vfs-monikers
DEPENDS+=	gtk2+>=2.12.9:../../x11/gtk2
DEPENDS+=	gtk-doc>=1.9:../../textproc/gtk-doc
DEPENDS+=	intltool>=0.37.1:../../textproc/intltool
DEPENDS+=	libIDL>=0.8.10:../../net/libIDL
DEPENDS+=	libart>=2.3.20:../../graphics/libart
DEPENDS+=	libbonobo>=2.22.0:../../devel/libbonobo
DEPENDS+=	libbonoboui>=2.22.0:../../devel/libbonoboui
DEPENDS+=	libglade>=2.6.2:../../devel/libglade
DEPENDS+=	libgnome>=2.22.0:../../devel/libgnome
DEPENDS+=	libgnomecanvas>=2.20.1.1:../../graphics/libgnomecanvas
DEPENDS+=	libgnomeui>=2.22.1:../../devel/libgnomeui
DEPENDS+=	pango>=1.20.3:../../devel/pango

# XXX gnome-keyring is distributed with the "desktop" set, but is required
# by libgnomeui. List it here to avoid circular dependency.
DEPENDS+=	gnome-keyring>=2.22.2:../../security/gnome-keyring

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
