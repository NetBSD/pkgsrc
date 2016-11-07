# $NetBSD: Makefile,v 1.2 2016/11/07 11:12:27 wiz Exp $

DISTNAME=	nosexcover-1.0.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/nosexcover/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/cmheisel/nose-xcover/
COMMENT=	Extends nose.plugins.cover to add Cobertura-style XML reports
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose
DEPENDS+=	${PYPKGPREFIX}-coverage>=3.4:../../devel/py-coverage

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
