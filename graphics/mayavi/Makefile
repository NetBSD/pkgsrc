# $NetBSD: Makefile,v 1.3 2005/01/23 20:41:46 recht Exp $
#

DISTNAME=		MayaVi-1.3
PKGREVISION=	1
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=mayavi/}

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://mayavi.sourceforge.net/
COMMENT=		Scientific data visualizer written in Python

DEPENDS=	vtk-python>=4.2:../../graphics/vtk-python

USE_BUILDLINK3=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

# vtk-python is for 23 only
PYTHON_VERSIONS_ACCEPTED=	23

.include "../../lang/python/extension.mk"
.include "../../x11/py-Tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
