# $NetBSD: Makefile,v 1.1.1.1 2010/08/15 10:34:56 drochner Exp $
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

# XXX tests in contrib.codeassisttest fail
do-test:
	cd ${WRKSRC} && ${PYTHONBIN} setup.py test

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
