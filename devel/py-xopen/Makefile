# $NetBSD: Makefile,v 1.4 2018/07/06 08:02:53 adam Exp $

DISTNAME=	xopen-0.3.5
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
