# $NetBSD: Makefile,v 1.6 2014/01/26 13:00:43 wiz Exp $

DISTNAME=	v2.2.0
EGG_NAME=	requests-${DISTNAME:S/v//}
PKGNAME=	${PYPKGPREFIX}-${EGG_NAME}
CATEGORIES=	devel www
MASTER_SITES=	https://github.com/kennethreitz/requests/archive/

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
