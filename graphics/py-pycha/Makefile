# $NetBSD: Makefile,v 1.8 2015/04/13 23:12:42 rodent Exp $

DISTNAME=	pycha-0.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	https://pypi.python.org/packages/source/p/pycha/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://bitbucket.org/lgs/pycha/
COMMENT=	Library for making charts with Python
LICENSE=      	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-gtk2-[0-9]*:../../x11/py-gtk2

USE_LANGUAGES=	#none

PYTHON_SELF_CONFLICT=	yes
PYTHON_VERSIONED_DEPENDENCIES=	cairo
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-gtk2

post-install:
	${CHMOD} ${SHAREMODE} ${DESTDIR}${PREFIX}/${PYSITELIB}/${EGG_INFODIR}/*

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
