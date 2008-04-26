# $NetBSD: egg.mk,v 1.4 2008/04/26 15:37:21 joerg Exp $
#
# Common logic to handle Python Eggs
#
.include "../../mk/bsd.prefs.mk"

PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes
# Only Python 2.4 support by devel/py-setuptools right now
PYTHON_VERSIONS_ACCEPTED?=	25 24

PLIST_SUBST+=	EGG_NAME=${EGG_NAME}-py${PYVERSSUFFIX}
PLIST_SUBST+=	EGG_INFODIR=${EGG_NAME}-py${PYVERSSUFFIX}.egg-info

_PYSETUPTOOLSINSTALLARGS=	--single-version-externally-managed
.if ${_USE_DESTDIR} == "no"
_PYSETUPTOOLSINSTALLARGS+=	--root=/
.endif

DEPENDS+=	${PYPKGPREFIX}-setuptools>=0.6c6:../../devel/py-setuptools

INSTALLATION_DIRS+=	${PYSITELIB}

.include "../../lang/python/extension.mk"
