# $NetBSD: Makefile,v 1.10 2024/03/24 16:03:24 nikita Exp $

PKGNAME=	ibm-plex-ttf-6.4.0
GITHUB_PROJECT=	plex
DISTNAME=	TrueType
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=IBM/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.zip
DIST_SUBDIR=	${PKGNAME_NOREV}

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://github.com/IBM/plex/
COMMENT=	IBM plex typeface (TrueType)
LICENSE=	ofl-v1.1

USE_LANGUAGES=	# none

NO_CONFIGURE=	yes
NO_BUILD=	yes

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
