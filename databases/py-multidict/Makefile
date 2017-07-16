# $NetBSD: Makefile,v 1.1 2017/07/16 09:37:09 adam Exp $

DISTNAME=	multidict-3.1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/multidict/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aio-libs/multidict/
COMMENT=	Multidict implementation
LICENSE=	apache-2.0

BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=		c

post-extract:
	${RM} ${WRKSRC}/multidict/_istr.cpython-35m-x86_64-linux-gnu.so

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
