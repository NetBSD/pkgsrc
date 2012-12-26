# $NetBSD: Makefile,v 1.3 2012/12/26 21:30:05 dholland Exp $
#

DISTNAME=	ipython-0.13.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel lang
MASTER_SITES=	http://archive.ipython.org/release/0.13.1/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://ipython.org/
COMMENT=	Interactive computing environment for Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-readline-[0-9]*:../../devel/py-readline

PYTHON_VERSIONS_INCOMPATIBLE=	25
#PYTHON_VERSIONS_INCLUDE_3X=	yes

USE_LANGUAGES=	# none
USE_TOOLS+=	gunzip

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
