# $NetBSD: Makefile,v 1.45 2026/08/28 18:57:15 ryoon Exp $

DISTNAME=	libbluray-1.5.0
CATEGORIES=	multimedia
MASTER_SITES=	https://download.videolan.org/pub/videolan/libbluray/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.videolan.org/developers/libbluray.html
COMMENT=	Library for Blu-Ray Discs playback for media players
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=		pkg-config
MESON_ARGS+=		-Dbdj_jar=disabled
PKGCONFIG_OVERRIDE+=	output/meson-private/libbluray.pc

# provide jni_md.h for other architectures
post-extract:
	${LN} -s ${WRKSRC}/jni/linux/jni_md.h ${WRKSRC}/jni/jni_md.h

.include "../../devel/meson/build.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
