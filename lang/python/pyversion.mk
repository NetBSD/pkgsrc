# $NetBSD: pyversion.mk,v 1.36 2005/06/23 11:10:32 seb Exp $

.if !defined(PYTHON_PYVERSION_MK)
PYTHON_PYVERSION_MK=	defined

.include "../../mk/bsd.prefs.mk"

PYTHON_VERSION_DEFAULT?=		23
.if ${OPSYS} == "Darwin"
PYTHON_VERSIONS_INCOMPATIBLE+=		22 21 20 15
.endif
PYTHON_VERSIONS_ACCEPTED?=		24 23 22 21 20
PYTHON_VERSIONS_INCOMPATIBLE?=		# empty by default

BUILDLINK_DEPENDS.python15?=		python15>=1.5
BUILDLINK_DEPENDS.python20?=		python20>=2.0
BUILDLINK_DEPENDS.python21?=		python21>=2.1
BUILDLINK_DEPENDS.python22?=		python22>=2.2
BUILDLINK_DEPENDS.python23?=		python23>=2.3
BUILDLINK_DEPENDS.python24?=		python24>=2.4

# transform the list into individual variables
.for pv in ${PYTHON_VERSIONS_ACCEPTED}
.if empty(PYTHON_VERSIONS_INCOMPATIBLE:M${pv})
_PYTHON_VERSION_${pv}_OK=	yes
.endif
.endfor

# check what is installed
.if exists(${LOCALBASE}/bin/python2.4)
_PYTHON_VERSION_24_INSTALLED=	yes
.endif
.if exists(${LOCALBASE}/bin/python2.3)
_PYTHON_VERSION_23_INSTALLED=	yes
.endif
.if exists(${LOCALBASE}/bin/python2.2)
_PYTHON_VERSION_22_INSTALLED=	yes
.endif
.if exists(${LOCALBASE}/bin/python2.1)
_PYTHON_VERSION_21_INSTALLED=	yes
.endif
.if exists(${LOCALBASE}/bin/python2.0)
_PYTHON_VERSION_20_INSTALLED=	yes
.endif
.if exists(${LOCALBASE}/bin/python1.5)
_PYTHON_VERSION_15_INSTALLED=	yes
.endif

#
# choose a python version where to add,
# try to be intelligent
#
# if a version is explicitely required, take it
.if defined(PYTHON_VERSION_REQD)
_PYTHON_VERSION=	${PYTHON_VERSION_REQD}
.endif
# if the default is already installed, it is first choice
.if !defined(_PYTHON_VERSION)
.if defined(_PYTHON_VERSION_${PYTHON_VERSION_DEFAULT}_OK)
.if defined(_PYTHON_VERSION_${PYTHON_VERSION_DEFAULT}_INSTALLED)
_PYTHON_VERSION=	${PYTHON_VERSION_DEFAULT}
.endif
.endif
.endif
# prefer an already installed version, in order of "accepted"
.if !defined(_PYTHON_VERSION)
.for pv in ${PYTHON_VERSIONS_ACCEPTED}
.if defined(_PYTHON_VERSION_${pv}_OK)
.if defined(_PYTHON_VERSION_${pv}_INSTALLED)
_PYTHON_VERSION?=	${pv}
.else
# keep information as last resort - see below
_PYTHON_VERSION_FIRSTACCEPTED?=	${pv}
.endif
.endif
.endfor
.endif
# if the default is OK for the addon pkg, take this
.if !defined(_PYTHON_VERSION)
.if defined(_PYTHON_VERSION_${PYTHON_VERSION_DEFAULT}_OK)
_PYTHON_VERSION=	${PYTHON_VERSION_DEFAULT}
.endif
.endif
# take the first one accepted by the package
.if !defined(_PYTHON_VERSION)
_PYTHON_VERSION=	${_PYTHON_VERSION_FIRSTACCEPTED}
.endif

#
# set variables for the version we decided to use:
#  PYVERSSUFFIX: suffix to executables and in library path,
#                equal to sys.version[0:3]
#  PYPKGPREFIX: prefix to use in PKGNAME for extensions which can install
#               to multiple Python versions
#
.if ${_PYTHON_VERSION} == "24"
PYPKGSRCDIR=	../../lang/python24
PYDEPENDENCY=	${BUILDLINK_DEPENDS.python24}:${PYPKGSRCDIR}
PYPACKAGE=	python24
PYVERSSUFFIX=	2.4
PYPKGPREFIX=	py24
.elif ${_PYTHON_VERSION} == "23"
PYPKGSRCDIR=	../../lang/python23
PYDEPENDENCY=	${BUILDLINK_DEPENDS.python23}:${PYPKGSRCDIR}
PYPACKAGE=	python23
PYVERSSUFFIX=	2.3
PYPKGPREFIX=	py23
.elif ${_PYTHON_VERSION} == "22"
PYPKGSRCDIR=	../../lang/python22
PYDEPENDENCY=	${BUILDLINK_DEPENDS.python22}:${PYPKGSRCDIR}
PYPACKAGE=	python22
PYVERSSUFFIX=	2.2
PYPKGPREFIX=	py22
.elif ${_PYTHON_VERSION} == "21"
PYPKGSRCDIR=	../../lang/python21
PYPACKAGE=	python21
PYDEPENDENCY=	${BUILDLINK_DEPENDS.python21}:${PYPKGSRCDIR}
PYVERSSUFFIX=	2.1
PYPKGPREFIX=	py21
.elif ${_PYTHON_VERSION} == "20"
PYPKGSRCDIR=	../../lang/python20
PYPACKAGE=	python20
PYDEPENDENCY=	${BUILDLINK_DEPENDS.python20}:${PYPKGSRCDIR}
PYVERSSUFFIX=	2.0
PYPKGPREFIX=	py20
.elif ${_PYTHON_VERSION} == "15"
PYPKGSRCDIR=	../../lang/python15
PYPACKAGE=	python15
PYDEPENDENCY=	${BUILDLINK_DEPENDS.python15}:${PYPKGSRCDIR}
PYVERSSUFFIX=	1.5
PYPKGPREFIX=	py15
.if !defined(PYTHON_DISTUTILS_BOOTSTRAP)
BUILD_DEPENDS+=	py15-distutils-*:../../devel/py-distutils
.endif
.else
# force an error
PKG_FAIL_REASON+=   "No valid Python version"
.endif

PTHREAD_OPTS=	require
.include "../../mk/pthread.buildlink3.mk"
.if defined(PYTHON_FOR_BUILD_ONLY)
BUILDLINK_DEPMETHOD.python?=	build
.endif
.include "${PYPKGSRCDIR}/buildlink3.mk"

PYTHONBIN=	${LOCALBASE}/bin/python${PYVERSSUFFIX}

.if exists(${PYTHONBIN})
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

.endif	# PYTHON_PYVERSION_MK
