# $NetBSD: Makefile,v 1.6 2001/08/23 16:54:37 jlam Exp $

DISTNAME=	vorbis-tools-1.0rc2
PKGNAME=	vorbis-tools-1.0.0.6
CATEGORIES=	audio
MASTER_SITES=	http://www.vorbis.com/files/rc2/unix/

MAINTAINER=	lukem@netbsd.org
HOMEPAGE=	http://www.vorbis.com/
COMMENT=	Ogg Vorbis encoder and player

CONFLICTS=	vorbis-*

USE_BUILDLINK_ONLY=	yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
CONFIGURE_ARGS+=	--with-ogg-prefix=${BUILDLINK_DIR}		\
			--with-vorbis-prefix=${BUILDLINK_DIR}		\
			--with-ao-prefix=${BUILDLINK_DIR}

.include "../../audio/libao/buildlink.mk"
.include "../../audio/libogg/buildlink.mk"
.include "../../audio/libvorbis/buildlink.mk"

.include "../../mk/bsd.pkg.mk"
