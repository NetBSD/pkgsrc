# $NetBSD: Makefile,v 1.3 2026/02/13 10:42:02 wiz Exp $

DISTNAME=	vatomic-2.4.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=open-s4c/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	db7@sdf.org
HOMEPAGE=	https://github.com/open-s4c/vatomic/
COMMENT=	Formally verified atomic operations
LICENSE=	mit

USE_LANGUAGES=		c c++
CMAKE_CONFIGURE_ARGS=	-DVATOMIC_DEV=off

# vatomic memory model is only safe for the following architectures
ONLY_FOR_PLATFORM+=	*-*-x86_64
ONLY_FOR_PLATFORM+=	*-*-riscv64
ONLY_FOR_PLATFORM+=	*-*-aarch64
ONLY_FOR_PLATFORM+=	*-*-arm

BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
