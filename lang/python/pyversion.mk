# $NetBSD: pyversion.mk,v 1.175 2025/10/05 22:43:14 wiz Exp $

# This file provides an interface to decide which version of python
# should be used in building a package.  It should be directly
# included by packages as a way to depend on python when none of the
# other methods are appropriate, e.g. a package that produces a binary
# that embeds python.  It is indirectly included by the other methods.
#
# There are three kinds of python versions:
#   - 2.7: Very old, and only usable if explicitly marked as supported.
#   - old 3.x: Usable if explicitly marked as supported and requested,
#     but not part of defaults because too many packages fail,
#     and it's painful for no gain to have to explicitly exclude it.
#   - current 3.x: Usable unless a package is specifically marked.
#     Includes the default version, older versions not yet too
#     troublesome, and often a version newer than default.
#
# The value of "current 3.x" is defined by the default value of
# PYTHON_VERSIONS_ACCEPTED.
#
# For any given package, there are a set of python3 versions that one
# can use with the upstream code, and perhaps a reduced version that
# pkgsrc chooses to use, often due to dependencies in pkgsrc not
# supporting an older version.  The set of versions is expressed in
# one of several ways, but not a mixture:
#  - No variables set, meaning that the supported versions are exactly
#    those in the default value of PYTHON_VERSIONS_ACCEPTED.
#  - PYTHON_VERSIONS_ACCEPTED set, meaning that is the set of
#    buildable versions.  This can include values not in the default,
#    and it can omit values in the default.
#  - PYTHON_VERSIONS_INCOMPATIBLE set, meaning that the set of
#    buildable versions is the default value of
#    PYTHON_VERSIONS_ACCEPTED, minus the INCOMPATIBLE versions.  This
#    is preferred when omitting a specific old or new version, so that
#    as versions are added and removed from DEFAULT, the set updates.
# NB: If a version is in the ACCEPTED set, that version must also be
# in the ACCEPTED set of every (recursive) dependency.
#
# The general plan for version selection (ignoring 2.7) is:
#   - If PYTHON_VERSION_REQD is set, choose it (and fail if not in
#       PYTHON_VERSIONS_ACCEPTED).
#   - If PYTHON_VERSION_DEFAULT is in PYTHON_VERSIONS_ACCEPTED, choose
#     it.
#   - Otherwise, choose the first version in PYTHON_VERSIONS_ACCEPTED.
#
# With 2.7, 27 is considered included in PYTHON_VERSIONS_ACCEPTED if
# PYTHON_27_ACCEPTED is defined.  If so, then:
#   - If PYTHON_VERSION_REQD is 27, 27 is used.
#   - If PYTHON_VERSION_DEFAULT is not in PYTHON_VERSIONS_ACCEPTED,
#     then the highest version in ACCEPTED is chosen.  (For a package
#     that supports only 27, this will be 27.)
#
# === User-settable variables ===
#
# PYTHON_VERSION_DEFAULT
#	The preferred Python version to use.  Typical use is to move
#	to a newer version before pkgsrc moves.  Another possible use
#	is to stay on an older version when pkgsrc advances.
#	
#	Reasonable values: Default value of PYTHON_VERSIONS_ACCEPTED.
#	Possible values: Reasonable values and "old 3.x".
#	Default: 313
#
# === Infrastructure variables ===
#
# PYTHON_VERSION_REQD
#	Python version to use. This variable should not be set by the
#	user or in packages.  Normally it is used by bulk build tools,
#	or e.g. as "make PYTHON_VERSION_REQD=311 replace".
#
#	Possible: ${PYTHON_VERSIONS_ACCEPTED}
#	Default:  ${PYTHON_VERSION_DEFAULT}
#
# === Package-settable variables ===
#
# PYTHON_VERSIONS_ACCEPTED
#	The Python versions that can be used to build the package.
#	Order is significant, with the first feasible value chosen;
#	normal practice is to list all feasible versions in decreasing
#	order.
#
#	Possible values: 313 312 311
#	Default: 313 312 311
#
# PYTHON_27_ACCEPTED
#       Set if the package can build with 2.7.  (27 should not be
#       placed in PYTHON_VERSIONS_ACCEPTED.)
#
# PYTHON_VERSIONS_INCOMPATIBLE
#	The Python versions that cannot be used to build the package.
#	Any "current 3.x" version that fails to build and work must be
#	listed.  "Old 3.x" versions may be listed, and if present
#	should not be pruned (as long as the old lang/pythonNN version
#	is in pkgsrc).  However it is not a consequential error if it
#	is missing, as those are not built by default in bulk builds.
#	(27 should not be listed as incompatible, as that's true
#	unless PYTHON_27_ACCEPTED is set.)
#
#	Possible values: 39 310 311 312 313
#	Default: (empty)
#
# PYTHON_FOR_BUILD_ONLY
#	Whether Python is needed only at build time or at run time.
#
#	Possible values: yes no test tool
#	Default: no
#
# PYTHON_SELF_CONFLICT
#	If set to "yes", additional CONFLICTS entries are added for
#	registering a conflict between pyNN-<modulename> packages,
#	covering all versions.  (Expressing CONFLICTS that are limited
#	to some versions must be done with a hand-written CONFLICTS
#	entry.)
#
#	Possible values: yes no
#	Default: no
#
# === Defined variables ===
#
# PYTHON_VERSION
#	Version of python that will be used in this build, as
#	a three-digit number of major_version * 100 + minor_version.
#
#	Examples: 207, 309, 310, 311, 312, 313
#
# PYPKGPREFIX
#	The prefix to use in PKGNAME for extensions which are meant
#	to be installed for multiple Python versions.
#
#	Example: py313
#
# PYVERSSUFFIX
#	The suffix to executables and in the library path, equal to
#	sys.version[0:3].
#
#	Example: 3.13
#
# Keywords: python
#

