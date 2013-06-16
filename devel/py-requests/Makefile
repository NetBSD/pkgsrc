# $NetBSD: Makefile,v 1.3 2013/06/16 11:48:51 wiz Exp $

DISTNAME=	v1.2.1
PKGNAME=	${PYPKGPREFIX}-requests-${DISTNAME:S/v//}
PKGREVISION=	1
EGG_NAME=	requests-1.2.1
CATEGORIES=	devel www
MASTER_SITES=	https://github.com/kennethreitz/requests/archive/
EXTRACT_SUFX=	.zip

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	http://docs.python-requests.org/en/latest/
COMMENT=	HTTP library, written in Python, for human beings
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/requests-1.2.1
USE_LANGUAGES=	# none
REPLACE_PYTHON=	requests/certs.py

DEPENDS+=	${PYPKGPREFIX}-docutils>=0.10:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-markupsafe-[0-9]*:../../textproc/py-markupsafe
DEPENDS+=	${PYPKGPREFIX}-pygments-[0-9]*:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
