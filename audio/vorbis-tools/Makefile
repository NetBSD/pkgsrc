# $NetBSD: Makefile,v 1.14 2002/08/01 05:48:05 jlam Exp $

DISTNAME=	vorbis-tools-1.0rc3
PKGNAME=	vorbis-tools-1.0.0.7
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.vorbis.com/files/rc3/unix/

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
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
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
