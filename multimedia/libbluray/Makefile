# $NetBSD: Makefile,v 1.13 2019/06/10 14:40:52 adam Exp $

DISTNAME=	libbluray-1.1.2
CATEGORIES=	multimedia
MASTER_SITES=	http://download.videolan.org/pub/videolan/libbluray/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.videolan.org/developers/libbluray.html
COMMENT=	Library for Blu-Ray Discs playback for media players
LICENSE=	gnu-lgpl-v2.1

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-bdjava-jar
CONFIGURE_ARGS+=	--disable-optimizations
PKGCONFIG_OVERRIDE+=	src/libbluray.pc.in

# provide jni_md.h for other architectures
post-extract:
	ln -s ${WRKSRC}/jni/linux/jni_md.h ${WRKSRC}/jni/jni_md.h

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
