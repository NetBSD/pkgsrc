# $NetBSD: Makefile.inc,v 1.3 2004/12/03 15:15:01 wiz Exp $
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

DEPENDS+=	python20-${PY_VERSION}*:../../lang/python20

BUILD_TARGET?=	default

.if ${MACHINE_ARCH} == "sparc64"
PKG_FAIL_REASON= "${PKGNAME} needs dynamic loading"
.endif

# Set PY_SETUP_SUBST to substitute "${variable}" for "@value@" in Setup.in.
PY_SETUP_SUBST+=	LOCALBASE=${LOCALBASE}
PY_SETUP_SUBST+=	X11BASE=${X11BASE}

# This is used for standard modules shipped with Python but build as
# separate packages.

python-std-do-configure:
	${SED} ${PY_SETUP_SUBST:S/=/@!/:S/$/!g/:S/^/ -e s!@/}		\
		${FILESDIR}/Setup.in > ${WRKSRC}/Setup.in
	( cd ${WRKSRC} ;\
	 ${CP} ${PY_CONFIGDIR}/Makefile.pre.in .;\
	 ${MAKE} -f Makefile.pre.in boot)
