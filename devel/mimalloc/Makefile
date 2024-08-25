# $NetBSD: Makefile,v 1.11 2024/08/25 06:18:36 wiz Exp $

DISTNAME=	mimalloc-2.0.9
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=microsoft/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/microsoft/mimalloc/
COMMENT=	General-purpose allocator with excellent performance characteristics
LICENSE=	mit

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DMI_INSTALL_TOPLEVEL=ON

# Requires stdatomic support.
USE_CC_FEATURES+=	c11

INSTALLATION_DIRS+=	lib/cmake/mimalloc

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/lib/mimalloc.o

.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
