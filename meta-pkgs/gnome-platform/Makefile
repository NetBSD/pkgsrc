# $NetBSD: Makefile,v 1.29 2018/08/19 20:16:40 wiz Exp $

DISTNAME=	gnome-platform-2.32.1
CATEGORIES=	meta-pkgs x11 gnome
MASTER_SITES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnome.org/
COMMENT=	Meta-package for core platform libraries of the GNOME desktop

META_PACKAGE=	yes

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnome-platform
PKG_SUPPORTED_OPTIONS=	fam
PKG_SUGGESTED_OPTIONS=	fam

.include "../../mk/bsd.options.mk"

# see http://ftp.gnome.org/pub/GNOME/platform/2.32/2.32.0/sources/

DEPENDS+=	GConf>=2.32.0:../../devel/GConf
DEPENDS+=	ORBit2>=2.14.19:../../net/ORBit2
DEPENDS+=	at-spi>=1.32.0:../../devel/at-spi
DEPENDS+=	atk>=1.32.0:../../devel/atk
DEPENDS+=	libaudiofile>=0.2.7:../../audio/libaudiofile
DEPENDS+=	esound>=0.2.41:../../audio/esound
DEPENDS+=	gdk-pixbuf2>=2.22.1:../../graphics/gdk-pixbuf2
.if !empty(PKG_OPTIONS:Mfam)
DEPENDS+=	gio-fam>=2.26.1:../../sysutils/gio-fam  # This is part of glib2.
.endif
DEPENDS+=	glib2>=2.26.1:../../devel/glib2
DEPENDS+=	gnome-mime-data>=2.18.0:../../databases/gnome-mime-data
DEPENDS+=	gnome-vfs>=2.24.4:../../sysutils/gnome-vfs
DEPENDS+=	gnome-vfs-monikers>=2.15.3:../../sysutils/gnome-vfs-monikers
DEPENDS+=	gtk2+>=2.22.1:../../x11/gtk2
DEPENDS+=	gtk-doc>=1.15:../../textproc/gtk-doc
DEPENDS+=	libIDL>=0.8.14:../../net/libIDL
DEPENDS+=	libart>=2.3.21:../../graphics/libart
DEPENDS+=	libbonobo>=2.32.0:../../devel/libbonobo
DEPENDS+=	libbonoboui>=2.24.4:../../devel/libbonoboui
DEPENDS+=	libglade>=2.6.4:../../devel/libglade
DEPENDS+=	libgnome>=2.32.0:../../devel/libgnome
DEPENDS+=	libgnomecanvas>=2.30.2:../../graphics/libgnomecanvas
DEPENDS+=	libgnomeui>=2.24.4:../../devel/libgnomeui
DEPENDS+=	pango>=1.28.3:../../devel/pango

.include "../../mk/bsd.pkg.mk"
