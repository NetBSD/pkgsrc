# $NetBSD: Makefile,v 1.7 2023/10/28 19:57:06 wiz Exp $

DISTNAME=	termcolor-2.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/termcolor/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/termcolor
COMMENT=	ANSI color output for terminals
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs-[0-9]*:../../devel/py-hatch-vcs

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

# No tests provided
do-test:
	${NADA}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
