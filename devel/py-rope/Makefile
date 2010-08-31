# $NetBSD: Makefile,v 1.2 2010/08/31 10:57:13 drochner Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_VERSIONS_ACCEPTED= 26 25

# XXX tests in contrib.codeassisttest fail
do-test:
	cd ${WRKSRC} && ${PYTHONBIN} setup.py test

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
