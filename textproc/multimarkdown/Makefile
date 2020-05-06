# $NetBSD: Makefile,v 1.8 2020/05/06 14:05:04 adam Exp $

DISTNAME=	multimarkdown-6.5.1
MASTER_SITES=	${MASTER_SITE_GITHUB:=fletcher/}
PKGREVISION=	2
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
