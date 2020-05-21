# $NetBSD: Makefile,v 1.13 2020/05/21 20:53:42 ryoon Exp $

DISTNAME=	FreeImage3180
PKGNAME=	freeimage-3.18.0
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=freeimage/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://freeimage.sf.net/
COMMENT=	Library for supporting PNG, BMP, JPEG, and TIFF
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3 OR mpl-1.0

USE_LANGUAGES+=	c c++11
USE_TOOLS+=	gmake pkg-config

WRKSRC=		${WRKDIR}/FreeImage

MAKE_FILE=	Makefile.gnu

INSTALLATION_DIRS+=	include lib share/doc/${PKGBASE}

pre-configure:
	# G3 and JPEGTransform can't be built,
	# due to using private headers in bundled libs
	cd ${WRKSRC} && ${RM} -r Source/Lib* \
	    Source/ZLib \
	    Source/OpenEXR \
	    Source/FreeImage/PluginG3.cpp \
	    Source/FreeImage/PluginJXR.cpp \
	    Source/FreeImageToolkit/JPEGTransform.cpp
	cd ${WRKSRC} && ${SH} gensrclist.sh
	cd ${WRKSRC} && ${SH} genfipsrclist.sh
	${SED} \
	    -e 's| \./Source/FreeImage/PluginG3\.cpp||g' \
	    -e 's| \./Source/FreeImage/PluginJXR\.cpp||g' \
	    -e 's| \./Source/FreeImageToolkit/JPEGTransform\.cpp||g' \
	    ${WRKSRC}/Makefile.srcs > ${WRKSRC}/Makefile.srcs.new
	${MV} ${WRKSRC}/Makefile.srcs.new ${WRKSRC}/Makefile.srcs

PLIST_SUBST+=	PKGVERSION_NOREV=${PKGVERSION_NOREV}

NOT_FOR_PLATFORM=	Darwin-*-*

.include "../../graphics/libraw/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/openjpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
