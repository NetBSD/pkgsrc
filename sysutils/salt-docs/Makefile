# $NetBSD: Makefile,v 1.10 2016/07/09 13:04:07 wiz Exp $

DISTNAME=	salt-2015.8.5
PKGNAME=	${DISTNAME:S/-/-docs-/}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_PYPI:=s/salt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://saltstack.org/
COMMENT=	Documentation for salt
LICENSE=	apache-2.0

USE_TOOLS+=	gmake

BUILD_DEPENDS+=	gnupg-[0-9]*:../../security/gnupg

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
PYTHON_VERSIONS_INCOMPATIBLE=  34 35 # not yet ported as of 0.10.5

# The upstream salt project does not say what version of sphinx is required.
.include "../../lang/python/pyversion.mk"
BUILD_DEPENDS+=	${PYPKGPREFIX}-sphinx>=1.2.3nb1*:../../textproc/py-sphinx

.include "../../mk/bsd.pkg.mk"
