# $NetBSD: Makefile,v 1.1.1.1 2004/02/09 00:30:24 chris Exp $
#

DISTNAME=	taglib-1.0
CATEGORIES=	audio
MASTER_SITES=	http://ktown.kde.org/~wheeler/taglib/

MAINTAINER=	chris@NetBSD.org
HOMEPAGE=	http://ktown.kde.org/~wheeler/taglib/
COMMENT=	Library for accessing id tags in mp3 and ogg files

USE_LANGUAGES=		c c++

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

pre-build:
	${CP} ${FILESDIR}/id3lib_strings.h ${WRKSRC}/taglib/toolkit/.

post-install:
	${INSTALL} -o ${ROOT_USER} -g ${ROOT_GROUP} -m 444 ${FILESDIR}/id3lib_strings.h ${LOCALBASE}/include/taglib/.

.include "../../mk/bsd.pkg.mk"
