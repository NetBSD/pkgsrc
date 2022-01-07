# $NetBSD: Makefile,v 1.4 2022/01/07 11:46:57 tnn Exp $

DISTNAME=	termcolor-1.1.0
PKGREVISION=	1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/termcolor/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/termcolor
COMMENT=	ANSI color output for terminals
LICENSE=	mit

USE_LANGUAGES=	# none

# No tests provided
do-test:
	${NADA}

.include "../../lang/python/egg.mk"
.if ${_PYTHON_VERSION} == 27
_PYSETUPTOOLSINSTALLARGS:=	${_PYSETUPTOOLSINSTALLARGS:N--single-version-externally-managed}
.endif
.include "../../mk/bsd.pkg.mk"
