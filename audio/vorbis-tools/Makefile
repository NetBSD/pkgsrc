# $NetBSD: Makefile,v 1.15 2002/08/05 13:12:43 lukem Exp $

DISTNAME=	vorbis-tools-1.0
PKGNAME=	vorbis-tools-1.0.0.8
CATEGORIES=	audio
MASTER_SITES=	http://www.vorbis.com/files/1.0/unix/

MAINTAINER=	lukem@netbsd.org
HOMEPAGE=	http://www.vorbis.com/
COMMENT=	Ogg Vorbis encoder and player

# list it into IPv6-ready packages
BUILD_DEFS+=	USE_INET6

DEPENDS=	curl>=7.9.1:../../www/curl

CONFLICTS=	vorbis-[0-9]*

USE_BUILDLINK_ONLY=	yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
CONFIGURE_ARGS+=	--with-ogg-prefix=${BUILDLINK_DIR}		\
			--with-vorbis-prefix=${BUILDLINK_DIR}		\
			--with-ao-prefix=${BUILDLINK_DIR}

PLIST_SUBST+=	DISTNAME="${DISTNAME}"

PTHREAD_OPTS+=	require

.include "../../audio/libao/buildlink.mk"
.include "../../audio/libogg/buildlink.mk"
.include "../../audio/libvorbis/buildlink.mk"

.include "../../mk/pthread.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
