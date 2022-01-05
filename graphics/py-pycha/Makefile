# $NetBSD: Makefile,v 1.22 2022/01/05 15:41:11 wiz Exp $

DISTNAME=	pycha-0.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pycha/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucket.org/lgs/pycha/
COMMENT=	Library for making charts with Python
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-cairocffi-[0-9]*:../../graphics/py-cairocffi
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=	#none

USE_PKG_RESOURCES=	yes

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/chavier ${DESTDIR}${PREFIX}/bin/chavier-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
