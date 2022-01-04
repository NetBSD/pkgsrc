# $NetBSD: Makefile,v 1.13 2022/01/04 20:52:49 wiz Exp $

.include "version.mk"

DISTNAME=	angr-${ANGR_VERSION}
PKGNAME=	${PYPKGPREFIX}-${EGG_NAME}
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=angr/}
GITHUB_PROJECT=	angr
GITHUB_TAG=	v${ANGR_VERSION}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/angr/angr/
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

USE_LANGUAGES+=	c c++
USE_TOOLS+=	gmake

MAKE_FLAGS+=	LIBDIR=${LIBDIR:Q}
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/${PYSITELIB:Q}/pyvex/lib

DEPENDS+=	${PYPKGPREFIX}-CppHeaderParser-[0-9]*:../../devel/py-CppHeaderParser
DEPENDS+=	${PYPKGPREFIX}-ailment>=${ANGR_VERSION}:../../devel/py-ailment
DEPENDS+=	${PYPKGPREFIX}-archinfo>=${ANGR_VERSION}:../../devel/py-archinfo
DEPENDS+=	${PYPKGPREFIX}-cachetools-[0-9]*:../../devel/py-cachetools
DEPENDS+=	${PYPKGPREFIX}-capstone>=4.0.2:../../devel/py-capstone
DEPENDS+=	${PYPKGPREFIX}-cffi-[0-9]*:../../devel/py-cffi
DEPENDS+=	${PYPKGPREFIX}-claripy>=${ANGR_VERSION}:../../math/py-claripy
DEPENDS+=	${PYPKGPREFIX}-cle>=${ANGR_VERSION}:../../devel/py-cle
DEPENDS+=	${PYPKGPREFIX}-cparser-[0-9]*:../../devel/py-cparser
DEPENDS+=	${PYPKGPREFIX}-dpkt-[0-9]*:../../net/py-dpkt
DEPENDS+=	${PYPKGPREFIX}-gitpython-[0-9]*:../../devel/py-gitpython
DEPENDS+=	${PYPKGPREFIX}-itanium_demangler-[0-9]*:../../devel/py-itanium_demangler
DEPENDS+=	${PYPKGPREFIX}-mulpyplexer-[0-9]*:../../devel/py-mulpyplexer
DEPENDS+=	${PYPKGPREFIX}-networkx-[0-9]*:../../math/py-networkx
DEPENDS+=	${PYPKGPREFIX}-progressbar2-[0-9]*:../../devel/py-progressbar2
DEPENDS+=	${PYPKGPREFIX}-protobuf-[0-9]*:../../devel/py-protobuf
DEPENDS+=	${PYPKGPREFIX}-psutil-[0-9]*:../../sysutils/py-psutil
DEPENDS+=	${PYPKGPREFIX}-pyvex>=${ANGR_VERSION}:../../devel/py-pyvex
DEPENDS+=	${PYPKGPREFIX}-rpyc-[0-9]*:../../net/py-rpyc
DEPENDS+=	${PYPKGPREFIX}-sortedcontainers-[0-9]*:../../devel/py-sortedcontainers
DEPENDS+=	${PYPKGPREFIX}-unicorn-[0-9]*:../../emulators/py-unicorn

PYTHON_VERSIONS_INCOMPATIBLE=	27

OPSYSVARS+=	SOEXT
SOEXT.Darwin=	dylib
SOEXT.*=	so
PLIST_SUBST+=	SOEXT=${SOEXT}

TEST_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose

do-test:
	${RUN} cd ${WRKSRC} && \
	${SETENV} ${TEST_ENV} \
	${PYTHONBIN} -m nose

.include "../../devel/py-pyvex/buildlink3.mk"
.include "../../emulators/unicorn/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
