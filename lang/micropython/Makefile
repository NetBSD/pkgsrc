# $NetBSD: Makefile,v 1.2 2016/03/22 19:01:17 joerg Exp $

DISTNAME=	micropython-1.5.2
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=micropython/}
GITHUB_TAG=	v1.5.2

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	https://micropython.org/
COMMENT=	Embedded version of python
LICENSE=	mit

DIST_SUBDIR=	${PKGNAME_NOREV}
BUILD_DIRS=	unix

USE_TOOLS+=	gmake pkg-config

AUTO_MKDIRS=	yes

MAKE_FLAGS+=	PYTHON=${PYTHONBIN}

REPLACE_PYTHON+=	tools/make-frozen.py

PYTHON_FOR_BUILD_ONLY=	yes

.include "../../devel/libffi/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
