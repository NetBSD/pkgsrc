# $NetBSD: Makefile,v 1.16 2002/08/25 21:49:29 jlam Exp $

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

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
CONFIGURE_ARGS+=	--with-ogg-prefix=${BUILDLINK_PREFIX.libogg}	\
			--with-vorbis-prefix=${BUILDLINK_PREFIX.libvorbis} \
			--with-ao-prefix=${BUILDLINK_PREFIX.libao}

PLIST_SUBST+=	DISTNAME="${DISTNAME}"

PTHREAD_OPTS+=	require

.include "../../audio/libao/buildlink2.mk"
.include "../../audio/libogg/buildlink2.mk"
.include "../../audio/libvorbis/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
