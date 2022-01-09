# $NetBSD: Makefile,v 1.53 2022/01/09 11:58:15 wiz Exp $

# 4.1.0 is broken, per reports on gpsd list.  Apparently 4.0.1 is ok.
DISTNAME=	scons-3.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/scons/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://www.scons.org/
COMMENT=	Python-based, open-source build system
LICENSE=	mit

USE_LANGUAGES=	# none

PYTHON_SELF_CONFLICT=	yes

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
