# $NetBSD: Makefile,v 1.46 2022/04/18 19:11:16 adam Exp $

DISTNAME=	exif-browser
PKGNAME=	gimp-exif-browser-0.1.0
DIST_SUBDIR=	gimp-exif-browser-0.1.0
PKGREVISION=	43
CATEGORIES=	graphics
MASTER_SITES=	http://registry.gimp.org/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://registry.gimp.org/node/8839
COMMENT=	EXIF data browser plugin
LICENSE=	gnu-lgpl-v2.1 # see work/exif-browser/COPYING

USE_TOOLS+=	intltool pkg-config

GNU_CONFIGURE=	yes

.include "../../graphics/gimp/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
