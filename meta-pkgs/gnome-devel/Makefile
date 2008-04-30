# $NetBSD: Makefile,v 1.28 2008/04/30 13:38:15 jmmv Exp $

DISTNAME=	gnome-devel-2.16.0
CATEGORIES=	meta-pkgs devel gnome
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Meta-package for development utilities used in the GNOME desktop

DEPENDS+=	autoconf>=2.60:../../devel/autoconf
DEPENDS+=	autoconf213>=2.13nb1:../../devel/autoconf213
DEPENDS+=	automake>=1.9.6:../../devel/automake
DEPENDS+=	automake14>=1.4.6:../../devel/automake14
DEPENDS+=	gettext-m4>=0.14.6:../../devel/gettext-m4
DEPENDS+=	gnome-common>=2.12.0:../../devel/gnome-common
DEPENDS+=	gnome-doc-utils>=0.8.0:../../textproc/gnome-doc-utils
DEPENDS+=	gtk-doc>=1.7:../../textproc/gtk-doc
DEPENDS+=	intltool>=0.35.0:../../textproc/intltool
DEPENDS+=	libtool>=1.5.22:../../devel/libtool
DEPENDS+=	pkg-config>=0.21:../../devel/pkg-config

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
