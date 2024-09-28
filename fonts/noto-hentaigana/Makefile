# $NetBSD: Makefile,v 1.2 2024/09/28 09:28:05 ryoon Exp $

DISTNAME=	NotoSerifHentaigana-v1.000
PKGNAME=	${DISTNAME:tl:S,notoserif,noto-,:S,-v,-,}
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=notofonts/}
GITHUB_PROJECT=	hentaigana
GITHUB_RELEASE=	${DISTNAME}
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/notofonts/hentaigana/
COMMENT=	Noto Hentaigana font
LICENSE=	ofl-v1.1

WRKSRC=		${WRKDIR}/NotoSerifHentaigana/googlefonts/variable
NO_CONFIGURE=	yes
NO_BUILD=	yes

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
