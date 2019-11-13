# $NetBSD: Makefile,v 1.24 2019/11/13 14:47:59 adam Exp $

DISTNAME=	salt-2019.2.2
PKGNAME=	${DISTNAME:S/-/-docs-/}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/salt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://saltstack.org/
COMMENT=	Documentation for salt
LICENSE=	apache-2.0

USE_TOOLS+=	gmake pax

BUILD_DEPENDS+=	${PYPKGPREFIX}-sphinx>=1.2.3nb1*:../../textproc/py-sphinx1

NO_CONFIGURE=	yes
BUILD_DIRS=	doc
BUILD_TARGET=	html

MAKE_FLAGS+=	SPHINXBUILD=${PREFIX}/bin/sphinx-build-${PYVERSSUFFIX}

HTMLDIR=	share/doc/salt
PLIST_SRC=	${WRKDIR}/.PLIST_SRC

INSTALLATION_DIRS=	${HTMLDIR}

PYTHON_VERSIONS_ACCEPTED=	27

do-install:
	cd ${WRKSRC}/doc/_build/html && ${PAX} -rw -pp . ${DESTDIR}${PREFIX}/${HTMLDIR}
	cd ${DESTDIR}${PREFIX} && ${FIND} ${HTMLDIR} -type f -print >>${PLIST_SRC}

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
