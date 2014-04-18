# $NetBSD: Makefile,v 1.6 2014/04/18 12:16:57 wiz Exp $

DISTNAME=	yajl-2.1.0
CATEGORIES=	devel textproc
MASTER_SITES=	# http://nodeload.github.com/lloyd/yajl/tarball/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lloyd.github.com/yajl/
COMMENT=	Small JSON library written in ANSI C
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/lloyd-yajl-66cb08c

USE_LANGUAGES=	c
USE_LIBTOOL=	yes
USE_CMAKE=	yes
PKGCONFIG_OVERRIDE=	src/yajl.pc.cmake

.include "../../mk/bsd.pkg.mk"
