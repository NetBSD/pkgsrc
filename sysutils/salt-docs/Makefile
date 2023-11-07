# $NetBSD: Makefile,v 1.34 2023/11/07 22:38:04 wiz Exp $

PKGREVISION= 2
.include "../../sysutils/salt/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-docs-/}

COMMENT=	Documentation for salt

USE_TOOLS+=	gmake pax

TOOL_DEPENDS+=	salt-[0-9]*:../../sysutils/salt
TOOL_DEPENDS+=	${PYPKGPREFIX}-sphinx>=1.2.3nb1:../../textproc/py-sphinx

NO_CONFIGURE=	yes
BUILD_DIRS=	doc
BUILD_TARGET=	html

MAKE_FLAGS+=	SPHINXBUILD=${PREFIX}/bin/sphinx-build-${PYVERSSUFFIX}

HTMLDIR=	share/doc/salt
PLIST_SRC=	${WRKDIR}/.PLIST_SRC

INSTALLATION_DIRS=	${HTMLDIR}

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

# Contains hardcoded paths that may refer to paths used during the build, for
# example /opt/tools on SmartOS.
CHECK_WRKREF_SKIP+=	*/*.html */*.txt

do-install:
	cd ${WRKSRC}/doc/_build/html && ${PAX} -rw -pp . ${DESTDIR}${PREFIX}/${HTMLDIR}
	cd ${DESTDIR}${PREFIX} && ${FIND} ${HTMLDIR} -type f -print >>${PLIST_SRC}

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
