# $NetBSD: bsd.python.mk,v 1.1.1.1 2001/05/14 13:41:32 drochner Exp $
#

.if defined(PYBINMODULE)
.if ${MACHINE_ARCH} == "powerpc" || ${MACHINE_ARCH} == "mips" || ${MACHINE_ARCH} == "vax"
IGNORE="${PKGNAME} needs dynamic loading"
.endif
.endif

PYINC!=	${PYTHON} -c "import distutils.sysconfig; \
	print distutils.sysconfig.get_python_inc(0, \"\")"
PYSITELIB!=	${PYTHON} -c "import distutils.sysconfig; \
		print distutils.sysconfig.get_python_lib(0, 0, \"\")"

.if defined(PYDISTUTILSPKG)
PYSETUP?=		setup.py
PYSETUPBUILDARGS?=	#empty
PYSETUPINSTALLARGS?=	#empty
PY_PATCHPLIST?=		yes

do-build:
	(cd ${WRKSRC} && ${PYTHON} ${PYSETUP} ${PYSETUPBUILDARGS} build)

do-install:
	(cd ${WRKSRC} && ${PYTHON} ${PYSETUP} ${PYSETUPINSTALLARGS} install)
.endif

PY_PLIST_TEMPLATE?=	${PKGDIR}/PLIST
PY_PLIST_SRC?=		${WRKDIR}/.PLIST_SRC

py_patchplist:
	${SED} "s|PYINC|${PYINC}|g;s|PYSITELIB|${PYSITELIB}|g" \
	<${PY_PLIST_TEMPLATE} >${PY_PLIST_SRC}

.if defined(PY_PATCHPLIST)
PLIST_SRC?=	${PY_PLIST_SRC}

pre-install: py_patchplist
.endif
