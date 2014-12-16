# $NetBSD: Makefile,v 1.3 2014/12/16 07:00:52 obache Exp $

DISTNAME=	argh-0.26.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	https://pypi.python.org/packages/source/a/argh/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://github.com/neithere/argh/
COMMENT=	Unobtrusive argparse wrapper with natural syntax
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
PLIST_VARS+=	py26
.if !empty(_PYTHON_VERSION:M26)
DEPENDS+=	${PYPKGPREFIX}-argparse>=1.1:../../devel/py-argparse
PLIST.py26=	yes
.endif
.include "../../mk/bsd.pkg.mk"
