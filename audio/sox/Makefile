# $NetBSD: Makefile,v 1.28 2004/10/03 00:13:09 tv Exp $

DISTNAME=	sox-12.17.4
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sox/} \
		http://www.cnpbagwell.com/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://sox.sourceforge.net/
COMMENT=	SOund eXchange - universal sound sample translator

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-fast-ulaw \
			--enable-fast-alaw \
			--with-sun-audio \
			--disable-oss-dsp \
			--with-ogg-vorbislib=${BUILDLINK_PREFIX.libvorbis}/lib \
			--with-ogg-vorbisinc=${BUILDLINK_PREFIX.libvorbis}/include

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
