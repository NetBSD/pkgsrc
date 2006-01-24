# $NetBSD: Makefile,v 1.19 2006/01/24 07:32:21 wiz Exp $

DISTNAME=	gnome-devel-2.12.2
PKGREVISION=	1
CATEGORIES=	meta-pkgs devel gnome
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Meta-package for development utilities used in the GNOME desktop

DEPENDS+=	autoconf>=2.59nb2:../../devel/autoconf
DEPENDS+=	autoconf213>=2.13nb1:../../devel/autoconf213
DEPENDS+=	automake>=1.9.6:../../devel/automake
DEPENDS+=	automake14>=1.4.6:../../devel/automake14
DEPENDS+=	gettext-m4>=0.11.5:../../devel/gettext-m4
DEPENDS+=	gnome-common>=2.12.0:../../devel/gnome-common
DEPENDS+=	gnome-doc-utils>=0.4.4:../../textproc/gnome-doc-utils
DEPENDS+=	gtk-doc>=1.4:../../textproc/gtk-doc
DEPENDS+=	intltool>=0.34.1:../../textproc/intltool
DEPENDS+=	libtool>=1.5.18:../../devel/libtool
DEPENDS+=	pkg-config>=0.19nb1:../../devel/pkg-config

EXTRACT_ONLY=	# empty
NO_BUILD=	yes
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
