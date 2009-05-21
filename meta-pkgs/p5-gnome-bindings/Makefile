# $NetBSD: Makefile,v 1.8 2009/05/21 20:40:03 wiz Exp $

DISTNAME=	p5-gnome-bindings-2.26.1.91
CATEGORIES=	meta-pkgs x11 gnome
MASTER_SITES=	# empty

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Meta-package for Perl bindings for the GNOME desktop

META_PACKAGE=	yes

# see http://ftp.gnome.org/pub/GNOME/bindings/2.26/2.26.2/sources/perl/

DEPENDS+=	p5-glib2>=1.220:../../devel/p5-glib2
# unpackaged
#DEPENDS+=	p5-Gnome2>=1.042:../../devel/p5-Gnome2
# unpackaged
#DEPENDS+=	p5-Gnome2-Canvas>=1.002:../../devel/p5-Gnome2-Canvas
# unpackaged
#DEPENDS+=	p5-Gnome2-GConf>=1.044:../../devel/p5-Gnome2-GConf
# unpackaged
#DEPENDS+=	p5-Gnome2-VFS>=1.081:../../devel/p5-Gnome2-VFS
DEPENDS+=	p5-gtk2>=1.220:../../x11/p5-gtk2
DEPENDS+=	p5-Gtk2-GladeXML>=1.007:../../x11/p5-Gtk2-GladeXML
DEPENDS+=	p5-pango>=1.220:../../devel/p5-pango

.include "../../mk/bsd.pkg.mk"
