# $NetBSD: Makefile,v 1.12 2021/09/29 19:01:24 adam Exp $

DISTNAME=	multimarkdown-6.5.2
MASTER_SITES=	${MASTER_SITE_GITHUB:=fletcher/}
PKGREVISION=	3
CATEGORIES=	textproc
GITHUB_PROJECT=	MultiMarkdown-6

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://fletcherpenney.net/multimarkdown/
COMMENT=	MultiMarkdown (MMD) v6 written in C
LICENSE=	gnu-gpl-v3 OR mit

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${PKGVERSION_NOREV}

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-Wno-dev

.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
