# $NetBSD: Makefile,v 1.6 2012/04/08 19:08:47 wiz Exp $
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

.include "../../lang/python/pyversion.mk"

.if defined(PYPKGPREFIX) && !empty(PYPKGPREFIX:Mpy25)
DEPENDS+=	${PYPKGPREFIX}-simplejson-[0-9]*:../../converters/py-simplejson
.endif

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
