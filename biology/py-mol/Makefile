# $NetBSD: Makefile,v 1.23 2014/05/09 07:36:55 wiz Exp $

DISTNAME=	pymol-v1.5.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pymol-v/mol-/}
EGG_NAME=	pymol-1.5.0.1
PKGREVISION=	3
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pymol/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.pymol.org/
COMMENT=	Molecular Visualization System

DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy

PYTHON_VERSIONED_DEPENDENCIES=	Pmw
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 1.5.0.1

WRKSRC=		${WRKDIR}/pymol

USE_TOOLS+=	csh:run

CONFLICTS=		pymol-[0-9]*

USE_LANGUAGES=	c c++

REPLACE_CSH=	test/vdiff
REPLACE_PYTHON=	test/cyg test/run test/show test/win.py modules/pmg_tk/startup/apbs_tools.py

# not used
CHECK_PORTABILITY_SKIP+=	setup/*

INSTALLATION_DIRS=	bin

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

# Gross hack
PYSETUPBUILDTARGET=	install ${_PYSETUPINSTALLARGS}

post-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} PYTHONPATH=${DESTDIR}${PREFIX}/${PYSITELIB} ${PYTHONBIN} setup2.py install ${_PYSETUPINSTALLARGS}
	${INSTALL_SCRIPT} ${WRKSRC}/pymol ${DESTDIR}${PREFIX}/bin/pymol${PYVERSSUFFIX}

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/glut/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
