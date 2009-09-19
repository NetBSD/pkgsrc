# $NetBSD: Makefile,v 1.17 2009/09/19 13:38:31 wiz Exp $
#

DISTNAME=	taglib-1.6
CATEGORIES=	audio
MASTER_SITES=	http://ktown.kde.org/~wheeler/files/src/

MAINTAINER=	chris@NetBSD.org
HOMEPAGE=	http://developer.kde.org/~wheeler/taglib.html
COMMENT=	Library for accessing id tags in various media files

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

PKGCONFIG_OVERRIDE=	bindings/c/taglib_c.pc.in taglib.pc.in

pre-build:
	cp ${FILESDIR}/id3lib_strings.h ${WRKSRC}/taglib/toolkit/.

post-install:
	${INSTALL_DATA} ${FILESDIR}/id3lib_strings.h ${DESTDIR}${PREFIX}/include/taglib/.

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
