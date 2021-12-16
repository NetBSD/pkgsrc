# $NetBSD: Makefile,v 1.7 2021/12/16 15:46:08 nikita Exp $

PKGNAME=	ibm-plex-otf-6.0.0
GITHUB_PROJECT=	plex
DISTNAME=	OpenType
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=IBM/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.zip
DIST_SUBDIR=	${PKGNAME_NOREV}

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://github.com/IBM/plex/
COMMENT=	IBM plex typeface (OpenType)
LICENSE=	ofl-v1.1

USE_LANGUAGES=	# none

NO_CONFIGURE=	yes
NO_BUILD=	yes

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
