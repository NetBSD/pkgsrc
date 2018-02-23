# $NetBSD: Makefile,v 1.1 2018/02/23 17:25:51 minskim Exp $

DISTNAME=	prefixspan-0.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/prefixspan/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/chuanconggao/PrefixSpan-py
COMMENT=	PrefixSpan in Python 3
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-docopt>=0.6.2:../../devel/py-docopt

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/prefixspan-cli \
		${DESTDIR}${PREFIX}/bin/prefixspan-cli${PYVERSSUFFIX}

.include "../../mk/bsd.pkg.mk"
