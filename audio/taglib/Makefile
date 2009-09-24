# $NetBSD: Makefile,v 1.18 2009/09/24 10:24:52 wiz Exp $
#

DISTNAME=	taglib-1.6
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://ktown.kde.org/~wheeler/files/src/

MAINTAINER=	chris@NetBSD.org
HOMEPAGE=	http://developer.kde.org/~wheeler/taglib.html
COMMENT=	Library for accessing id tags in various media files

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-asf
CONFIGURE_ARGS+=	--enable-mp4

USE_LIBTOOL=		YES

PKGCONFIG_OVERRIDE=	bindings/c/taglib_c.pc.in taglib.pc.in

pre-build:
	cp ${FILESDIR}/id3lib_strings.h ${WRKSRC}/taglib/toolkit/.

post-install:
	${INSTALL_DATA} ${FILESDIR}/id3lib_strings.h ${DESTDIR}${PREFIX}/include/taglib/.

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
