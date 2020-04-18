# $NetBSD: Makefile,v 1.13 2020/04/18 08:11:53 adam Exp $

DISTNAME=	llvmlite-0.32.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/llvmlite/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://llvmlite.pydata.org/
COMMENT=	Lightweight LLVM Python binding for writing JIT compilers
LICENSE=	2-clause-bsd

USE_LANGUAGES=	c++14

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
DEPENDS+=	${PYPKGPREFIX}-enum34-[0-9]*:../../devel/py-enum34
.endif

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
