# $NetBSD: Makefile,v 1.4 2023/03/29 09:34:04 wiz Exp $

DISTNAME=	pickleshare-0.7.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	databases devel
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pickleshare/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/pickleshare/pickleshare
COMMENT=	Tiny shelve-like database with concurrency support
LICENSE=	mit

.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} == 207
DEPENDS+=       ${PYPKGPREFIX}-pathlib2-[0-9]*:../../devel/py-pathlib2
.endif

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
