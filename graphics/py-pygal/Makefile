# $NetBSD: Makefile,v 1.4 2016/06/08 17:43:34 wiz Exp $

DISTNAME=	pygal-1.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pygal/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://pygal.org/
COMMENT=	Python SVG graph plotting library
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml

USE_LANGUAGES=	# none

PY_PATCHPLIST=	yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

.include "options.mk"

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/pygal_gen.py \
		${DESTDIR}${PREFIX}/bin/pygal_gen${PYVERSSUFFIX}.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
