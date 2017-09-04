# $NetBSD: Makefile,v 1.8 2017/09/04 18:08:25 wiz Exp $

DISTNAME=	roman-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=r/roman/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/roman/
COMMENT=	Integer to Roman numerals converter for Python
LICENSE=	python-software-foundation

CONFLICTS+=	${PYPKGPREFIX}-docutils<=0.7

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
