# $NetBSD: pyversion.mk,v 1.50 2008/02/01 08:17:00 xtraeme Exp $

# This file determines which Python version is used as a dependency for
# a package.
#
# === User-settable variables ===
#
# PYTHON_VERSION_DEFAULT
#	The preferred Python version to use.
#
#	Possible values: 15 20 21 22 23 24 25
#	Default: 24
#
# === Package-settable variables ===
#
# PYTHON_VERSIONS_ACCEPTED
#	The Python versions that are acceptable for the package. The
#	order of the entries matters, since earlier entries are
#	preferred over later ones. If the package doesn't work with
#	older Python versions but only with newer ones, please use
#	PYTHON_VERSIONS_INCOMPATIBLE instead, since it will
#	automatically include future versions.
#
#	Possible values: 25 24 23 22 21 20 15
#	Default: (all)
#
# PYTHON_VERSIONS_INCOMPATIBLE
#	The Python versions that are NOT acceptable for the package.
#
#	Possible values: 15 20 21 22 23 24 25
#	Default: (depends on the platform)
#
# PYTHON_FOR_BUILD_ONLY
#	Whether Python is needed only at build time or at run time.
#
#	Possible values: (defined) (undefined)
#	Default: (undefined)
#
# Keywords: python
#

.if !defined(PYTHON_PYVERSION_MK)
PYTHON_PYVERSION_MK=	defined

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		PYTHON_VERSION_DEFAULT
BUILD_DEFS_EFFECTS+=	PYPACKAGE

PYTHON_VERSION_DEFAULT?=		24
.if ${OPSYS} == "Darwin"
PYTHON_VERSIONS_INCOMPATIBLE+=		22 21 20 15
.endif
PYTHON_VERSIONS_ACCEPTED?=		25 24 23 22 21 20
PYTHON_VERSIONS_INCOMPATIBLE?=		# empty by default

BUILDLINK_API_DEPENDS.python15?=		python15>=1.5
BUILDLINK_API_DEPENDS.python20?=		python20>=2.0
BUILDLINK_API_DEPENDS.python21?=		python21>=2.1
BUILDLINK_API_DEPENDS.python22?=		python22>=2.2
BUILDLINK_API_DEPENDS.python23?=		python23>=2.3
BUILDLINK_API_DEPENDS.python24?=		python24>=2.4
BUILDLINK_API_DEPENDS.python25?=		python25>=2.5.1

# transform the list into individual variables
.for pv in ${PYTHON_VERSIONS_ACCEPTED}
.if empty(PYTHON_VERSIONS_INCOMPATIBLE:M${pv})
_PYTHON_VERSION_${pv}_OK=	yes
.endif
.endfor

#
# choose a python version where to add,
# try to be intelligent
#
# if a version is explicitely required, take it
.if defined(PYTHON_VERSION_REQD)
# but check if it is acceptable first, error out otherwise
. if defined(_PYTHON_VERSION_${PYTHON_VERSION_REQD}_OK)
_PYTHON_VERSION=	${PYTHON_VERSION_REQD}
. endif
.else
# if the default is accepted, it is first choice
. if !defined(_PYTHON_VERSION)
. if defined(_PYTHON_VERSION_${PYTHON_VERSION_DEFAULT}_OK)
_PYTHON_VERSION=	${PYTHON_VERSION_DEFAULT}
. endif
. endif
# prefer an already installed version, in order of "accepted"
. if !defined(_PYTHON_VERSION)
. for pv in ${PYTHON_VERSIONS_ACCEPTED}
. if defined(_PYTHON_VERSION_${pv}_OK)
_PYTHON_VERSION?=	${pv}
. endif
. endfor
. endif
.endif

# No supported version found, annotate to simplify statements below.
.if !defined(_PYTHON_VERSION)
_PYTHON_VERSION=	none
.endif

