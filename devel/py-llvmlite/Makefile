# $NetBSD: Makefile,v 1.24 2022/08/15 19:14:43 wiz Exp $

DISTNAME=	llvmlite-0.38.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/llvmlite/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://llvmlite.readthedocs.io/
COMMENT=	Lightweight LLVM Python binding for writing JIT compilers
LICENSE=	2-clause-bsd

USE_LANGUAGES=	c++14

# https://github.com/numba/llvmlite/pull/802
BROKEN=		"No support for llvm 14 yet."

# officially supports llvm 11 as of 0.37.0
MAKE_ENV+=		LLVMLITE_SKIP_LLVM_VERSION_CHECK=1
# unable to pass LLVM bit-code files to linker
MAKE_ENV.NetBSD+=	CXX_FLTO_FLAGS=
MAKE_ENV.NetBSD+=	LD_FLTO_FLAGS=

PYTHON_VERSIONS_INCOMPATIBLE=	27

pre-configure:
	${SED} -e 's/ -stdlib=libc++//' ${WRKSRC}/ffi/Makefile.freebsd > ${WRKSRC}/ffi/Makefile.netbsd

.include "../../mk/bsd.prefs.mk"
post-install:
.if ${OPSYS} == "Darwin"
	install_name_tool -id \
		${PREFIX}/${PYSITELIB}/llvmlite/binding/libllvmlite.dylib \
		${DESTDIR}${PREFIX}/${PYSITELIB}/llvmlite/binding/libllvmlite.dylib
.endif

.include "../../lang/llvm/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
