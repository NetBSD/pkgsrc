# $NetBSD: Makefile,v 1.20 2003/03/25 09:14:06 wiz Exp $
#

DISTNAME=	sox-12.17.4
CATEGORIES=	audio
MASTER_SITES=	http://prdownloads.sourceforge.net/sox/ \
		${MASTER_SITE_SOURCEFORGE:=sox/} \
		http://www.cnpbagwell.com/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://sox.sourceforge.net/
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
.include "../../audio/mad/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
