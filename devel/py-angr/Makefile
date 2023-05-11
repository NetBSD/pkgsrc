# $NetBSD: Makefile,v 1.14 2023/05/11 07:21:34 adam Exp $

.include "version.mk"

DISTNAME=	angr-${ANGR_VERSION}
PKGNAME=	${PYPKGPREFIX}-${EGG_NAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/angr/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/angr/angr
COMMENT=	Platform-agnostic binary analysis framework
LICENSE=	2-clause-bsd

# Needed for the automatic tests, but I got bored trying to make them
# work.  Here's the partial effort, at least.
#
# BINARIES_TAG=	f517c1ae88f4a9ccf19f5c90ff1519827df0157c
# BINARIES_DIST=	angr-binaries-${BINARIES_TAG}.tar.gz
# SITES.${BINARIES_DIST}=	-${MASTER_SITES:=binaries/archive/${BINARIES_TAG}.tar.gz}

# DISTFILES=	${DEFAULT_DISTFILES}
# DISTFILES+=	${BINARIES_DIST}

# post-extract:
# 	${RUN} cd ${WRKDIR} && \
# 	${MV} -f binaries-${BINARIES_TAG} binaries

MAKE_FLAGS+=	LIBDIR=${LIBDIR:Q}
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/${PYSITELIB:Q}/pyvex/lib

DEPENDS+=	${PYPKGPREFIX}-CppHeaderParser-[0-9]*:../../devel/py-CppHeaderParser
DEPENDS+=	${PYPKGPREFIX}-ailment>=${ANGR_VERSION}:../../devel/py-ailment
DEPENDS+=	${PYPKGPREFIX}-archinfo>=${ANGR_VERSION}:../../devel/py-archinfo
DEPENDS+=	${PYPKGPREFIX}-cachetools-[0-9]*:../../devel/py-cachetools
DEPENDS+=	${PYPKGPREFIX}-capstone>=4.0.2:../../devel/py-capstone
DEPENDS+=	${PYPKGPREFIX}-cffi>=1.14.0:../../devel/py-cffi
DEPENDS+=	${PYPKGPREFIX}-claripy>=${ANGR_VERSION}:../../math/py-claripy
DEPENDS+=	${PYPKGPREFIX}-cle>=${ANGR_VERSION}:../../devel/py-cle
DEPENDS+=	${PYPKGPREFIX}-cparser>=2.18:../../devel/py-cparser
DEPENDS+=	${PYPKGPREFIX}-dpkt-[0-9]*:../../net/py-dpkt
DEPENDS+=	${PYPKGPREFIX}-gitpython-[0-9]*:../../devel/py-gitpython
DEPENDS+=	${PYPKGPREFIX}-itanium_demangler-[0-9]*:../../devel/py-itanium_demangler
DEPENDS+=	${PYPKGPREFIX}-mulpyplexer-[0-9]*:../../devel/py-mulpyplexer
DEPENDS+=	${PYPKGPREFIX}-nampa-[0-9]*:../../devel/py-nampa
DEPENDS+=	${PYPKGPREFIX}-networkx>=2.8.2:../../math/py-networkx
DEPENDS+=	${PYPKGPREFIX}-protobuf>=3.19.0:../../devel/py-protobuf
DEPENDS+=	${PYPKGPREFIX}-psutil-[0-9]*:../../sysutils/py-psutil
DEPENDS+=	${PYPKGPREFIX}-pyvex>=${ANGR_VERSION}:../../devel/py-pyvex
DEPENDS+=	${PYPKGPREFIX}-rich>=13.1.0:../../comms/py-rich
DEPENDS+=	${PYPKGPREFIX}-rpyc-[0-9]*:../../net/py-rpyc
DEPENDS+=	${PYPKGPREFIX}-sortedcontainers-[0-9]*:../../devel/py-sortedcontainers
DEPENDS+=	${PYPKGPREFIX}-sympy-[0-9]*:../../math/py-sympy
DEPENDS+=	${PYPKGPREFIX}-unicorn>=2.0.1:../../emulators/py-unicorn

USE_LANGUAGES+=	c c++
USE_TOOLS+=	gmake

PYTHON_VERSIONS_INCOMPATIBLE=	27

OPSYSVARS+=	SOEXT
SOEXT.Darwin=	dylib
SOEXT.*=	so
PLIST_SUBST+=	SOEXT=${SOEXT}

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
post-install:
	install_name_tool -id ${PREFIX}/${PYSITELIB}/angr/lib/angr_native.dylib \
	${DESTDIR}${PREFIX}/${PYSITELIB}/angr/lib/angr_native.dylib
.endif

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m unittest tests/*.py

.include "../../devel/py-pyvex/buildlink3.mk"
.include "../../emulators/unicorn/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
