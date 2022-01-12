# $NetBSD: egg.mk,v 1.35 2022/01/12 08:34:34 wiz Exp $
#
# Common logic to handle Python Eggs
#
.include "../../mk/bsd.fast.prefs.mk"
.include "../../lang/python/pyversion.mk"

# This file should be included to package python "distributions" which
# use setuptools to create an egg.
#
# For wheel (*.whl) support, look at wheel.mk.

EGG_NAME?=	${DISTNAME:C/-([^0-9])/_\1/g}
EGG_INFODIR?=	${EGG_NAME}-py${PYVERSSUFFIX}.egg-info

PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes

# True eggs always have an egg-info directory egg.mk can also
# be used for distutils packages, in which case there will be no
# egg-info directory.

# Please note that some packages do not provide this directory
# with the last setuptools version that supports python 2.7.
# In this case, the ${EGG_INFODIR} lines in the PLIST need to
# be prefixed with ${PLIST.py3x} - please always test with both
# python 2.7 and the current python 3.x default!

PLIST_SUBST+=	EGG_NAME=${EGG_NAME}-py${PYVERSSUFFIX}
PLIST_SUBST+=	EGG_INFODIR=${EGG_INFODIR}
PRINT_PLIST_AWK+=	{ gsub(/${EGG_NAME}-py${PYVERSSUFFIX:S,.,\.,g}.egg-info/, \
			       "$${EGG_INFODIR}") }
PRINT_PLIST_AWK+=	{ gsub(/${EGG_NAME}-py${PYVERSSUFFIX:S,.,\.,g}-nspkg.pth/, \
			       "$${EGG_NAME}-nspkg.pth") }
PRINT_PLIST_AWK+=	{ gsub(/${PYVERSSUFFIX:S,.,\.,g}/, \
			       "$${PYVERSSUFFIX}") }

USE_PKG_RESOURCES?=	no

# py-setuptools needs to be bootstrapped from python itself, without using
# py-setuptools.
BOOTSTRAP_SETUPTOOLS?=	no
.if ${BOOTSTRAP_SETUPTOOLS} == "yes"
TOOL_DEPENDS+=		${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat
do-build: ensurepip
.PHONY: ensurepip

ensurepip:
	${SETENV} ${MAKE_ENV} ${PYTHONBIN} -m ensurepip --user
.else
.  if "${PYVERSSUFFIX}" == "2.7"
SETUPTOOLS_PATH=../../devel/py-setuptools44
.  else
SETUPTOOLS_PATH=../../devel/py-setuptools
.  endif
.  if "${USE_PKG_RESOURCES}" == "yes"
DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:${SETUPTOOLS_PATH}
.  else
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:${SETUPTOOLS_PATH}
.  endif
.endif

INSTALLATION_DIRS+=	${PYSITELIB}

privileged-install-hook:	fixup-egg-info
.PHONY:				fixup-egg-info
fixup-egg-info:	# ensure egg-info directory contents are always 644
	if ${TEST} -d "${DESTDIR}${PREFIX}/${PYSITELIB}/${EGG_INFODIR}"; then \
	    ${FIND} ${DESTDIR}${PREFIX}/${PYSITELIB}/${EGG_INFODIR} -type f \
		-exec ${CHMOD} ${SHAREMODE} '{}' +; \
	fi

.include "../../lang/python/extension.mk"
