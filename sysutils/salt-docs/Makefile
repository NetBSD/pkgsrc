# $NetBSD: Makefile,v 1.35 2024/01/22 16:35:25 adam Exp $

.include "../../sysutils/salt/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-docs-/}

COMMENT=	Documentation for salt

USE_TOOLS+=	gmake pax

TOOL_DEPENDS+=	salt-[0-9]*:../../sysutils/salt
TOOL_DEPENDS+=	${PYPKGPREFIX}-linkify-it-py-[0-9]*:../../textproc/py-linkify-it-py
TOOL_DEPENDS+=	${PYPKGPREFIX}-looseversion-[0-9]*:../../devel/py-looseversion
TOOL_DEPENDS+=	${PYPKGPREFIX}-myst-parser-[0-9]*:../../textproc/py-myst-parser
TOOL_DEPENDS+=	${PYPKGPREFIX}-sphinxcontrib-httpdomain-[0-9]*:../../textproc/py-sphinxcontrib-httpdomain
TOOL_DEPENDS+=	${PYPKGPREFIX}-sphinxcontrib-spelling-[0-9]*:../../textproc/py-sphinxcontrib-spelling

NO_CONFIGURE=	yes
BUILD_DIRS=	doc
BUILD_TARGET=	html

MAKE_FLAGS+=	SPHINXBUILD=${PREFIX}/bin/sphinx-build-${PYVERSSUFFIX}

HTMLDIR=	share/doc/salt
PLIST_SRC=	${WRKDIR}/.PLIST_SRC

INSTALLATION_DIRS=	${HTMLDIR}

PYTHON_VERSIONS_INCOMPATIBLE=	27 38 312

# Contains hardcoded paths that may refer to paths used during the build, for
# example /opt/tools on SmartOS.
CHECK_WRKREF_SKIP+=	*/*.html */*.txt

do-install:
	cd ${WRKSRC}/doc/_build/html && ${PAX} -rw -pp . ${DESTDIR}${PREFIX}/${HTMLDIR}
	cd ${DESTDIR}${PREFIX} && ${FIND} ${HTMLDIR} -type f -print >>${PLIST_SRC}

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
