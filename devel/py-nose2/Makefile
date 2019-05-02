# $NetBSD: Makefile,v 1.7 2019/05/02 09:38:23 adam Exp $

DISTNAME=	nose2-0.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/nose2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/nose-devs/nose2
COMMENT=	Next generation of nicer testing for Python
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-coverage>=4.4.1:../../devel/py-coverage
DEPENDS+=	${PYPKGPREFIX}-six>=1.7:../../lang/py-six
.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
.endif

USE_LANGUAGES=	# none

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/bin/nose2

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
