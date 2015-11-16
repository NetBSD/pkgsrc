# $NetBSD: Makefile,v 1.1 2015/11/16 01:31:10 khorben Exp $

.include "../../devel/radare2/Makefile.common"

DISTNAME=	radare2-bindings-${RADARE2_VERSION}
PKGNAME=	${PYPKGPREFIX}-radare2-${RADARE2_VERSION}
CATEGORIES=	devel
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	khorben@defora.org
COMMENT=	Reverse engineering framework (Python bindings)
LICENSE=	gnu-gpl-v3

USE_LANGUAGES+=	c c++
USE_TOOLS+=	gmake
USE_TOOLS+=	pkg-config

BUILD_DEPENDS+=	radare2-valabind-[0-9]*:../../devel/radare2-valabind
BUILD_DEPENDS+=	swig2-[0-9]*:../../devel/swig2

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable=python

MAKE_ENV+=	PYTHON_CONFIG=${PYTHONCONFIG}
MAKE_ENV+=	SWIG=swig2.0

BUILD_DIRS=	python

.include "../../devel/radare2/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
