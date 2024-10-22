# $NetBSD: Makefile,v 1.50 2024/10/22 18:39:54 adam Exp $

DISTNAME=	rich-13.9.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	comms python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rich/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/willmcgugan/rich
COMMENT=	Render rich text, tables, progress bars, syntax highlighting
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=1.0.0:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-markdown-it-py>=2.2.0:../../textproc/py-markdown-it-py
DEPENDS+=	${PYPKGPREFIX}-pygments>=2.14.0:../../textproc/py-pygments

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
