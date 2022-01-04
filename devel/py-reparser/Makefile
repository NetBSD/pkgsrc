# $NetBSD: Makefile,v 1.2 2022/01/04 20:53:35 wiz Exp $

DISTNAME=	ReParser-1.4.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	1
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
