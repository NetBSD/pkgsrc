# $NetBSD: Makefile,v 1.21 2022/01/11 07:00:27 adam Exp $

DISTNAME=	rich-11.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	comms python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rich/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/willmcgugan/rich
COMMENT=	Render rich text, tables, progress bars, syntax highlighting
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-colorama>=0.4.0:../../comms/py-colorama
DEPENDS+=	${PYPKGPREFIX}-commonmark>=0.9.0:../../textproc/py-commonmark
DEPENDS+=	${PYPKGPREFIX}-pygments>=2.6.0:../../textproc/py-pygments

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} < 38
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=3.7.4:../../devel/py-typing-extensions
.endif

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
