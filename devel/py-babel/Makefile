# $NetBSD: Makefile,v 1.24 2018/04/04 11:00:56 fhajny Exp $

DISTNAME=	Babel-2.5.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=B/Babel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://babel.pocoo.org/
COMMENT=	Collection of tools for internationalizing Python applications
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz

USE_LANGUAGES=	# none

post-extract:
	cd ${WRKSRC} && ${FIND} * -exec ${CHMOD} g-w,o-w \{} \;

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} pybabel pybabel-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
