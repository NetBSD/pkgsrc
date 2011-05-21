# $NetBSD: Makefile,v 1.23 2011/05/21 15:13:20 wiz Exp $
#

DISTNAME=	taglib-1.7
CATEGORIES=	audio
MASTER_SITES=	http://ktown.kde.org/~wheeler/files/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://developer.kde.org/~wheeler/taglib.html
COMMENT=	Library for accessing id tags in various media files
LICENSE=	gnu-lgpl-v2.1 OR mpl-1.1

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++

USE_CMAKE=		YES
CMAKE_ARGS=		-DWITH_MP4=ON -DWITH_ASF=ON
USE_LIBTOOL=		YES

PKGCONFIG_OVERRIDE=	bindings/c/taglib_c.pc.cmake taglib.pc.cmake

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
