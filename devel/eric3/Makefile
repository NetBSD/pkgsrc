# $NetBSD: Makefile,v 1.27 2014/05/09 07:36:59 wiz Exp $

DISTNAME=	eric-3.8.1
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=eric-ide/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.die-offenbachs.de/detlev/eric.html
COMMENT=	Python IDE

DEPENDS+=	${PYPKGPREFIX}-qt3-modules>=3.11:../../x11/py-qt3-modules
DEPENDS+=	${PYPKGPREFIX}-qt3-qscintilla>=3.11:../../x11/py-qt3-qscintilla
DEPENDS+=	${PYPKGPREFIX}-xml>=0.8.4:../../textproc/py-xml

NO_BUILD=		yes
USE_LANGUAGES=

PY_PATCHPLIST=		yes

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-xml, py-qt3-modules

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	-b ${PREFIX:Q}/bin
CONFIGURE_ARGS+=	-d ${PREFIX:Q}/${PYSITELIB:Q}
.if ${_USE_DESTDIR} != "no"
CONFIGURE_ARGS+=	-i ${DESTDIR:Q}
.endif

do-install:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${PYTHONBIN} install.py ${CONFIGURE_ARGS})
	(cd ${DESTDIR}${PREFIX}/${PYSITELIB} && \
		${PYTHONBIN} -c "import py_compile; py_compile.compile('sitecustomize.py')")

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
