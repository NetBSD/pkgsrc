# $NetBSD: Makefile,v 1.3 2017/08/11 15:26:21 nros Exp $

DISTNAME=	FreeImage3170
PKGNAME=	freeimageplus-3.17.0
PKGREVISION=	1
CATEGORIES=	devel graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=freeimage/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://freeimage.sf.net/
COMMENT=	Library for supporting PNG, BMP, JPEG, and TIFF - C++ Wrapper
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3 OR mpl-1.0

USE_LANGUAGES+= c c++
USE_TOOLS+=	gmake
MAKE_FILE=	Makefile.fip

DEPENDS+=	freeimage>=3.17.0:../../graphics/freeimage

PATCHDIR=	${.CURDIR}/../../graphics/freeimage/patches
DISTINFO_FILE=	${.CURDIR}/../../graphics/freeimage/distinfo

WRKSRC=		${WRKDIR}/FreeImage

INSTALLATION_DIRS+= include lib share/doc/${PKGBASE}

post-install:
	${INSTALL_DATA} ${WRKSRC}/Source/LibJXR/LICENCE \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/LICENSE.LibJXR
	${INSTALL_DATA} ${WRKSRC}/Source/LibOpenJPEG/LICENSE \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/LICENSE.OpenJPEG
	${HEAD} -n 31 ${WRKSRC}/Source/LibRawLite/internal/libraw_x3f.cpp \
		> ${WRKDIR}/LICENSE.x3f
	${HEAD} -n 33 ${WRKSRC}/Source/LibRawLite/internal/dcb_demosaicing.c \
		> ${WRKDIR}/LICENSE.dcb
	${HEAD} -n 25 ${WRKSRC}/Source/LibTIFF4/tif_open.c \
		> ${WRKDIR}/LICENSE.LibTIFF4
	${INSTALL_DATA} ${WRKDIR}/LICENSE.* \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/Source/LibWebP/COPYING \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/LICENSE.LibWebP
	${INSTALL_DATA} ${WRKSRC}/Source/OpenEXR/Copyrights/openexr/LICENSE \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/LICENSE.OpenEXR

PLIST_SUBST+=	PKGVERSION_NOREV=${PKGVERSION_NOREV}

NOT_FOR_PLATFORM=Darwin-*-*

.include "../../mk/bsd.pkg.mk"
