# $NetBSD: Makefile,v 1.2 2011/11/17 19:43:11 ryoon Exp $
#

DISTNAME=	libalac-r3
PKGNAME=	libalac-0.0.20111026
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://alac.macosforge.org/
COMMENT=	Apple Lossless Audio Codec is an audio codec developed by Apple
LICENSE=	apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/libalac-r3/codec
USE_LANGUAGES=	c c++
MAKE_FILE=	makefile

USE_LIBTOOL=	yes

.include "../../mk/bsd.pkg.mk"
