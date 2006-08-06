# $NetBSD: Makefile,v 1.24 2006/08/06 20:46:00 jmmv Exp $

DISTNAME=	gnome-devel-2.14.3
CATEGORIES=	meta-pkgs devel gnome
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Meta-package for development utilities used in the GNOME desktop

DEPENDS+=	autoconf>=2.60:../../devel/autoconf
DEPENDS+=	autoconf213>=2.13nb1:../../devel/autoconf213
DEPENDS+=	automake>=1.9.6:../../devel/automake
DEPENDS+=	automake14>=1.4.6:../../devel/automake14
DEPENDS+=	gettext-m4>=0.4.6:../../devel/gettext-m4
DEPENDS+=	gnome-common>=2.12.0:../../devel/gnome-common
DEPENDS+=	gnome-doc-utils>=0.6.1:../../textproc/gnome-doc-utils
DEPENDS+=	gtk-doc>=1.6:../../textproc/gtk-doc
DEPENDS+=	intltool>=0.34.2:../../textproc/intltool
DEPENDS+=	libtool>=1.5.22:../../devel/libtool
DEPENDS+=	pkg-config>=0.20:../../devel/pkg-config

EXTRACT_ONLY=	# empty
NO_BUILD=	yes
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
