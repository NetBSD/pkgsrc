# $NetBSD: Makefile,v 1.11 2025/02/09 09:28:07 wiz Exp $

DISTNAME=	yajl-2.1.0
CATEGORIES=	devel textproc
#MASTER_SITES=	${MASTER_SITE_GITHUB:=lloyd/}
#GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lloyd.github.io/yajl/
COMMENT=	Small JSON library written in ANSI C
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/lloyd-yajl-66cb08c

USE_LANGUAGES=		c
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE=	src/yajl.pc.cmake

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
