# $NetBSD: Makefile,v 1.2 2017/07/05 08:46:26 nros Exp $

DISTNAME=	FreeImage3170
PKGNAME=	freeimageplus-3.17.0
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

INSTALLATION_DIRS+= include lib

PLIST_SUBST+=	PKGVERSION_NOREV=${PKGVERSION_NOREV}

NOT_FOR_PLATFORM=Darwin-*-*

.include "../../mk/bsd.pkg.mk"
