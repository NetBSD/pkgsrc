# $NetBSD: Makefile,v 1.2 2003/08/25 17:31:43 recht Exp $
#

DISTNAME=		eric-3.2
CATEGORIES=		devel
MASTER_SITES=		http://www.die-offenbachs.de/detlev/files/

MAINTAINER=		tech-pkg@netbsd.org
HOMEPAGE=		http://www.die-offenbachs.de/detlev/eric3.html
COMMENT=		Python IDE

USE_BUILDLINK2=		yes
NO_BUILD=		yes
PY_PATCHPLIST=		yes
PYTHON_VERSIONS_ACCEPTED=	22pth 23pth

do-install:
	(cd ${WRKSRC} && ${PYTHONBIN} install.py -b ${PREFIX}/bin)

.include "../../lang/python/extension.mk"
.include "../../x11/py-qt3-base/buildlink2.mk"
.include "../../x11/py-qt3-modules/buildlink2.mk"
.include "../../x11/py-qt3-qscintilla/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
