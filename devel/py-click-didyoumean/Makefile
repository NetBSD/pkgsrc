# $NetBSD: Makefile,v 1.2 2022/01/04 20:52:56 wiz Exp $

DISTNAME=	click-didyoumean-0.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/click-didyoumean/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/timofurrer/click-didyoumean
COMMENT=	Enable git-like did-you-mean feature in click
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-click-[0-9]*:../../devel/py-click

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
