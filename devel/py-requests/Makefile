# $NetBSD: Makefile,v 1.2 2013/05/23 15:01:15 joerg Exp $
#

DISTNAME=	v1.2.1
PKGNAME=	${PYPKGPREFIX}-requests-${DISTNAME}
EGG_NAME=	requests-1.2.1
CATEGORIES=	devel www
MASTER_SITES=	https://github.com/kennethreitz/requests/archive/
EXTRACT_SUFX=	.zip
FETCH_USING=	curl

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	http://docs.python-requests.org/en/latest/
COMMENT=	HTTP library, written in Python, for human beings
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/requests-1.2.1
USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-docutils>=0.10:../../textproc/py-docutils

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