.if !defined(PYTHON_PYVERSION_MK)
PYTHON_PYVERSION_MK=	defined

# derive a python version from the package name if possible
# optionally handled quoted package names
.if defined(PKGNAME_REQD) && !empty(PKGNAME_REQD:Mpy[0-9][0-9]-*) || \
    defined(PKGNAME_REQD) && !empty(PKGNAME_REQD:M*-py[0-9][0-9]-*)
PYTHON_VERSION_REQD?=	${PKGNAME_REQD:C/(^.*-|^)py([0-9][0-9])-.*/\2/}
.elif defined(PKGNAME_REQD) && !empty(PKGNAME_REQD:Mpy[0-9][0-9][0-9]-*) || \
    defined(PKGNAME_REQD) && !empty(PKGNAME_REQD:M*-py[0-9][0-9][0-9]-*)
PYTHON_VERSION_REQD?=	${PKGNAME_REQD:C/(^.*-|^)py([0-9][0-9][0-9])-.*/\2/}
.elif defined(PKGNAME_OLD) && !empty(PKGNAME_OLD:Mpy[0-9][0-9]-*) || \
      defined(PKGNAME_OLD) && !empty(PKGNAME_OLD:M*-py[0-9][0-9]-*)
PYTHON_VERSION_REQD?=	${PKGNAME_OLD:C/(^.*-|^)py([0-9][0-9])-.*/\2/}
.elif defined(PKGNAME_OLD) && !empty(PKGNAME_OLD:Mpy[0-9][0-9][0-9]-*) || \
      defined(PKGNAME_OLD) && !empty(PKGNAME_OLD:M*-py[0-9][0-9][0-9]-*)
PYTHON_VERSION_REQD?=	${PKGNAME_OLD:C/(^.*-|^)py([0-9][0-9][0-9])-.*/\2/}
.endif

.include "../../mk/bsd.fast.prefs.mk"

