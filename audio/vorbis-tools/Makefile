# $NetBSD: Makefile,v 1.8 2002/01/02 12:45:42 lukem Exp $

DISTNAME=	vorbis-tools-1.0rc3
PKGNAME=	vorbis-tools-1.0.0.7
CATEGORIES=	audio
MASTER_SITES=	http://www.vorbis.com/files/rc3/unix/

MAINTAINER=	lukem@netbsd.org
HOMEPAGE=	http://www.vorbis.com/
COMMENT=	Ogg Vorbis encoder and player

DEPENDS=	curl-7.9.1:../../www/curl

CONFLICTS=	vorbis-[0-9]*

USE_BUILDLINK_ONLY=	yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
CONFIGURE_ARGS+=	--with-ogg-prefix=${BUILDLINK_DIR}		\
			--with-vorbis-prefix=${BUILDLINK_DIR}		\
			--with-ao-prefix=${BUILDLINK_DIR}

# GLib needs a working pthreads implementation, and pth is proven to work.
USE_PTHREAD=	native pth

.include "../../mk/bsd.prefs.mk"

.include "../../audio/libao/buildlink.mk"
.include "../../audio/libogg/buildlink.mk"
.include "../../audio/libvorbis/buildlink.mk"

.include "../../mk/pthread.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