#
# set variables for the version we decided to use:
#  PYVERSSUFFIX: suffix to executables and in library path,
#                equal to sys.version[0:3]
#  PYPKGPREFIX: prefix to use in PKGNAME for extensions which can install
#               to multiple Python versions
#
.if ${_PYTHON_VERSION} == "25"
PYPKGSRCDIR=	../../wip/python25
PYDEPENDENCY=	${BUILDLINK_API_DEPENDS.python25}:${PYPKGSRCDIR}
PYPACKAGE=	python25
PYVERSSUFFIX=	2.5
PYPKGPREFIX=	py25
.elif ${_PYTHON_VERSION} == "24"
PYPKGSRCDIR=	../../lang/python24
PYDEPENDENCY=	${BUILDLINK_API_DEPENDS.python24}:${PYPKGSRCDIR}
PYPACKAGE=	python24
PYVERSSUFFIX=	2.4
PYPKGPREFIX=	py24
.elif ${_PYTHON_VERSION} == "23"
PYPKGSRCDIR=	../../lang/python23
PYDEPENDENCY=	${BUILDLINK_API_DEPENDS.python23}:${PYPKGSRCDIR}
PYPACKAGE=	python23
PYVERSSUFFIX=	2.3
PYPKGPREFIX=	py23
.elif ${_PYTHON_VERSION} == "22"
PYPKGSRCDIR=	../../lang/python22
PYDEPENDENCY=	${BUILDLINK_API_DEPENDS.python22}:${PYPKGSRCDIR}
PYPACKAGE=	python22
PYVERSSUFFIX=	2.2
PYPKGPREFIX=	py22
.elif ${_PYTHON_VERSION} == "21"
PYPKGSRCDIR=	../../lang/python21
PYPACKAGE=	python21
PYDEPENDENCY=	${BUILDLINK_API_DEPENDS.python21}:${PYPKGSRCDIR}
PYVERSSUFFIX=	2.1
PYPKGPREFIX=	py21
.elif ${_PYTHON_VERSION} == "20"
PYPKGSRCDIR=	../../lang/python20
PYPACKAGE=	python20
PYDEPENDENCY=	${BUILDLINK_API_DEPENDS.python20}:${PYPKGSRCDIR}
PYVERSSUFFIX=	2.0
PYPKGPREFIX=	py20
.elif ${_PYTHON_VERSION} == "15"
PYPKGSRCDIR=	../../lang/python15
PYPACKAGE=	python15
PYDEPENDENCY=	${BUILDLINK_API_DEPENDS.python15}:${PYPKGSRCDIR}
PYVERSSUFFIX=	1.5
PYPKGPREFIX=	py15
.if !defined(PYTHON_DISTUTILS_BOOTSTRAP)
BUILD_DEPENDS+=	py15-distutils-[0-9]*:../../devel/py-distutils
.endif
.else
PKG_FAIL_REASON+=   "No valid Python version"
.endif

PTHREAD_OPTS+=	require
.include "../../mk/pthread.buildlink3.mk"

.if defined(PYTHON_FOR_BUILD_ONLY)
BUILDLINK_DEPMETHOD.python?=	build
.endif
.if defined(PYPKGSRCDIR)
.include "${PYPKGSRCDIR}/buildlink3.mk"
.endif

PYTHONBIN=	${LOCALBASE}/bin/python${PYVERSSUFFIX}

.if exists(${PYTHONBIN}) && !defined(PYTHON_DISTUTILS_BOOTSTRAP)
PYINC!=	${PYTHONBIN} -c "import distutils.sysconfig; \
	print distutils.sysconfig.get_python_inc(0, \"\")" || ${ECHO} ""
PYLIB!=	${PYTHONBIN} -c "import distutils.sysconfig; \
	print distutils.sysconfig.get_python_lib(0, 1, \"\")" || ${ECHO} ""
PYSITELIB!=	${PYTHONBIN} -c "import distutils.sysconfig; \
	print distutils.sysconfig.get_python_lib(0, 0, \"\")" || ${ECHO} ""

PRINT_PLIST_AWK+=	/^@dirrm ${PYINC:S|/|\\/|g}$$/ { next; }
PRINT_PLIST_AWK+=	/^@dirrm ${PYSITELIB:S|/|\\/|g}$$/ { next; }
PRINT_PLIST_AWK+=	/^@dirrm ${PYLIB:S|/|\\/|g}$$/ { next; }

PRINT_PLIST_AWK+=	/^(@dirrm )?${PYINC:S|/|\\/|g}/ \
			{ gsub(/${PYINC:S|/|\\/|g}/, "$${PYINC}"); \
				print; next; }
PRINT_PLIST_AWK+=	/^(@dirrm )?${PYSITELIB:S|/|\\/|g}/ \
			{ gsub(/${PYSITELIB:S|/|\\/|g}/, "$${PYSITELIB}"); \
				print; next; }
PRINT_PLIST_AWK+=	/^(@dirrm )?${PYLIB:S|/|\\/|g}/ \
			{ gsub(/${PYLIB:S|/|\\/|g}/, "$${PYLIB}"); \
				print; next; }
.endif

ALL_ENV+=	PYTHON=${PYTHONBIN}

.endif	# PYTHON_PYVERSION_MK
