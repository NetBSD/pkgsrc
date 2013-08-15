# $NetBSD: Makefile,v 1.2 2013/08/15 20:57:14 richard Exp $
DISTNAME=		pycha-0.6.0
PKGREVISION=	1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		graphics python
MASTER_SITES=	https://pypi.python.org/packages/source/p/pycha/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://bitbucket.org/lgs/pycha/
COMMENT=		Library for making charts with Python
LICENSE=      	gnu-lgpl-v3

DEPENDS+=		${PYPKGPREFIX}-cairo-[0-9]*:../../graphics/py-cairo
DEPENDS+=		${PYPKGPREFIX}-gtk2-[0-9]*:../../x11/py-gtk2

USE_LANGUAGES=	#none

PYTHON_SELF_CONFLICT=	yes

post-install:
	${CHMOD} ${SHAREMODE} ${DESTDIR}${PREFIX}/${PYSITELIB}/${EGG_NAME}-py${PYVERSSUFFIX}.egg-info/*

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
