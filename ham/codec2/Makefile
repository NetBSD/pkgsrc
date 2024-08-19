# $NetBSD: Makefile,v 1.7 2024/08/19 17:19:32 gdt Exp $
#

# https://github.com/drowe67/codec2/archive/v0.9.2.tar.gz
DISTNAME=	codec2-0.9.2
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_GITHUB:=drowe67/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	dbj@NetBSD.org
HOMEPAGE=	https://rowetel.com/codec2.html
COMMENT=	Speech codec for between 700 and 3200 bit/s

LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	c

.include "../../devel/cmake/build.mk"
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Release

# XXX this creates a circular dependency between
# lpcnetfreedv and codec2 that requires bootstrapping
# and causes problems with pkg tools once created.
#CMAKE_ARGS+=	-DLPCNET=ON
#.include "../../ham/lpcnetfreedv/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
