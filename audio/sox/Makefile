# $NetBSD: Makefile,v 1.19 2002/11/25 19:02:45 wiz Exp $
#

DISTNAME=	sox-12.17.3
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://home.sprynet.com/~cbagwell/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://home.sprynet.com/~cbagwell/sox.html
COMMENT=	SOund eXchange - universal sound sample translator

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-fast-ulaw \
			--enable-fast-alaw \
			--with-sun-audio \
			--without-oss-dsp \
			--with-ogg-vorbislib=${BUILDLINK_PREFIX.libvorbis}/lib \
			--with-ogg-vorbisinc=${BUILDLINK_PREFIX.libvorbis}/include

.include "../../audio/libvorbis/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
