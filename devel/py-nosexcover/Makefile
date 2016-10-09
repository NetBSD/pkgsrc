# $NetBSD: Makefile,v 1.1 2016/10/09 08:10:52 wiz Exp $

DISTNAME=	nosexcover-1.0.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/nosexcover/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/cmheisel/nose-xcover/
COMMENT=	Extends nose.plugins.cover to add Cobertura-style XML reports
#LICENSE=	BSD

DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose
DEPENDS+=	${PYPKGPREFIX}-coverage>=3.4:../../devel/py-coverage

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
