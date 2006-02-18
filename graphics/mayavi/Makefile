# $NetBSD: Makefile,v 1.9 2006/02/18 17:16:01 wiz Exp $
#

DISTNAME=		MayaVi-1.5
PKGREVISION=		2
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=mayavi/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://mayavi.sourceforge.net/
COMMENT=		Scientific data visualizer written in Python

DEPENDS+=		vtk-python>=4.2:../../graphics/vtk-python

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

# vtk-python is for 23 only
PYTHON_VERSIONS_ACCEPTED=	23

.include "../../lang/python/extension.mk"
.include "../../x11/py-Tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
