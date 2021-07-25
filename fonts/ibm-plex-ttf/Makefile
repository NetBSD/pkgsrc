# $NetBSD: Makefile,v 1.7 2021/07/25 20:13:01 fcambus Exp $

PKGNAME=	ibm-plex-ttf-5.2.1
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
