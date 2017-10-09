# $NetBSD: Makefile,v 1.2 2017/10/09 08:46:25 wiz Exp $

DISTNAME=	termcolor-1.1.0
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

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
