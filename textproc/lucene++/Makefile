# $NetBSD: Makefile,v 1.22 2023/12/29 18:24:59 adam Exp $

DISTNAME=	LucenePlusPlus-rel_3.0.7
PKGNAME=	${DISTNAME:S/LucenePlusPlus-rel_/lucene++-/}
PKGREVISION=	20
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=luceneplusplus/LucenePlusPlus/archive/rel_${PKGVERSION_NOREV}/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/luceneplusplus/LucenePlusPlus/
COMMENT=	C++ port of Lucene text search library
LICENSE=	gnu-lgpl-v3 OR apache-2.0

USE_LANGUAGES=	c c++
USE_CMAKE=	yes

CMAKE_ARGS+=	-DENABLE_DEMO=no

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
