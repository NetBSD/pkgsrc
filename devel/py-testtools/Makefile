# $NetBSD: Makefile,v 1.3 2011/10/07 10:45:06 obache Exp $
#

DISTNAME=	testtools-0.9.12
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://launchpad.net/testtools/0.9/${PKGVERSION_NOREV}/+download/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://launchpad.net/testtools
COMMENT=	Extensions to the Python standard library unit testing framework
LICENSE=	mit AND python-software-foundation

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	24

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
