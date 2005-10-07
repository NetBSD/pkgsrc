# $NetBSD: Makefile,v 1.1 2005/10/07 19:41:07 perry Exp $

DISTNAME=	pymol-0_98-src
PKGNAME=	pymol-0.98
WRKSRC=		${WRKDIR}/${PKGNAME}
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pymol/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	perry@NetBSD.org
HOMEPAGE=	http://pymol.sourceforge.net/
COMMENT=	Molecular Visualization System

PYTHON_VERSIONS_ACCEPTED= 23 24

PYDISTUTILSPKG=	yes
PYBINMODULE=	yes
PYSETUP=	setup.py

post-install:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHONBIN} setup2.py)
	${INSTALL_SCRIPT} ${WRKSRC}/pymol.com ${PREFIX}/bin/pymol

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/glut/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../math/py-Numeric/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../x11/py-Tk/buildlink3.mk"
.include "../../x11/py-Pmw/buildlink3.mk"

# Note that the website claims this package needs "freeglut", which
# would mean:
#  .include "../../graphics/freeglut/buildlink3.mk"
# However, the package seems to link with "glut" and not with "freeglut",
# and no other pkgsrc packages seem to use freeglut.

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
