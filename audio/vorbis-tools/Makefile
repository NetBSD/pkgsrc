# $NetBSD: Makefile,v 1.5 2001/08/16 05:16:29 lukem Exp $

DISTNAME=	vorbis-tools-1.0rc2
PKGNAME=	vorbis-tools-1.0.0.6
CATEGORIES=	audio
MASTER_SITES=	http://www.vorbis.com/files/rc2/unix/

MAINTAINER=	lukem@netbsd.org
HOMEPAGE=	http://www.vorbis.com/
COMMENT=	Ogg Vorbis encoder and player

CONFLICTS=	vorbis-*

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
CONFIGURE_ARGS+=	--with-ogg-prefix=${PREFIX} \
			--with-vorbis-prefix=${PREFIX} \
			--with-ao-prefix=${PREFIX}

.include "../../audio/libao/buildlink.mk"
.include "../../audio/libogg/buildlink.mk"
.include "../../audio/libvorbis/buildlink.mk"

.include "../../mk/bsd.pkg.mk"
