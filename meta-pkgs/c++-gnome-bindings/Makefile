# $NetBSD: Makefile,v 1.1.1.1 2008/11/10 16:35:48 wiz Exp $

DISTNAME=	c++-gnome-bindings-2.24.0.90
CATEGORIES=	meta-pkgs x11 gnome
MASTER_SITES=	# empty

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Meta-package for C++ bindings for the GNOME desktop

META_PACKAGE=	yes

# see http://ftp.gnome.org/pub/GNOME/bindings/2.24/2.24.1/sources/c++/

# outdated
#DEPENDS+=	gconfmm>=2.24.0:../../devel/gconfmm
DEPENDS+=	gconfmm-[0-9]*:../../devel/gconfmm
DEPENDS+=	glibmm>=2.18.1:../../devel/glibmm
# outdated
#DEPENDS+=	gnome-vfsmm>=2.24.0:../../sysutils/gnome-vfsmm
DEPENDS+=	gnome-vfsmm-[0-9]*:../../sysutils/gnome-vfsmm
DEPENDS+=	gtkmm>=2.14.1:../../x11/gtkmm
# outdated
#DEPENDS+=	libglademm>=2.6.7:../../devel/libglademm
DEPENDS+=	libglademm-[0-9]*:../../devel/libglademm
# outdated
#DEPENDS+=	libgnomecanvasmm>=2.23.1:../../graphics/libgnomecanvasmm
DEPENDS+=	libgnomecanvasmm-[0-9]*:../../graphics/libgnomecanvasmm
# outdated
#DEPENDS+=	libgnomemm>=2.24.0:../../devel/libgnomemm
DEPENDS+=	libgnomemm-[0-9]*:../../devel/libgnomemm
# outdated
#DEPENDS+=	libgnomeuimm>=2.24.0:../../devel/libgnomeuimm
DEPENDS+=	libgnomeuimm-[0-9]*:../../devel/libgnomeuimm
DEPENDS+=	libsigc++>=2.2.3:../../devel/libsigc++
# outdated
#DEPENDS+=	libxml++>=2.24.0:../../textproc/libxml++
DEPENDS+=	libxml++-[0-9]*:../../textproc/libxml++
DEPENDS+=	pangomm>=2.14.0:../../devel/pangomm

.include "../../mk/bsd.pkg.mk"
