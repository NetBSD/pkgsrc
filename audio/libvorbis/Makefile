# $NetBSD: Makefile,v 1.27 2003/12/08 14:39:39 wiz Exp $

DISTNAME=	libvorbis-1.0.1
CATEGORIES=	devel audio
MASTER_SITES=	http://www.vorbis.com/files/1.0.1/unix/

MAINTAINER=	lukem@NetBSD.org
HOMEPAGE=	http://www.xiph.org/ogg/vorbis/
COMMENT=	Library for the Ogg Vorbis audio encoding format

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

GCC_REQD=		2.95.3

PKGCONFIG_OVERRIDE+=	${WRKSRC}/vorbis.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/vorbisenc.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/vorbisfile.pc.in

.include "../../audio/libogg/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
