# $NetBSD: Makefile,v 1.6 2015/09/12 20:03:01 tnn Exp $

DISTNAME=	salt-0.10.5
PKGNAME=	${DISTNAME:S/-/-docs-/}
CATEGORIES=	sysutils
MASTER_SITES=	https://cloud.github.com/downloads/saltstack/salt/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://saltstack.org/
COMMENT=	Documentation for salt
LICENSE=	apache-2.0

NO_CONFIGURE=	yes
BUILD_DIRS=	doc
BUILD_TARGET=	html

MAKE_FLAGS+=	SPHINXBUILD=${PREFIX}/bin/sphinx-build${PYVERSSUFFIX}

HTMLDIR=	share/doc/salt
PLIST_SRC=	${WRKDIR}/.PLIST_SRC

INSTALLATION_DIRS=	${HTMLDIR}

do-install:
	( cd ${WRKSRC}/doc/_build/html \
	  && pax -rw -pe . ${DESTDIR}${PREFIX}/${HTMLDIR} )
	( cd ${DESTDIR}${PREFIX} \
	  && ${FIND} ${HTMLDIR} -type f -print ) >>${PLIST_SRC}

# problem in sphinx config file?
PYTHON_VERSIONS_INCOMPATIBLE=  33 34 # not yet ported as of 0.10.5

# The upstream salt project does not say what version of sphinx is required.
.include "../../lang/python/pyversion.mk"
BUILD_DEPENDS+=	${PYPKGPREFIX}-sphinx>=1.2.3nb1*:../../textproc/py-sphinx

.include "../../mk/bsd.pkg.mk"
