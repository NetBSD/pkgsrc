# $NetBSD: Makefile,v 1.7 2024/01/02 08:43:10 wiz Exp $

DISTNAME=	SCons-4.6.0.post1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=S/SCons/}
EXTRACT_USING=	bsdtar

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://www.scons.org/
COMMENT=	Python-based, open-source build system
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	script/scons
REPLACE_PYTHON+=	script/scons-configure-cache
REPLACE_PYTHON+=	script/sconsign

PYTHON_VERSIONS_INCOMPATIBLE=	27

# XXX: not sure why this is needed exactly
# but -Wl,-rpath is filtered out by buildlink from the c++ command line
SUBST_CLASSES+=		rflag
SUBST_STAGE.rflag=	pre-configure
SUBST_FILES.rflag=	SCons/Tool/gnulink.py
SUBST_SED.rflag=	-e 's|-Wl,-rpath=|${COMPILER_RPATH_FLAG}|g'

INSTALLATION_DIRS=	${PKGMANDIR}/man1

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} scons scons-${PYVERSSUFFIX}
	cd ${DESTDIR}${PREFIX}/bin && ${MV} scons-configure-cache scons-configure-cache-${PYVERSSUFFIX}
	cd ${DESTDIR}${PREFIX}/bin && ${MV} sconsign sconsign-${PYVERSSUFFIX}
	cd ${DESTDIR}${PREFIX} && ${MV} scons.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/scons-${PYVERSSUFFIX}.1
	cd ${DESTDIR}${PREFIX} && ${MV} scons-time.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/scons-time-${PYVERSSUFFIX}.1
	cd ${DESTDIR}${PREFIX} && ${MV} sconsign.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/sconsign-${PYVERSSUFFIX}.1

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
