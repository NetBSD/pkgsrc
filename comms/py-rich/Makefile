# $NetBSD: Makefile,v 1.54 2025/09/22 07:38:44 wiz Exp $

DISTNAME=	rich-14.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	comms python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rich/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/willmcgugan/rich
COMMENT=	Render rich text, tables, progress bars, syntax highlighting
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=2.2.1:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-markdown-it-py>=2.2.0:../../textproc/py-markdown-it-py
DEPENDS+=	${PYPKGPREFIX}-pygments>=2.14.0:../../textproc/py-pygments

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
