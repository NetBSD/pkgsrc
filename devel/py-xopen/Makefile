# $NetBSD: Makefile,v 1.3 2018/04/13 09:17:03 adam Exp $

DISTNAME=	xopen-0.3.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=x/xopen/}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/marcelm/xopen
COMMENT=	Open compressed files transparently
LICENSE=	mit

USE_LANGUAGES=	# none

# Python 2.7: requires bz2file

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
