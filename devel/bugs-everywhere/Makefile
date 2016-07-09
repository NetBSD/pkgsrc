# $NetBSD: Makefile,v 1.4 2016/07/09 13:03:37 wiz Exp $

DISTNAME=	be-1.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/be/bugs-everywhere/}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://download.bugseverywhere.org/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://bugseverywhere.org/
COMMENT=	Distributed bugtracker
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-cherrypy-[0-9]*:../../www/py-cherrypy
# supposedly needed for docs and man pages, but no change to binary package
#BUILD_DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx
#BUILD_DEPENDS+=	${PYPKGPREFIX}-numpydoc-[0-9]*:../../textproc/py-numpydoc
#BUILD_DEPENDS+=	${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils

USE_LANGUAGES=	# none

EGG_NAME=			bugs_everywhere-${PKGVERSION_NOREV}
PLIST_SUBST+=			PYVERSSUFFIX=${PYVERSSUFFIX}
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # not ported yet as of 1.1.1
REPLACE_PYTHON+=		libbe/version.py
FILES_SUBST+=			PYVERSSUFFIX=${PYVERSSUFFIX}

post-install:
	cd ${DESTDIR}${PREFIX}/bin && mv be be${PYVERSSUFFIX}

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
