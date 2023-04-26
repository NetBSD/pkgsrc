# $NetBSD: Makefile,v 1.10 2023/04/26 18:16:43 wiz Exp $

DISTNAME=	yajl-2.1.0
CATEGORIES=	devel textproc
MASTER_SITES=	# ${MASTER_SITE_GITHUB:=lloyd/}
#GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lloyd.github.io/yajl/
COMMENT=	Small JSON library written in ANSI C
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/lloyd-yajl-66cb08c

USE_LANGUAGES=		c
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE=	src/yajl.pc.cmake

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
