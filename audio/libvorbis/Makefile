# $NetBSD: Makefile,v 1.31 2004/02/14 18:48:49 jlam Exp $

DISTNAME=	libvorbis-1.0.1
CATEGORIES=	devel audio
MASTER_SITES=	http://www.vorbis.com/files/1.0.1/unix/

MAINTAINER=	lukem@NetBSD.org
HOMEPAGE=	http://www.xiph.org/ogg/vorbis/
COMMENT=	Library for the Ogg Vorbis audio encoding format

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

GCC_REQD+=		2.95.3

PKGCONFIG_OVERRIDE+=	vorbis.pc.in
PKGCONFIG_OVERRIDE+=	vorbisenc.pc.in
PKGCONFIG_OVERRIDE+=	vorbisfile.pc.in

.include "../../audio/libogg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
