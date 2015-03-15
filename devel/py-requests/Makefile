# $NetBSD: Makefile,v 1.14 2015/03/15 21:32:27 wiz Exp $

DISTNAME=	requests-2.5.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel www
MASTER_SITES=	https://pypi.python.org/packages/source/r/requests/

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	http://docs.python-requests.org/en/latest/
COMMENT=	HTTP library, written in Python, for human beings
LICENSE=	apache-2.0

USE_LANGUAGES=	c
REPLACE_PYTHON=	requests/certs.py requests/packages/chardet/chardetect.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
