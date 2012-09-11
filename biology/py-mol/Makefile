# $NetBSD: Makefile,v 1.12 2012/09/11 20:32:14 asau Exp $

DISTNAME=	pymol-v1.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pymol-v/mol-/}
EGG_NAME=	pymol-1.4.0
PKGREVISION=	2
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pymol/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.pymol.org/
COMMENT=	Molecular Visualization System

USE_TOOLS+=	csh:run

DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-Pmw-[0-9]*:../../x11/py-Pmw

WRKSRC=		${WRKDIR}/pymol

CONFLICTS=	pymol-[0-9]*

USE_LANGUAGES=	c c++

REPLACE_CSH=	test/vdiff
REPLACE_PYTHON=	test/cyg test/run test/show test/win.py

# not used
CHECK_PORTABILITY_SKIP+=	setup/*

INSTALLATION_DIRS=	bin

post-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} PYTHONPATH=${DESTDIR}${PREFIX}/${PYSITELIB} ${PYTHONBIN} setup2.py install
	${INSTALL_SCRIPT} ${WRKSRC}/pymol ${DESTDIR}${PREFIX}/bin/pymol

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/glut/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
