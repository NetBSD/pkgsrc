# $NetBSD: Makefile,v 1.2 2021/07/28 14:23:13 fcambus Exp $

DISTNAME=	mimalloc-2.0.2
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=microsoft/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	fcambus@NetBSD.org
HOMEPAGE=	https://github.com/microsoft/mimalloc/
COMMENT=	General-purpose allocator with excellent performance characteristics
LICENSE=	mit

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DMI_INSTALL_TOPLEVEL=ON

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/lib/mimalloc-2.0/mimalloc.o

.include "../../mk/bsd.pkg.mk"
