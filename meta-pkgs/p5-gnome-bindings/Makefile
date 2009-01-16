# $NetBSD: Makefile,v 1.5 2009/01/16 14:40:32 wiz Exp $

DISTNAME=	p5-gnome-bindings-2.24.2.90
CATEGORIES=	meta-pkgs x11 gnome
MASTER_SITES=	# empty

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Meta-package for Perl bindings for the GNOME desktop

META_PACKAGE=	yes

# see http://ftp.gnome.org/pub/GNOME/bindings/2.24/2.24.3/sources/perl/

DEPENDS+=	p5-glib2>=1.200:../../devel/p5-glib2
# unpackaged
#DEPENDS+=	p5-gnome2>=1.042:../../devel/p5-gnome2
# unpackaged
#DEPENDS+=	p5-gnome2-canvas>=1.002:../../devel/p5-gnome2-canvas
# unpackaged
#DEPENDS+=	p5-gnome2-gconf>=1.044:../../devel/p5-gnome2-gconf
# unpackaged
#DEPENDS+=	p5-gnome2-vfs>=1.081:../../devel/p5-gnome2-vfs
DEPENDS+=	p5-gtk2>=1.201:../../x11/p5-gtk2
# unpackaged
#DEPENDS+=	p5-gtk2-gladexml>=1.007:../../x11/p5-gtk2-gladexml

.include "../../mk/bsd.pkg.mk"
