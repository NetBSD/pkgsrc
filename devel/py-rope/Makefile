# $NetBSD: Makefile,v 1.5 2012/10/31 11:19:34 asau Exp $
#

VERS=		0.9.3
DISTNAME=	rope-${VERS}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/r/rope/

MAINTAINER=	helgoman@users.sourceforge.net
HOMEPAGE=	http://rope.sourceforge.net/
COMMENT=	Rope is a python refactoring library
LICENSE=	gnu-gpl-v2

# XXX tests in contrib.codeassisttest fail
do-test:
	cd ${WRKSRC} && ${PYTHONBIN} setup.py test

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
