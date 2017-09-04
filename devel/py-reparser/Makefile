# $NetBSD: Makefile,v 1.1 2017/09/04 13:39:56 leot Exp $

DISTNAME=	ReParser-1.4.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/reparser/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/xmikos/reparser
COMMENT=	Simple regex-based lexer/parser for inline markup
LICENSE=	mit

USE_LANGUAGES=			# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