BUILD_DEFS+=		PYTHON_VERSION_DEFAULT
BUILD_DEFS_EFFECTS+=	PYPACKAGE

PYTHON_VERSION_DEFAULT?=		313
PYTHON_VERSIONS_ACCEPTED?=		313 312 311
.if defined(PYTHON_27_ACCEPTED)
PYTHON_VERSIONS_ACCEPTED+=		27
.endif
PYTHON_VERSIONS_INCOMPATIBLE?=		# empty by default

# transform the list into individual variables
.for pv in ${PYTHON_VERSIONS_ACCEPTED}
.  if empty(PYTHON_VERSIONS_INCOMPATIBLE:M${pv})
_PYTHON_VERSION_${pv}_OK=	yes
_PYTHON_VERSIONS_ACCEPTED+=	${pv}
.  endif
.endfor

#
# choose a python version where to add,
# try to be intelligent
#
# if a version is explicitly required, take it
.if defined(PYTHON_VERSION_REQD)
# but check if it is acceptable first, error out otherwise
.  if defined(_PYTHON_VERSION_${PYTHON_VERSION_REQD}_OK)
_PYTHON_VERSION=	${PYTHON_VERSION_REQD}
.  endif
.else
# if the default is accepted, it is first choice
.  if !defined(_PYTHON_VERSION)
.    if defined(_PYTHON_VERSION_${PYTHON_VERSION_DEFAULT}_OK)
_PYTHON_VERSION=	${PYTHON_VERSION_DEFAULT}
.    endif
.  endif
# prefer an already installed version, in order of "accepted"
.  if !defined(_PYTHON_VERSION)
.    for pv in ${PYTHON_VERSIONS_ACCEPTED}
.      if defined(_PYTHON_VERSION_${pv}_OK)
_PYTHON_VERSION?=	${pv}
.      endif
.    endfor
.  endif
.endif

#
# Variable assignment for multi-python packages
MULTI+=	PYTHON_VERSION_REQD=${_PYTHON_VERSION}

# No supported version found, annotate to simplify statements below.
.if !defined(_PYTHON_VERSION)
_PYTHON_VERSION=	none
# since no supported version is found and no build will happen,
# choose a numeric default
PYTHON_VERSION=		0
PKG_FAIL_REASON+=	"No valid Python version"
PYPKGPREFIX=		none
PYVERSSUFFIX=		none
.else
PYTHON_VERSION=		${_PYTHON_VERSION:C/^(.)(.)$/\10\2/}
.endif

# Additional CONFLICTS
.if ${PYTHON_SELF_CONFLICT:U:tl} == "yes"
.  for i in ${PYTHON_VERSIONS_ACCEPTED:N${_PYTHON_VERSION}}
.    if empty(PYTHON_VERSIONS_INCOMPATIBLE:M${i})
CONFLICTS+=	${PKGNAME:S/py${_PYTHON_VERSION}/py${i}/:C/-[0-9].*$/-[0-9]*/}
.    endif
.  endfor
.endif # PYCONFLICTS

#
PLIST_VARS+=	py2x py3x

.if empty(_PYTHON_VERSION:Mnone)
PYPACKAGE=				python${_PYTHON_VERSION}
PYVERSSUFFIX=				${_PYTHON_VERSION:C/^([0-9])/\1./1}
BUILDLINK_API_DEPENDS.${PYPACKAGE}?=	${PYPACKAGE}>=${PYVERSSUFFIX}
PYPKGSRCDIR=				../../lang/${PYPACKAGE}
PYDEPENDENCY=				${BUILDLINK_API_DEPENDS.${PYPACKAGE}:=:${PYPKGSRCDIR}}
PYPKGPREFIX=				py${_PYTHON_VERSION}
.endif
.if !empty(_PYTHON_VERSION:M3*)
PLIST.py3x=				yes
.endif
.if !empty(_PYTHON_VERSION:M2*)
PLIST.py2x=				yes
.endif

