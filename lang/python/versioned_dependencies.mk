# $NetBSD: versioned_dependencies.mk,v 1.62 2022/01/29 21:46:17 wiz Exp $
#
# This file determines which separate distribution of a Python
# package is used as dependency, depending on the Python version
# used.
#
# === User-settable variables ===
#
# PYTHON_VERSIONED_DEPENDENCIES
#       The Python package which should be added as a dependency.
#
#       Possible values: Pmw Pillow X cairo flake8 html2text hypothesis importlib-metadata ipython markdown more-itertools pip packaging pygments pyparsing python-digest rsa setuptools setuptools_scm sphinx test testtools zipp
#       Default: (nothing)
#

.include "../../lang/python/pyversion.mk"

# format: short name for PYTHON_VERSIONED_DEPENDENCIES<space>Python-2.x path<space>Python-3.x path
_SUPPORTED_PACKAGES=	# empty
_SUPPORTED_PACKAGES+=	Pmw x11/py-Pmw x11/py-Pmw2
_SUPPORTED_PACKAGES+=	Pillow graphics/py-Pillow6 graphics/py-Pillow
_SUPPORTED_PACKAGES+=	X textproc/py-X2 textproc/py-X
_SUPPORTED_PACKAGES+=	cairo graphics/py-cairo118 graphics/py-cairo
# XXX feedparser 6.x is not only py27-incompatible, but also 5.x-API-incompatible
#_SUPPORTED_PACKAGES+=	feedparser textproc/py-feedparser5 textproc/py-feedparser
_SUPPORTED_PACKAGES+=	flake8 devel/py-flake8-3 devel/py-flake8
_SUPPORTED_PACKAGES+=	html2text textproc/py-html2text-2019.8.11 textproc/py-html2text
_SUPPORTED_PACKAGES+=	hypothesis devel/py-hypothesis4 devel/py-hypothesis
_SUPPORTED_PACKAGES+=	importlib-metadata devel/py-importlib-metadata2 devel/py-importlib-metadata
_SUPPORTED_PACKAGES+=	ipython devel/py-ipython5 devel/py-ipython
_SUPPORTED_PACKAGES+=	isort devel/py-isort4 devel/py-isort
_SUPPORTED_PACKAGES+=	markdown textproc/py-markdown3 textproc/py-markdown
_SUPPORTED_PACKAGES+=	more-itertools devel/py-more-itertools2 devel/py-more-itertools
_SUPPORTED_PACKAGES+=	packaging devel/py-packaging2 devel/py-packaging
_SUPPORTED_PACKAGES+=	pip devel/py-pip20 devel/py-pip
_SUPPORTED_PACKAGES+=	pygments textproc/py-pygments25 textproc/py-pygments
_SUPPORTED_PACKAGES+=	pyparsing devel/py-pyparsing2 devel/py-pyparsing
_SUPPORTED_PACKAGES+=	python-digest www/py-python-digest www/py-python3-digest
_SUPPORTED_PACKAGES+=	rsa security/py-rsa40 security/py-rsa
_SUPPORTED_PACKAGES+=	setuptools devel/py-setuptools44 devel/py-setuptools
_SUPPORTED_PACKAGES+=	setuptools_scm devel/py-setuptools_scm5 devel/py-setuptools_scm
_SUPPORTED_PACKAGES+=	sphinx textproc/py-sphinx1 textproc/py-sphinx
_SUPPORTED_PACKAGES+=	test devel/py-test4 devel/py-test
_SUPPORTED_PACKAGES+=	testtools devel/py-testtools24 devel/py-testtools
_SUPPORTED_PACKAGES+=	zipp archivers/py-zipp1 archivers/py-zipp

.for pattern in ${PYTHON_VERSIONED_DEPENDENCIES}
_PKG_MATCHED=	no
pkg:=	${pattern:C/:.*//}
type:=	${pattern:C/[^:]*//}
.  for name py2dir py3dir in ${_SUPPORTED_PACKAGES}
.    if "${pkg}" == "${name}"
_PKG_MATCHED=	yes
.      if ${_PYTHON_VERSION} == 27
dir:=	${py2dir}
.      else
dir:=	${py3dir}
.      endif
.      if "${type}" == ":link"
.include "../../${dir}/buildlink3.mk"
.      elif "${type}" == ":build"
BUILD_DEPENDS:=	${BUILD_DEPENDS} ${PYPKGPREFIX}-${pkg}-[0-9]*:../../${dir}
.      elif "${type}" == ":test"
TEST_DEPENDS:=	${TEST_DEPENDS} ${PYPKGPREFIX}-${pkg}-[0-9]*:../../${dir}
.      elif "${type}" == ":tool"
TOOL_DEPENDS:=	${TOOL_DEPENDS} ${PYPKGPREFIX}-${pkg}-[0-9]*:../../${dir}
.      else
DEPENDS:=	${DEPENDS} ${PYPKGPREFIX}-${pkg}-[0-9]*:../../${dir}
.      endif
.    endif
.  endfor
.  if ${_PKG_MATCHED} == "no"
PKG_FAIL_REASON+=	"${pkg} unsupported in PYTHON_VERSIONED_DEPENDENCIES"
.  endif
.endfor
