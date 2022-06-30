# $NetBSD: Makefile,v 1.7 2022/06/30 11:18:46 nia Exp $

DISTNAME=	pdf-redact-tools-0.1
PKGREVISION=	4
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GITHUB:=firstlook/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	https://firstlook.org/code/project/pdf-redact-tools/
COMMENT=	Strip metadata from documents before publishing
LICENSE=	gnu-gpl-v3

DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick
DEPENDS+=	p5-Image-ExifTool-[0-9]*:../../graphics/p5-Image-ExifTool

USE_LANGUAGES=	# none

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
