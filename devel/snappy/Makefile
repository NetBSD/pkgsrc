# $NetBSD: Makefile,v 1.10 2017/07/14 17:27:40 adam Exp $

DISTNAME=	snappy-1.1.6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://google.github.io/snappy/
COMMENT=	General purpose data compression library
LICENSE=	apache-2.0

GITHUB_TAG=	${PKGVERSION_NOREV}

USE_CMAKE=		yes
USE_LANGUAGES+=		c c++

.include "../../archivers/lzo/buildlink3.mk"
.include "../../devel/googletest/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
