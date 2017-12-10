# $NetBSD: Makefile,v 1.1 2017/12/10 16:34:41 adam Exp $

DISTNAME=	confusable_homoglyphs-3.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	converters python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/confusable_homoglyphs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/vhf/confusable_homoglyphs
COMMENT=	Detect confusable usage of unicode homoglyphs
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-click-[0-9]*:../../devel/py-click

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
