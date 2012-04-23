# $NetBSD: Makefile,v 1.5 2012/04/23 12:23:39 obache Exp $
#

DISTNAME=	testtools-0.9.14
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://launchpad.net/testtools/0.9/${PKGVERSION_NOREV}/+download/ \
		http://launchpadlibrarian.net/93060290/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://launchpad.net/testtools
COMMENT=	Extensions to the Python standard library unit testing framework
LICENSE=	mit AND python-software-foundation

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
