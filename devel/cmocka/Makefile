# $NetBSD: Makefile,v 1.14 2025/07/23 08:09:09 pin Exp $

DISTNAME=	cmocka-1.1.8
CATEGORIES=	devel
MASTER_SITES=	https://cmocka.org/files/${PKGVERSION_NOREV:R}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cmocka.org/
COMMENT=	Unit testing framework for C supporting mock objects
LICENSE=	apache-2.0

# GCC 4.3/4.4 provides wrong warnings:
# cmocka.c:3281: error: 'setup_name' may be used uninitialized in this function
CMAKE_CONFIGURE_ARGS+=	-DWITH_WERROR_UNINITIALIZED_FLAG=0

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
