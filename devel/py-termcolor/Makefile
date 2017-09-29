# $NetBSD: Makefile,v 1.1 2017/09/29 14:07:49 joerg Exp $

DISTNAME=	termcolor-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/termcolor/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pypi.python.org/pypi/termcolor
COMMENT=	ANSI color output for terminals
LICENSE=	mit

USE_LANGUAGES=	# none

# No tests provided
do-test:
	${NADA}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
