# $NetBSD: Makefile,v 1.26 2014/05/05 00:47:56 ryoon Exp $
#

DISTNAME=	exif-browser
PKGNAME=	gimp-exif-browser-0.1.0
DIST_SUBDIR=	gimp-exif-browser-0.1.0
PKGREVISION=	24
CATEGORIES=	graphics
MASTER_SITES=	http://registry.gimp.org/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://registry.gimp.org/node/8839
COMMENT=	EXIF data browser plugin
#LICENSE=	# TODO: (see mk/license.mk)

USE_TOOLS+=	intltool pkg-config

GNU_CONFIGURE=	yes

.include "../../graphics/gimp/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
