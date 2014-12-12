# $NetBSD: Makefile,v 1.9 2014/12/12 19:54:31 imil Exp $

DISTNAME=	requests-2.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel www
MASTER_SITES=	https://pypi.python.org/packages/source/r/requests/

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	http://docs.python-requests.org/en/latest/
COMMENT=	HTTP library, written in Python, for human beings
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-docutils>=0.10:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-markupsafe-[0-9]*:../../textproc/py-markupsafe
DEPENDS+=	${PYPKGPREFIX}-pygments-[0-9]*:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-sphinx>=1.1.3:../../textproc/py-sphinx

WRKSRC=		${WRKDIR}/${EGG_NAME}
USE_LANGUAGES=	c
REPLACE_PYTHON=	requests/certs.py requests/packages/chardet/chardetect.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
