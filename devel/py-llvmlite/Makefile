# $NetBSD: Makefile,v 1.20 2022/01/04 20:53:15 wiz Exp $

DISTNAME=	llvmlite-0.36.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/llvmlite/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://llvmlite.readthedocs.io/
COMMENT=	Lightweight LLVM Python binding for writing JIT compilers
LICENSE=	2-clause-bsd

BROKEN=		"Does not compile with LLVM 12"

USE_LANGUAGES=	c++14
MAKE_ENV+=	LLVMLITE_SKIP_LLVM_VERSION_CHECK=1

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
