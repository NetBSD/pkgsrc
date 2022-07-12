# $NetBSD: versioned_dependencies.mk,v 1.79 2022/07/12 09:29:37 wiz Exp $
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
#       Possible values: Pillow X cairo chardet click cryptography flake8 html2text hypothesis importlib-metadata jinja2 lama markdown mccabe more-itertools pip packaging pygments pyparsing pyphen python-digest rsa setuptools setuptools_scm test twisted
#       Default: (nothing)
#

.include "../../lang/python/pyversion.mk"

# format: short name for PYTHON_VERSIONED_DEPENDENCIES<space>Python-2.x path<space>Python-3.x path
_SUPPORTED_PACKAGES=	# empty
_SUPPORTED_PACKAGES+=	Pillow graphics/py-Pillow6 graphics/py-Pillow
_SUPPORTED_PACKAGES+=	X textproc/py-X2 textproc/py-X
_SUPPORTED_PACKAGES+=	cairo graphics/py-cairo118 graphics/py-cairo
_SUPPORTED_PACKAGES+=	chardet converters/py-chardet4 converters/py-chardet
_SUPPORTED_PACKAGES+=	click devel/py-click7 devel/py-click
_SUPPORTED_PACKAGES+=	cryptography security/py27-cryptography security/py-cryptography 
_SUPPORTED_PACKAGES+=	flake8 devel/py-flake8-3 devel/py-flake8
_SUPPORTED_PACKAGES+=	html2text textproc/py-html2text-2019.8.11 textproc/py-html2text
_SUPPORTED_PACKAGES+=	hypothesis devel/py-hypothesis4 devel/py-hypothesis
_SUPPORTED_PACKAGES+=	importlib-metadata devel/py-importlib-metadata2 devel/py-importlib-metadata
_SUPPORTED_PACKAGES+=	isort devel/py-isort4 devel/py-isort
_SUPPORTED_PACKAGES+=	jinja2 textproc/py27-jinja2 textproc/py-jinja2
_SUPPORTED_PACKAGES+=	lama devel/py-lama7 devel/py-lama
_SUPPORTED_PACKAGES+=	markdown textproc/py-markdown3 textproc/py-markdown
_SUPPORTED_PACKAGES+=	mccabe devel/py-mccabe06 devel/py-mccabe
_SUPPORTED_PACKAGES+=	more-itertools devel/py-more-itertools2 devel/py-more-itertools
_SUPPORTED_PACKAGES+=	packaging devel/py-packaging2 devel/py-packaging
_SUPPORTED_PACKAGES+=	pip devel/py-pip20 devel/py-pip
_SUPPORTED_PACKAGES+=	pygments textproc/py-pygments25 textproc/py-pygments
_SUPPORTED_PACKAGES+=	pyparsing devel/py-pyparsing2 devel/py-pyparsing
_SUPPORTED_PACKAGES+=	pyphen textproc/py27-pyphen textproc/py-pyphen
_SUPPORTED_PACKAGES+=	python-digest www/py-python-digest www/py-python3-digest
_SUPPORTED_PACKAGES+=	rsa security/py-rsa40 security/py-rsa
_SUPPORTED_PACKAGES+=	setuptools devel/py-setuptools44 devel/py-setuptools
_SUPPORTED_PACKAGES+=	setuptools_scm devel/py-setuptools_scm5 devel/py-setuptools_scm
_SUPPORTED_PACKAGES+=	test devel/py-test4 devel/py-test
_SUPPORTED_PACKAGES+=	twisted net/py-twisted19 net/py-twisted

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
