# $NetBSD: Makefile,v 1.7 2007/02/15 22:37:05 perry Exp $

DISTNAME=	pymol-0_98-src
PKGNAME=	pymol-0.98
PKGREVISION=	3
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pymol/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pymol.sourceforge.net/
COMMENT=	Molecular Visualization System

PYTHON_VERSIONS_INCOMPATIBLE=	15 20 21 22

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
PYDISTUTILSPKG=	yes
PYBINMODULE=	yes
PYSETUP=	setup.py

post-install:
	cd ${WRKSRC} && env ${MAKE_ENV} ${PYTHONBIN} setup2.py
	${INSTALL_SCRIPT} ${WRKSRC}/pymol.com ${PREFIX}/bin/pymol

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
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
