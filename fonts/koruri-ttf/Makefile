# $NetBSD: Makefile,v 1.15 2020/11/06 18:04:25 maya Exp $

DISTNAME=	Koruri-${KORURI_VERSION}
PKGNAME=	koruri-ttf-${KORURI_VERSION}
CATEGORIES=	fonts japanese
MASTER_SITES=	${MASTER_SITE_GITHUB:=Koruri/}
EXTRACT_SUFX=	.tar.xz
GITHUB_PROJECT=	Koruri
GITHUB_RELEASE=	Koruri-${KORURI_VERSION}

MAINTAINER=	nonakap@gmail.com
HOMEPAGE=	https://koruri.github.io/
COMMENT=	Koruri Japanese TrueType fonts
LICENSE=	apache-2.0

KORURI_VERSION=	20180915

USE_LANGUAGES=	# none

NO_CONFIGURE=	yes
NO_BUILD=	yes

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
