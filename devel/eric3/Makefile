# $NetBSD: Makefile,v 1.4 2004/05/09 17:06:56 recht Exp $
#

DISTNAME=	eric-3.4.2
CATEGORIES=	devel
MASTER_SITES=	http://www.die-offenbachs.de/detlev/files/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.die-offenbachs.de/detlev/eric3.html
COMMENT=	Python IDE

DEPENDS=	${PYPKGPREFIX}-qt3-modules>=3.11:../../x11/py-qt3-modules
DEPENDS+=	${PYPKGPREFIX}-qt3-qscintilla>=3.11:../../x11/py-qt3-qscintilla

USE_BUILDLINK3=		yes
NO_BUILD=		yes
USE_LANGUAGES=

PY_PATCHPLIST=		yes
PYTHON_VERSIONS_ACCEPTED=	23pth 22pth

CONFIGURE_ARGS=	-b ${PREFIX}/bin -d ${PREFIX}/${PYSITELIB}

do-install:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${PYTHONBIN} install.py ${CONFIGURE_ARGS})

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
