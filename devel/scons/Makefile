# $NetBSD: Makefile,v 1.59 2023/08/14 05:24:16 wiz Exp $

DISTNAME=	scons-3.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/scons/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://www.scons.org/
COMMENT=	Python-based, open-source build system (old version 3)
LICENSE=	mit

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED=	27

USE_PKG_RESOURCES=	yes

REPLACE_PYTHON+=	script/scons
REPLACE_PYTHON+=	script/scons-configure-cache
REPLACE_PYTHON+=	script/scons-time
REPLACE_PYTHON+=	script/sconsign

SUBST_CLASSES+=		rflag
SUBST_STAGE.rflag=	pre-configure
SUBST_FILES.rflag=	engine/SCons/Tool/gnulink.py
SUBST_SED.rflag=	-e 's|-Wl,-rpath=|${COMPILER_RPATH_FLAG}|g'

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
