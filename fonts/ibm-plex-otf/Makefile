# $NetBSD: Makefile,v 1.5 2020/11/06 18:04:25 maya Exp $

PKGNAME=	ibm-plex-otf-4.0.2
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
