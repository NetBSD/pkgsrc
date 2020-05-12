# $NetBSD: Makefile,v 1.14 2020/05/12 08:08:08 adam Exp $

DISTNAME=	llvmlite-0.32.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/llvmlite/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://llvmlite.readthedocs.io/
COMMENT=	Lightweight LLVM Python binding for writing JIT compilers
LICENSE=	2-clause-bsd

USE_LANGUAGES=	c++14
MAKE_ENV+=	LLVMLITE_SKIP_LLVM_VERSION_CHECK=1

PYTHON_VERSIONS_INCOMPATIBLE=	27

pre-configure:
	${LN} -f ${WRKSRC}/ffi/Makefile.freebsd ${WRKSRC}/ffi/Makefile.netbsd

post-install:
.if ${OPSYS} == "Darwin"
	install_name_tool -id \
		${PREFIX}/${PYSITELIB}/llvmlite/binding/libllvmlite.dylib \
		${DESTDIR}${PREFIX}/${PYSITELIB}/llvmlite/binding/libllvmlite.dylib
.endif

BUILDLINK_API_DEPENDS.llvm+=	llvm>=10.0.0
.include "../../lang/llvm/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
