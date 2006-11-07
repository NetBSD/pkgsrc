# $NetBSD: Makefile,v 1.14 2006/11/07 09:24:32 joerg Exp $
#

DISTNAME=	taglib-1.4
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://ktown.kde.org/~wheeler/files/src/

MAINTAINER=	chris@NetBSD.org
HOMEPAGE=	http://ktown.kde.org/~wheeler/taglib/
COMMENT=	Library for accessing id tags in mp3 and ogg files

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

pre-build:
	${CP} ${FILESDIR}/id3lib_strings.h ${WRKSRC}/taglib/toolkit/.

post-install:
	${INSTALL_DATA} ${FILESDIR}/id3lib_strings.h ${DESTDIR}${PREFIX}/include/taglib/.

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
