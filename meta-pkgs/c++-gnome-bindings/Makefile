# $NetBSD: Makefile,v 1.10 2018/08/19 20:16:40 wiz Exp $

DISTNAME=	c++-gnome-bindings-2.26.2
CATEGORIES=	meta-pkgs x11 gnome
MASTER_SITES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnome.org/
COMMENT=	Meta-package for C++ bindings for the GNOME desktop

META_PACKAGE=	yes

PREV_PKGPATH=   meta-pkgs/gnome-bindings-c++
SUPERSEDES=	gnome-bindings-c++-[0-9]*

# see http://ftp.gnome.org/pub/GNOME/bindings/2.26/2.26.2/sources/c++/

DEPENDS+=	gconfmm>=2.24.0:../../devel/gconfmm
DEPENDS+=	glibmm>=2.20.0:../../devel/glibmm
DEPENDS+=	gnome-vfsmm>=2.26.0:../../sysutils/gnome-vfsmm
DEPENDS+=	gtkmm>=2.16.0:../../x11/gtkmm
DEPENDS+=	libglademm>=2.6.7:../../devel/libglademm
DEPENDS+=	libgnomecanvasmm>=2.26.0:../../graphics/libgnomecanvasmm
DEPENDS+=	libgnomemm>=2.26.0:../../devel/libgnomemm
DEPENDS+=	libgnomeuimm>=2.26.0:../../devel/libgnomeuimm
DEPENDS+=	libsigc++>=2.2.3:../../devel/libsigc++
DEPENDS+=	libxml++>=2.26.0:../../textproc/libxml++
DEPENDS+=	pangomm>=2.24.0:../../devel/pangomm

.include "../../mk/bsd.pkg.mk"
