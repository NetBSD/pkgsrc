# $NetBSD: Makefile,v 1.1 2024/04/21 06:35:01 ryoon Exp $

DISTNAME=	morisawa-biz-ud-gothic-fonts
PKGNAME=	biz-ud-gothic-ttf-${GITHUB_RELEASE:S,^v,,}
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=googlefonts/}
GITHUB_PROJECT=	morisawa-biz-ud-gothic
GITHUB_RELEASE=	v1.051
DIST_SUBDIR=	${GITHUB_PROJECT}-${GITHUB_RELEASE}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/googlefonts/morisawa-biz-ud-gothic/
COMMENT=	Morisawa BIZ UDGothic font
LICENSE=	ofl-v1.1

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/fonts/ttf

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
