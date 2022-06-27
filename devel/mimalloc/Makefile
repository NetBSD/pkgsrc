# $NetBSD: Makefile,v 1.7 2022/06/27 15:29:14 fcambus Exp $

DISTNAME=	mimalloc-2.0.6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=microsoft/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/microsoft/mimalloc/
COMMENT=	General-purpose allocator with excellent performance characteristics
LICENSE=	mit

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DMI_INSTALL_TOPLEVEL=ON

INSTALLATION_DIRS+=	lib/cmake/mimalloc

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/lib/mimalloc.o

.include "../../mk/bsd.pkg.mk"
