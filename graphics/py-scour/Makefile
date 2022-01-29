# $NetBSD: Makefile,v 1.4 2022/01/29 07:36:00 wiz Exp $

DISTNAME=	scour-0.38.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/scour/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/scour-project/scour
COMMENT=	Scour SVG Optimizer
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-six>=1.15.0:../../lang/py-six

USE_PKG_RESOURCES=	yes

USE_LANGUAGES=	# none

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/scour \
		${DESTDIR}${PREFIX}/bin/scour-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
