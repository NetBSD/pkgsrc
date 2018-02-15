# $NetBSD: Makefile,v 1.2 2018/02/15 08:15:55 bsiegert Exp $

DISTNAME=	gexiv2-0.10.8
CATEGORIES=	graphics devel
MASTER_SITES=	http://ftp.acc.umu.se/pub/gnome/sources/gexiv2/0.10/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/gexiv2
COMMENT=	GObject-based wrapper around the Exiv2 library
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake m4 pkg-config bash
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE=	gexiv2.m4

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
