# $NetBSD: Makefile,v 1.18 2020/12/31 00:13:48 mef Exp $

DISTNAME=	llvmlite-0.34.0
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
#	${LN} -f ${WRKSRC}/ffi/Makefile.freebsd ${WRKSRC}/ffi/Makefile.netbsd
	${SED} -e 's/ -stdlib=libc++//'   ${WRKSRC}/ffi/Makefile.freebsd > ${WRKSRC}/ffi/Makefile.netbsd

.include "../../mk/bsd.prefs.mk"
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
