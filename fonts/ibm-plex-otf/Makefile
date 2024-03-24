# $NetBSD: Makefile,v 1.9 2024/03/24 16:02:32 nikita Exp $

PKGNAME=	ibm-plex-otf-6.4.0
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
