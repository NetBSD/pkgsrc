# $NetBSD: Makefile,v 1.5 2022/04/12 22:36:02 tnn Exp $

DISTNAME=	libcbor-0.9.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=PJK/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@pkgsrc.org
HOMEPAGE=	https://github.com/PJK/libcbor
COMMENT=	Parsing and generate schema-less binary data format
LICENSE=	mit

USE_LANGUAGES+=	c c++
USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON

CHECK_PORTABILITY_SKIP+=	misc/hooks/*

.include "../../mk/bsd.pkg.mk"
