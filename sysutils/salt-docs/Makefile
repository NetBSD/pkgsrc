# $NetBSD: Makefile,v 1.4 2014/05/09 07:37:20 wiz Exp $

DISTNAME=	salt-0.10.5
PKGNAME=	${DISTNAME:S/-/-docs-/}
CATEGORIES=	sysutils
MASTER_SITES=	http://cloud.github.com/downloads/saltstack/salt/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://saltstack.org/
COMMENT=	Documentation for salt
LICENSE=	apache-2.0

NO_CONFIGURE=	yes
BUILD_DIRS=	doc
BUILD_TARGET=	html

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
BUILD_DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx

.include "../../mk/bsd.pkg.mk"
