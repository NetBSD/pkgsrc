# $NetBSD: Makefile,v 1.13 2018/02/07 11:11:23 adam Exp $

DISTNAME=	salt-2017.7.3
PKGNAME=	${DISTNAME:S/-/-docs-/}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_PYPI:=s/salt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://saltstack.org/
COMMENT=	Documentation for salt
LICENSE=	apache-2.0

USE_TOOLS+=	gmake pax

BUILD_DEPENDS+=	${PYPKGPREFIX}-sphinx>=1.2.3nb1*:../../textproc/py-sphinx

NO_CONFIGURE=	yes
BUILD_DIRS=	doc
BUILD_TARGET=	html

MAKE_FLAGS+=	SPHINXBUILD=${PREFIX}/bin/sphinx-build${PYVERSSUFFIX}

HTMLDIR=	share/doc/salt
PLIST_SRC=	${WRKDIR}/.PLIST_SRC

INSTALLATION_DIRS=	${HTMLDIR}

do-install:
	cd ${WRKSRC}/doc/_build/html && pax -rw -pe . ${DESTDIR}${PREFIX}/${HTMLDIR}
	cd ${DESTDIR}${PREFIX} && ${FIND} ${HTMLDIR} -type f -print >>${PLIST_SRC}

# problem building due to some mocking
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
