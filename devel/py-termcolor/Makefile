# $NetBSD: Makefile,v 1.6 2023/04/25 14:02:40 wiz Exp $

DISTNAME=	termcolor-2.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
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
