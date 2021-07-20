# $NetBSD: Makefile,v 1.16 2021/07/20 15:35:23 nonaka Exp $

DISTNAME=	Koruri-${KORURI_VERSION}
PKGNAME=	koruri-ttf-${KORURI_VERSION}
CATEGORIES=	fonts japanese
MASTER_SITES=	${MASTER_SITE_GITHUB:=Koruri/}
EXTRACT_SUFX=	.tar.xz
GITHUB_PROJECT=	Koruri
GITHUB_RELEASE=	${KORURI_VERSION}

MAINTAINER=	nonakap@gmail.com
HOMEPAGE=	https://koruri.github.io/
COMMENT=	Koruri Japanese TrueType fonts
LICENSE=	apache-2.0

KORURI_VERSION=	20210720

INSTALLATION_DIRS+=	share/doc/koruri-ttf

USE_LANGUAGES=	# none

WRKSRC=		${WRKDIR}

NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	cd ${WRKSRC} && ${INSTALL_DATA} LICENSE README.md README_EN.md ${DESTDIR}${PREFIX}/share/doc/koruri-ttf

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
