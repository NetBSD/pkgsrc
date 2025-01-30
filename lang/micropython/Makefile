# $NetBSD: Makefile,v 1.11 2025/01/30 12:01:27 wiz Exp $

DISTNAME=	micropython-1.24.1
CATEGORIES=	lang
MASTER_SITES=	http://micropython.org/resources/source/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	https://micropython.org/
COMMENT=	Embedded version of Python 3
LICENSE=	mit

BUILD_DIRS=	mpy-cross ports/unix
TEST_DIRS=	ports/unix

# as of 1.24.1
# 899 tests performed (28325 individual testcases)
# 656 tests passed
# 79 tests skipped
TEST_TARGET=	test

USE_TOOLS+=	gmake pkg-config

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ports/unix/build-standard/micropython ${DESTDIR}${PREFIX}/bin

.include "../../devel/libffi/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
