# $NetBSD: egg.mk,v 1.42 2023/10/29 17:07:15 wiz Exp $
#
# The method used in this Makefile fragment is obsolete.
# Please use wheel.mk instead.

#
# Common logic to handle Python Eggs
#
.include "../../mk/bsd.fast.prefs.mk"
.include "../../lang/python/pyversion.mk"


EGG_NAME?=	${DISTNAME:C/-([^0-9])/_\1/g}
EGG_INFODIR?=	${EGG_NAME}-py${PYVERSSUFFIX}.egg-info

PYDISTUTILSPKG?=	yes
PY_PATCHPLIST?=		yes

# True eggs always have an egg-info directory. egg.mk can also
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
do-build: ensurepip
.PHONY: ensurepip
.include "../../lang/python/batteries-included.mk"

ensurepip:
	${SETENV} ${MAKE_ENV} ${TOOL_PYTHONBIN} -m ensurepip --user
.else
.  if "${PYVERSSUFFIX}" == "2.7"
SETUPTOOLS_PATH=../../devel/py-setuptools44
.  else
SETUPTOOLS_PATH=../../devel/py-setuptools
.  endif
.  if "${USE_PKG_RESOURCES}" == "yes"
# when packages use pkg_resources, setuptools is needed at runtime
DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:${SETUPTOOLS_PATH}
.  endif
# in all cases (in particular, for cross-compilation), setuptools
# also needs to be a tool dependency
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:${SETUPTOOLS_PATH}
.endif

.if ${USE_CROSS_COMPILE:U:tl} == "yes"
.if ${PYTHON_FOR_BUILD_ONLY:Uno:tl} == "no" || \
    ${PYTHON_FOR_BUILD_ONLY:Uno:tl} == "build"
_COOKIE.pysetupcross=	${WRKDIR}/.pysetupcross_done
pre-configure: ${_COOKIE.pysetupcross}
${_COOKIE.pysetupcross}:
	@${STEP_MSG} "Adjusting Python setup.cfg for cross-compiling"
	${RUN} ${PRINTF} "\\n[build]\\nexecutable = '%s'\\n" ${PYTHONBIN:Q} \
		>>${WRKSRC}/setup.cfg
	${RUN} touch $@
.endif
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
