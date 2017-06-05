# $NetBSD: Makefile,v 1.16 2017/06/05 14:24:13 ryoon Exp $

DISTNAME=	p5-gnome-bindings-2.30.2
PKGREVISION=	6
CATEGORIES=	meta-pkgs x11 gnome
MASTER_SITES=	# empty

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Meta-package for Perl bindings for the GNOME desktop

META_PACKAGE=	yes

# see http://ftp.gnome.org/pub/GNOME/bindings/2.30/2.30.2/sources/perl/

DEPENDS+=	p5-glib2>=1.222:../../devel/p5-glib2
DEPENDS+=	p5-Gnome2>=1.042:../../devel/p5-Gnome2
DEPENDS+=	p5-Gnome2-Canvas>=1.002:../../graphics/p5-Gnome2-Canvas
DEPENDS+=	p5-Gnome2-GConf>=1.044:../../devel/p5-Gnome2-GConf
DEPENDS+=	p5-Gnome2-VFS>=1.081:../../sysutils/p5-Gnome2-VFS
DEPENDS+=	p5-gtk2>=1.221:../../x11/p5-gtk2
DEPENDS+=	p5-Gtk2-GladeXML>=1.007:../../devel/p5-Gtk2-GladeXML
DEPENDS+=	p5-pango>=1.221:../../devel/p5-pango

.include "../../mk/bsd.pkg.mk"
