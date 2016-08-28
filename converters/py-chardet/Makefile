# $NetBSD: Makefile,v 1.15 2016/08/28 15:48:29 wiz Exp $

DISTNAME=	chardet-2.3.0
PKGREVISION=	1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	converters python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/chardet/}

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	http://pypi.python.org/pypi/chardet
COMMENT=	Character encoding auto-detection in Python
LICENSE=	gnu-lgpl-v2.1

REPLACE_PYTHON=		chardet/chardetect.py

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/chardetect ${DESTDIR}${PREFIX}/bin/chardetect-${PYVERSSUFFIX}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
