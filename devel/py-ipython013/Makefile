# $NetBSD: Makefile,v 1.6 2013/10/29 18:18:46 drochner Exp $
#

DISTNAME=	ipython-0.13.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel lang
MASTER_SITES=	http://archive.ipython.org/release/0.13.2/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ipython.org/
COMMENT=	Interactive computing environment for Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-readline-[0-9]*:../../devel/py-readline

#PYTHON_VERSIONS_INCLUDE_3X=	yes

USE_LANGUAGES=	# none
USE_TOOLS+=	gunzip

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
