# $NetBSD: extension.buildlink.mk,v 1.4 2001/12/07 19:47:13 jmc Exp $

.include "../../mk/bsd.prefs.mk"

PYTHON_VERSION_DEFAULT?=	21
PYTHON_VERSIONS_ACCEPTED?=	21 20

# transform the list into individual variables
.for pv in ${PYTHON_VERSIONS_ACCEPTED}
_PYTHON_VERSION_${pv}_OK=	yes
.endfor

# check what is installed
.if exists(${LOCALBASE}/bin/python2.1)
_PYTHON_VERSION_21_INSTALLED=	yes
.endif
.if exists(${LOCALBASE}/bin/python2.0)
_PYTHON_VERSION_20_INSTALLED=	yes
.endif

#
# choose a python version where to add,
# try to be intelligent
#
# if the default is already installed, it is first choice
.if defined(_PYTHON_VERSION_${PYTHON_VERSION_DEFAULT}_OK)
.if defined(_PYTHON_VERSION_${PYTHON_VERSION_DEFAULT}_INSTALLED)
_PYTHON_VERSION=	${PYTHON_VERSION_DEFAULT}
.endif
.endif
# prefer an already installed version, in order of "accepted"
.if !defined(_PYTHON_VERSION)
.for pv in ${PYTHON_VERSIONS_ACCEPTED}
.if defined(_PYTHON_VERSION_${pv}_INSTALLED)
_PYTHON_VERSION?=	${pv}
.else
# keep information as last resort - see below
_PYTHON_VERSION_FIRSTACCEPTED?=	${pv}
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
# set variables for the version we decided to use
#
.if ${_PYTHON_VERSION} == "21"
DEPENDS+=	python21>=2.1:../../lang/python21
PYTHONBIN=	${LOCALBASE}/bin/python2.1
PYPKGPREFIX=	py21
.elif ${_PYTHON_VERSION} == "20"
#DEPENDS+=	python20>=2.0:../../lang/python20
DEPENDS+=	python-2.0.1:../../lang/python
PYTHONBIN=	${LOCALBASE}/bin/python2.0
PYPKGPREFIX=	py20
.endif


#
# below is what used to be in bsd.python.mk
#

.if defined(PYBINMODULE)
.if ${MACHINE_ARCH} == "mips" || ${MACHINE_ARCH} == "vax"
IGNORE="${PKGNAME} needs dynamic loading"
.endif
.endif

.if exists(${PYTHONBIN})
PYINC!=	${PYTHONBIN} -c "import distutils.sysconfig; \
	print distutils.sysconfig.get_python_inc(0, \"\")"
PYSITELIB!=	${PYTHONBIN} -c "import distutils.sysconfig; \
		print distutils.sysconfig.get_python_lib(0, 0, \"\")"
.endif

.if defined(PYDISTUTILSPKG)
PYSETUP?=		setup.py
PYSETUPBUILDARGS?=	#empty
PYSETUPINSTALLARGS?=	#empty
PY_PATCHPLIST?=		yes

do-build:
	(cd ${WRKSRC} && ${PYTHONBIN} ${PYSETUP} ${PYSETUPBUILDARGS} build)

do-install:
	(cd ${WRKSRC} && ${PYTHONBIN} ${PYSETUP} ${PYSETUPINSTALLARGS} install)
.endif

.if defined(PY_PATCHPLIST)
PLIST_SUBST+=	PYINC=${PYINC} PYSITELIB=${PYSITELIB}
.endif
