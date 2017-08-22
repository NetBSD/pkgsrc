# $NetBSD: Makefile,v 1.21 2017/08/22 08:16:44 adam Exp $

DISTNAME=	Babel-2.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=B/Babel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://babel.pocoo.org/
COMMENT=	Collection of tools for internationalizing Python applications
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} pybabel pybabel-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
