# $NetBSD: Makefile,v 1.44 2023/02/25 17:55:24 ryoon Exp $

DISTNAME=	mosml-ver-2.10.1
PKGNAME=	${DISTNAME:S/mosml-ver-/moscow_ml-/}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=kfl/}
GITHUB_PROJECT=	mosml
GITHUB_TAG=	ver-${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mosml.org/
COMMENT=	Moscow ML, a version of Standard ML

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_TOOLS+=	gmake perl

BUILD_DIRS=	src
BUILD_TARGET=	world

MAKE_FLAGS+=	PREFIX=${PREFIX}

LDFLAGS=		${COMPILER_RPATH_FLAG}${PREFIX}/lib
BUILD_MAKE_FLAGS+=	GMPLIBDIR=${BUILDLINK_DIR}/lib

.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
