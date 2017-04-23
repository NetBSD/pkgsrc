# $NetBSD: Makefile,v 1.1 2017/04/23 03:38:51 markd Exp $

DISTNAME=	pickleshare-0.7.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases devel
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pickleshare/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/pickleshare/pickleshare
COMMENT=	Tiny shelve-like database with concurrency support
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
