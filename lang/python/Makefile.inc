# $NetBSD: Makefile.inc,v 1.1 2000/10/22 20:01:48 tsarna Exp $
#

PY_VERSION=	2.0
PY_DISTNAME=	BeOpen-Python-${PY_VERSION}
PY_MASTER_SITES=http://www.pythonlabs.com/products/python${PY_VERSION}/downloads/
DIST_SUBDIR?=	python

PY_WRKSRC=	${WRKDIR}/Python-${PY_VERSION}/Modules
PY_MODULES=	Python-${PY_VERSION}/Modules

PY_CONFIGDIR=	${LOCALBASE}/lib/python${PY_VERSION}/config
PY_LIBPATH=	lib/python${PY_VERSION}
PY_LIBDIR=	${LOCALBASE}/${PY_LIBPATH}
PY_SITEPATH=	${PY_LIBPATH}/site-packages
PY_SITEPKG=	${PY_LIBDIR}/site-packages
PY_PROG=	${LOCALBASE}/bin/python${PY_VERSION}
PY_INCDIR=	${LOCALBASE}/include/python${PY_VERSION}

PY_COMPILEDIR=	${PY_PROG} ${PY_LIBDIR}/compileall.py

DEPENDS+=	python-${PY_VERSION}*:../../lang/python

ALL_TARGET?=	default

.if ${MACHINE_ARCH} == "sparc64"
IGNORE="${PKGNAME} needs dynamic loading"
.endif

# This is used for standard modules shipped with Python but build as
# separate packages.

python-std-do-configure:
	${SED} -e 's%@LOCALBASE@%${LOCALBASE}%g' \
	-e 's%@X11BASE@%${X11BASE}%g' ${FILESDIR}/Setup.in \
	 >${WRKSRC}/Setup.in
	( cd ${WRKSRC} ;\
	 ${CP} ${PY_CONFIGDIR}/Makefile.pre.in .;\
	 ${MAKE} -f Makefile.pre.in boot)
