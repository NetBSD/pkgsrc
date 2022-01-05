# $NetBSD: Makefile,v 1.3 2022/01/05 15:41:12 wiz Exp $

DISTNAME=	scour-0.38.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/scour/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/scour-project/scour
COMMENT=	Scour SVG Optimizer
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-six>=1.15.0:../../lang/py-six

USE_PKG_RESOURCES=	yes

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
