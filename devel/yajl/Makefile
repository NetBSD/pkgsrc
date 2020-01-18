# $NetBSD: Makefile,v 1.8 2020/01/18 23:30:44 rillig Exp $

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
USE_CMAKE=		yes
PKGCONFIG_OVERRIDE=	src/yajl.pc.cmake

.include "../../mk/bsd.pkg.mk"
