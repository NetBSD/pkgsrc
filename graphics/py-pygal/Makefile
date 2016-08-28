# $NetBSD: Makefile,v 1.5 2016/08/28 15:48:32 wiz Exp $

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

.include "options.mk"

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/pygal_gen.py \
		${DESTDIR}${PREFIX}/bin/pygal_gen${PYVERSSUFFIX}.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
