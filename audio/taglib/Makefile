# $NetBSD: Makefile,v 1.16 2008/03/04 10:31:01 wiz Exp $
#

DISTNAME=	taglib-1.5
CATEGORIES=	audio
MASTER_SITES=	http://ktown.kde.org/~wheeler/files/src/

MAINTAINER=	chris@NetBSD.org
HOMEPAGE=	http://developer.kde.org/~wheeler/taglib.html
COMMENT=	Library for accessing id tags in mp3 and ogg files

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
