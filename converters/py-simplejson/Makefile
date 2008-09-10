# $NetBSD: Makefile,v 1.2 2008/09/10 13:56:40 mjl Exp $
#

PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
DISTNAME=	simplejson-1.9.2
CATEGORIES=	converters
MASTER_SITES=	http://pypi.python.org/packages/source/s/simplejson/

MAINTAINER=	pkgsrc@NetBSD.org
HOMEPAGE=	http://undefined.org/python/#simplejson
COMMENT=	Simplejson is a simple, fast, extensible JSON encoder/decoder

USE_LANGUAGES=  # none

PYDISTUTILSPKG=         yes
PYBINMODULE=    yes
PYSETUPINSTALLARGS= --single-version-externally-managed --record plist.txt
PLIST_SUBST+=   PYVERSSUFFIX=${PYVERSSUFFIX:Q}

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