PTHREAD_OPTS+=	require
.include "../../mk/pthread.buildlink3.mk"

PYTHON_FOR_BUILD_ONLY?=		no
.if defined(PYPKGSRCDIR)
.  if !empty(PYTHON_FOR_BUILD_ONLY:M[tT][oO][oO][lL])
TOOL_DEPENDS+=			${PYDEPENDENCY}
.  elif !empty(PYTHON_FOR_BUILD_ONLY:M[tT][eE][sS][tT])
TEST_DEPENDS+=			${PYDEPENDENCY}
.  else
.    if !empty(PYTHON_FOR_BUILD_ONLY:M[yY][eE][sS])
BUILDLINK_DEPMETHOD.python?=	build
.    else
BUILDLINK_DEPMETHOD.python?=	full
.    endif
.    include "${PYPKGSRCDIR}/buildlink3.mk"
.    if ${USE_CROSS_COMPILE:tl} == "yes"
TOOL_DEPENDS+=			${PYDEPENDENCY}
MAKE_ENV+=			PYTHONPATH=${WRKDIR:Q}/.pysite:${_CROSS_DESTDIR:Q}${LOCALBASE:Q}/${PYLIB:Q}
pre-configure: ${WRKDIR}/.pysite/sitecustomize.py
.include "${PYPKGSRCDIR}/platname.mk"
${WRKDIR}/.pysite/sitecustomize.py:
	@${STEP_MSG} "Creating Python sitecustomize.py for cross-compiling"
	${RUN} ${MKDIR} ${.TARGET:H}
	${RUN} ( \
		${ECHO} "import sys" && \
		${PRINTF} "sys.platform = '%s'\\n" ${PY_PLATNAME:Q} && \
		for v in \
			sys.base_exec_prefix \
			sys.base_prefix \
			sys.exec_prefix \
			sys.prefix \
		; do \
			${PRINTF} "%s = '%s'\\n" "$$v" ${LOCALBASE:Q}; \
		done; \
	) >${.TARGET}.tmp
	${RUN} ${MV} -f ${.TARGET}.tmp ${.TARGET}
.    endif
.  endif
.endif

PYTHONBIN=	${LOCALBASE}/bin/python${PYVERSSUFFIX}
TOOL_PYTHONBIN=	${TOOLBASE}/bin/python${PYVERSSUFFIX}
.if exists(${TOOL_PYTHONBIN}m)
PYTHONCONFIG=	${TOOLBASE}/bin/python${PYVERSSUFFIX}m-config
.else
PYTHONCONFIG=	${TOOLBASE}/bin/python${PYVERSSUFFIX}-config
.endif
PY_COMPILE_ALL= \
	${TOOL_PYTHONBIN} ${PREFIX}/lib/python${PYVERSSUFFIX}/compileall.py -q
PY_COMPILE_O_ALL= \
	${TOOL_PYTHONBIN} -O ${PREFIX}/lib/python${PYVERSSUFFIX}/compileall.py -q

PYINC=		include/python${PYVERSSUFFIX}
PYLIB=		lib/python${PYVERSSUFFIX}
PYSITELIB=	${PYLIB}/site-packages

# Expect paths directly under PREFIX, but allow for ${PLIST.*} prefix(es)
PRINT_PLIST_AWK+=	/(^|^\$$.+\})${PYINC:S|/|\\/|g}/ \
			{ gsub(/${PYINC:S|/|\\/|g}/, "$${PYINC}") }
PRINT_PLIST_AWK+=	/(^|^\$$.+\})${PYSITELIB:S|/|\\/|g}/ \
			{ gsub(/${PYSITELIB:S|/|\\/|g}/, "$${PYSITELIB}") }
PRINT_PLIST_AWK+=	/(^|^\$$.+\})${PYLIB:S|/|\\/|g}/ \
			{ gsub(/${PYLIB:S|/|\\/|g}/, "$${PYLIB}") }

