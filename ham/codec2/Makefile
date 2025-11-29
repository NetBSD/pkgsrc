# $NetBSD: Makefile,v 1.10 2025/11/29 07:15:35 wiz Exp $

DISTNAME=	codec2-1.2.0
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_GITHUB:=drowe67/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	dbj@NetBSD.org
HOMEPAGE=	https://www.rowetel.com/?page_id=452
COMMENT=	Speech codec for between 700 and 3200 bit/s
LICENSE=	gnu-lgpl-v2.1

USE_CC_FEATURES=	c99
USE_LANGUAGES=		c

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Release

.include "../../devel/cmake/build.mk"
# XXX this creates a circular dependency between
# lpcnetfreedv and codec2 that requires bootstrapping
# and causes problems with pkg tools once created.
#CMAKE_CONFIGURE_ARGS+=	-DLPCNET=ON
#.include "../../ham/lpcnetfreedv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
