# $NetBSD: Makefile,v 1.1.1.1 2004/02/22 20:33:27 jmmv Exp $

DISTNAME=	gnome-devel-2.4.2
CATEGORIES=	meta-pkgs devel gnome
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Meta-package for development utilities used in the GNOME desktop

DEPENDS+=	autoconf>=2.59:../../devel/autoconf
DEPENDS+=	autoconf213>=2.13:../../devel/autoconf213
DEPENDS+=	automake>=1.8.2:../../devel/automake
DEPENDS+=	automake14>=1.4.6:../../devel/automake14
DEPENDS+=	automake17>=1.7.9:../../devel/automake17
DEPENDS+=	gettext-m4>=0.11.5:../../devel/gettext-m4
DEPENDS+=	gnome-common>=2.4.0:../../devel/gnome-common
DEPENDS+=	libtool>=1.5.2:../../devel/libtool
DEPENDS+=	pkgconfig>=0.15:../../devel/pkgconfig

EXTRACT_ONLY=	# empty
NO_BUILD=	yes
NO_BUILDLINK=	yes
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