ALL_ENV+=		PYTHON=${TOOL_PYTHONBIN}
.if defined(USE_CMAKE) || defined(BUILD_USES_CMAKE)
# used by FindPython
CMAKE_CONFIGURE_ARGS+=		-DPython_EXECUTABLE:FILEPATH=${TOOL_PYTHONBIN}
CMAKE_CONFIGURE_ARGS+=		-DPython_INCLUDE_DIR:PATH=${BUILDLINK_DIR}/${PYINC}
# used by FindPython2
.  if !empty(_PYTHON_VERSION:M2*)
CMAKE_CONFIGURE_ARGS+=		-DPython2_EXECUTABLE:FILEPATH=${TOOL_PYTHONBIN}
CMAKE_CONFIGURE_ARGS+=		-DPython2_INCLUDE_DIR:PATH=${BUILDLINK_DIR}/${PYINC}
.  endif
# used by FindPython3
.  if !empty(_PYTHON_VERSION:M3*)
CMAKE_CONFIGURE_ARGS+=		-DPython3_EXECUTABLE:FILEPATH=${TOOL_PYTHONBIN}
CMAKE_CONFIGURE_ARGS+=		-DPython3_INCLUDE_DIR:PATH=${BUILDLINK_DIR}/${PYINC}
.  endif
# used by FindPythonInterp.cmake and FindPythonLibs.cmake
CMAKE_CONFIGURE_ARGS+=		-DPYVERSSUFFIX:STRING=${PYVERSSUFFIX}
# set this explicitly, as by default it will prefer the built in framework
# on Darwin
CMAKE_CONFIGURE_ARGS+=		-DPYTHON_INCLUDE_DIR:PATH=${BUILDLINK_DIR}/${PYINC}
CMAKE_CONFIGURE_ARGS+=		-DPYTHON_INCLUDE_PATH:PATH=${BUILDLINK_DIR}/${PYINC}
CMAKE_CONFIGURE_ARGS+=		-DPYTHON_EXECUTABLE:FILEPATH=${TOOL_PYTHONBIN}
.endif

_VARGROUPS+=		pyversion
_USER_VARS.pyversion=	PYTHON_VERSION_DEFAULT
_PKG_VARS.pyversion=	\
	PYTHON_VERSIONS_ACCEPTED PYTHON_VERSIONS_INCOMPATIBLE		\
	PYTHON_SELF_CONFLICT PYTHON_FOR_BUILD_ONLY USE_CMAKE BUILD_USES_CMAKE
_SYS_VARS.pyversion=	\
	PYTHON_VERSION PYTHON_VERSION_REQD PYPACKAGE PYVERSSUFFIX	\
	PYPKGSRCDIR PYPKGPREFIX PYTHONBIN PYTHONCONFIG PY_COMPILE_ALL	\
	PY_COMPILE_O_ALL PYINC PYLIB PYSITELIB CMAKE_CONFIGURE_ARGS		\
	TOOL_PYTHONBIN
_USE_VARS.pyversion=	\
	PKGNAME_REQD PKGNAME_OLD LOCALBASE PREFIX BUILDLINK_DIR PKGNAME
_DEF_VARS.pyversion=	\
	CONFLICTS MULTI PLIST_VARS BUILDLINK_API_DEPENDS.${PYPACKAGE}	\
	PYDEPENDENCY PLIST.py2x PLIST.py3x PTHREAD_OPTS TOOL_DEPENDS	\
	TEST_DEPENDS BUILDLINK_DEPMETHOD.python PRINT_PLIST_AWK ALL_ENV	\
	_PYTHON_VERSIONS_ACCEPTED _PYTHON_VERSION
_IGN_VARS.pyversion=	_PYTHON_*
_LISTED_VARS.pyversion=	*_ARGS
_SORTED_VARS.pyversion=	*_DEPENDS *_ENV

.endif	# PYTHON_PYVERSION_MK
