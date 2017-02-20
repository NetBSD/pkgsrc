# $NetBSD: Makefile,v 1.3 2017/02/20 08:00:42 snj Exp $

DISTNAME=	FreeImage3170
PKGNAME=	freeimage-3.17.0
PKGREVISION=	1
CATEGORIES=	devel graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=freeimage/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://freeimage.sf.net/
COMMENT=	Library for supporting PNG, BMP, JPEG, and TIFF

USE_LANGUAGES+= c c++
USE_TOOLS+=	gmake

WRKSRC=		${WRKDIR}/FreeImage

INSTALLATION_DIRS+= include lib

PLIST_SUBST+=	PKGVERSION_NOREV=${PKGVERSION_NOREV}

NOT_FOR_PLATFORM=Darwin-*-*

.include "../../mk/bsd.pkg.mk"
