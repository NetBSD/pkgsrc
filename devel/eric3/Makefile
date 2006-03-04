# $NetBSD: Makefile,v 1.15 2006/03/04 21:29:14 jlam Exp $
#

DISTNAME=	eric-3.8.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=eric-ide/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.die-offenbachs.de/detlev/eric3.html
COMMENT=	Python IDE

DEPENDS+=	${PYPKGPREFIX}-qt3-modules>=3.11:../../x11/py-qt3-modules
DEPENDS+=	${PYPKGPREFIX}-qt3-qscintilla>=3.11:../../x11/py-qt3-qscintilla

NO_BUILD=		yes
USE_LANGUAGES=

PY_PATCHPLIST=		yes
PYTHON_VERSIONS_ACCEPTED=	24 23 22

CONFIGURE_ARGS+=	-b ${PREFIX:Q}/bin
CONFIGURE_ARGS+=	-d ${PREFIX:Q}/${PYSITELIB:Q}

do-install:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${PYTHONBIN} install.py ${CONFIGURE_ARGS})

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
