# $NetBSD: egg.mk,v 1.6 2008/09/12 05:32:38 epg Exp $
#
# Common logic to handle Python Eggs
#
.include "../../mk/bsd.prefs.mk"

EGG_NAME?=	${DISTNAME}

PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes
# Only Python 2.4 support by devel/py-setuptools right now
PYTHON_VERSIONS_ACCEPTED?=	25 24

PLIST_SUBST+=	EGG_NAME=${EGG_NAME}-py${PYVERSSUFFIX}
PLIST_SUBST+=	EGG_INFODIR=${EGG_NAME}-py${PYVERSSUFFIX}.egg-info
PRINT_PLIST_AWK+=	{ gsub(/${EGG_NAME}-py${PYVERSSUFFIX}.egg-info/, \
			       "$${EGG_INFODIR}") }
PRINT_PLIST_AWK+=	{ gsub(/${EGG_NAME}-py${PYVERSSUFFIX}-nspkg.pth/, \
			       "$${EGG_NAME}-nspkg.pth") }

_PYSETUPTOOLSINSTALLARGS=	--single-version-externally-managed
.if ${_USE_DESTDIR} == "no"
_PYSETUPTOOLSINSTALLARGS+=	--root=/
.endif

DEPENDS+=	${PYPKGPREFIX}-setuptools>=0.6c6:../../devel/py-setuptools

INSTALLATION_DIRS+=	${PYSITELIB}

.include "../../lang/python/extension.mk"
