# $NetBSD: Makefile,v 1.5 2003/12/08 14:41:38 wiz Exp $

DISTNAME=	vorbis-tools-1.0
PKGREVISION=	2
PKGNAME=	tremor-tools-1.0.0.8
CATEGORIES=	audio
MASTER_SITES=	http://www.vorbis.com/files/1.0/unix/

MAINTAINER=	chris@NetBSD.org
HOMEPAGE=	http://www.vorbis.com/
COMMENT=	Ogg Vorbis encoder and player

# list it into IPv6-ready packages
BUILD_DEFS+=	USE_INET6

CONFLICTS=	vorbis-[0-9]*

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_GMAKE=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
CONFIGURE_ARGS+=	--with-ogg-prefix=${BUILDLINK_PREFIX.libogg}	\
			--with-vorbis-prefix=${BUILDLINK_PREFIX.libvorbis} \
			--with-ao-prefix=${BUILDLINK_PREFIX.libao}

PLIST_SUBST+=	DISTNAME="${DISTNAME}"

AUTOMAKE_REQD=	1.4
PTHREAD_OPTS+=	require

pre-configure:
	cd ${WRKSRC} && ${AUTOMAKE}
	cd ${WRKSRC} && ${AUTOCONF}

.include "../../mk/automake.mk"
.include "../../audio/tremor/buildlink2.mk"
.include "../../audio/libvorbis/buildlink2.mk"
.include "../../audio/libao/buildlink2.mk"
.include "../../audio/libogg/buildlink2.mk"
.include "../../www/curl/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
