# $NetBSD: Makefile,v 1.43 2019/01/02 17:18:47 tnn Exp $

DISTNAME=	scons-3.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=scons/}
MASTER_SITES+=	${MASTER_SITE_PYPI:=S/SCons/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.scons.org/
COMMENT=	Python-based, open-source build system
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

REPLACE_PYTHON+=	script/scons
REPLACE_PYTHON+=	script/scons-configure-cache
REPLACE_PYTHON+=	script/scons-time
REPLACE_PYTHON+=	script/sconsign

SUBST_CLASSES+=		rflag
SUBST_STAGE.rflag=	pre-configure
SUBST_FILES.rflag=	engine/SCons/Tool/gnulink.py
SUBST_SED.rflag=	-e 's|-Wl,-rpath=|${COMPILER_RPATH_FLAG}|g'

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
