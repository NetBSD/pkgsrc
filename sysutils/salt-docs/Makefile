# $NetBSD: Makefile,v 1.27 2022/06/30 11:18:52 nia Exp $

DISTNAME=	salt-3004
PKGNAME=	${DISTNAME:S/-/-docs-/}
PKGREVISION=	1
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/salt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://saltstack.org/
COMMENT=	Documentation for salt
LICENSE=	apache-2.0

USE_TOOLS+=	gmake pax

BUILD_DEPENDS+=	${PYPKGPREFIX}-sphinx>=1.2.3nb1*:../../textproc/py-sphinx1
BUILD_DEPENDS+=	${PYPKGPREFIX}-sqlite3>=1.2.3nb1*:../../databases/py-sqlite3

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
CHECK_WRKREF_SKIP+=    */*.html */*.txt

do-install:
	cd ${WRKSRC}/doc/_build/html && ${PAX} -rw -pp . ${DESTDIR}${PREFIX}/${HTMLDIR}
	cd ${DESTDIR}${PREFIX} && ${FIND} ${HTMLDIR} -type f -print >>${PLIST_SRC}

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
