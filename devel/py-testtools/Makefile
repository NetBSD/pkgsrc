# $NetBSD: Makefile,v 1.14 2015/03/15 19:11:21 hiramatsu Exp $

DISTNAME=	testtools-1.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	https://pypi.python.org/packages/source/t/testtools/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/testing-cabal/testtools
COMMENT=	Extensions to the Python standard library unit testing framework
LICENSE=	mit AND python-software-foundation

DEPENDS+=	${PYPKGPREFIX}-extras-[0-9]*:../../devel/py-extras
DEPENDS+=	${PYPKGPREFIX}-python-mimeparse-[0-9]*:../../www/py-python-mimeparse
DEPENDS+=	${PYPKGPREFIX}-unittest2>=0.8.0:../../devel/py-unittest2

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
