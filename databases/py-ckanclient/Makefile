# $NetBSD: Makefile,v 1.3 2011/10/14 04:47:34 obache Exp $
#

DISTNAME=	ckanclient-0.9
PKGNAME=	${PYPKGPREFIX}-ckanclient-0.9
CATEGORIES=	databases
MASTER_SITES=	http://pypi.python.org/packages/source/c/ckanclient/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ckan.org/
COMMENT=	Open-source data portal software
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	24

.include "../../lang/python/pyversion.mk"

.if ${PYPKGPREFIX} == py25
DEPENDS+=	${PYPKGPREFIX}-simplejson-[0-9]*:../../converters/py-simplejson
.endif

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
