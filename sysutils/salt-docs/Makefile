# $NetBSD: Makefile,v 1.31 2023/06/06 12:42:23 riastradh Exp $

.include "../../sysutils/salt/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-docs-/}

COMMENT=	Documentation for salt

USE_TOOLS+=	gmake pax

TOOL_DEPENDS+=	salt-[0-9]*:../../sysutils/salt
TOOL_DEPENDS+=	${PYPKGPREFIX}-sphinx>=1.2.3nb1:../../textproc/py-sphinx
TOOL_DEPENDS+=	${PYPKGPREFIX}-sqlite3>=1.2.3nb1:../../databases/py-sqlite3

NO_CONFIGURE=	yes
BUILD_DIRS=	doc
BUILD_TARGET=	html

MAKE_FLAGS+=	SPHINXBUILD=${PREFIX}/bin/sphinx-build-${PYVERSSUFFIX}

HTMLDIR=	share/doc/salt
PLIST_SRC=	${WRKDIR}/.PLIST_SRC

INSTALLATION_DIRS=	${HTMLDIR}

PYTHON_VERSIONS_INCOMPATIBLE=	27

# Contains hardcoded paths that may refer to paths used during the build, for
# example /opt/tools on SmartOS.
CHECK_WRKREF_SKIP+=	*/*.html */*.txt

do-install:
	cd ${WRKSRC}/doc/_build/html && ${PAX} -rw -pp . ${DESTDIR}${PREFIX}/${HTMLDIR}
	cd ${DESTDIR}${PREFIX} && ${FIND} ${HTMLDIR} -type f -print >>${PLIST_SRC}

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
