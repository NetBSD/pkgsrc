# $NetBSD: Makefile,v 1.9 2023/01/24 18:36:24 wiz Exp $

DISTNAME=	yajl-2.1.0
CATEGORIES=	devel textproc
MASTER_SITES=	# http://nodeload.github.com/lloyd/yajl/tarball/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lloyd.github.com/yajl/
COMMENT=	Small JSON library written in ANSI C
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/lloyd-yajl-66cb08c

USE_LANGUAGES=		c
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE=	src/yajl.pc.cmake

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
