# $NetBSD: Makefile,v 1.57 2023/07/20 13:16:14 gdt Exp $

DISTNAME=	scons-3.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/scons/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://www.scons.org/
COMMENT=	Python-based, open-source build system (old version 3)
LICENSE=	mit

USE_LANGUAGES=	# none

CONFLICTS=	py[0-9]*-scons-3[0-9\.]*

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
