# $NetBSD: Makefile,v 1.5 2004/08/21 11:30:28 markd Exp $
#

DISTNAME=	taglib-1.2
CATEGORIES=	audio
MASTER_SITES=	http://ktown.kde.org/~wheeler/files/src/

MAINTAINER=	chris@NetBSD.org
HOMEPAGE=	http://ktown.kde.org/~wheeler/taglib/
COMMENT=	Library for accessing id tags in mp3 and ogg files

USE_LANGUAGES=		c c++

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

pre-build:
	${CP} ${FILESDIR}/id3lib_strings.h ${WRKSRC}/taglib/toolkit/.

post-install:
	${INSTALL} -c -o ${ROOT_USER} -g ${ROOT_GROUP} -m 444 \
		${FILESDIR}/id3lib_strings.h ${LOCALBASE}/include/taglib/.

.include "../../mk/bsd.pkg.mk"
