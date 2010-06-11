# $NetBSD: Makefile,v 1.23 2010/06/11 13:50:10 drochner Exp $

DISTNAME=	gnome-platform-2.30.1
CATEGORIES=	meta-pkgs x11 gnome
MASTER_SITES=	# empty

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Meta-package for core platform libraries of the GNOME desktop

META_PACKAGE=	yes

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnome-platform
PKG_SUPPORTED_OPTIONS=	fam
PKG_SUGGESTED_OPTIONS=	fam

.include "../../mk/bsd.options.mk"

# see http://ftp.gnome.org/pub/GNOME/platform/2.30/2.30.1/sources/

DEPENDS+=	GConf>=2.28.1:../../devel/GConf
DEPENDS+=	ORBit2>=2.14.18:../../net/ORBit2
DEPENDS+=	at-spi>=1.30.1:../../devel/at-spi
DEPENDS+=	atk>=1.30.0:../../devel/atk
DEPENDS+=	libaudiofile>=0.2.7:../../audio/libaudiofile
DEPENDS+=	esound>=0.2.41:../../audio/esound
.if !empty(PKG_OPTIONS:Mfam)
DEPENDS+=	gio-fam>=2.24.0:../../sysutils/gio-fam  # This is part of glib2.
.endif
DEPENDS+=	glib2>=2.24.0:../../devel/glib2
DEPENDS+=	gnome-mime-data>=2.18.0:../../databases/gnome-mime-data
DEPENDS+=	gnome-vfs>=2.24.3:../../sysutils/gnome-vfs
DEPENDS+=	gnome-vfs-monikers>=2.15.3:../../sysutils/gnome-vfs-monikers
DEPENDS+=	gtk2+>=2.20.0:../../x11/gtk2
DEPENDS+=	gtk-doc>=1.14:../../textproc/gtk-doc
DEPENDS+=	libIDL>=0.8.14:../../net/libIDL
DEPENDS+=	libart>=2.3.21:../../graphics/libart
DEPENDS+=	libbonobo>=2.24.3:../../devel/libbonobo
DEPENDS+=	libbonoboui>=2.24.3:../../devel/libbonoboui
DEPENDS+=	libglade>=2.6.4:../../devel/libglade
DEPENDS+=	libgnome>=2.30.0:../../devel/libgnome
DEPENDS+=	libgnomecanvas>=2.30.1:../../graphics/libgnomecanvas
DEPENDS+=	libgnomeui>=2.24.3:../../devel/libgnomeui
DEPENDS+=	pango>=1.28.0:../../devel/pango

.include "../../mk/bsd.pkg.mk"
