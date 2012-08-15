# $NetBSD: Makefile,v 1.2 2012/08/15 05:50:11 dholland Exp $
#

DISTNAME=	stompclient-0.3.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/s/stompclient/

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	http://pypi.python.org/packages/source/s/stompclient/
COMMENT=	Lightweight and extensible STOMP messaging client
LICENSE=	apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	25

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
