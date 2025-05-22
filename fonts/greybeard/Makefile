# $NetBSD: Makefile,v 1.1 2025/05/22 17:14:14 vins Exp $

DISTNAME=	greybeard-1.0.0
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=flowchartsman/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://github.com/flowchartsman/greybeard/
COMMENT=	Chunky monospaced bitmap font
LICENSE=	mit

USE_TOOLS=	bdftopcf gmake gzip perl:build

USE_LANGUAGES=	# none

FONTDIR=	share/fonts/X11/PCF

REQD_DIRS=		${FONTDIR}
FONTS_DIRS.x11=		${FONTDIR}

NO_CONFIGURE=	yes

MAKE_FLAGS+=	PERL=${PERL5:Q} \
		PREFIX=${PREFIX:Q} \
		PCFDIR=${PREFIX}/${FONTDIR}

BUILD_DIRS=	build

.include "../../mk/bsd.pkg.mk"
