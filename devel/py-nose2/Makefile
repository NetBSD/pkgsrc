# $NetBSD: Makefile,v 1.12 2022/08/24 09:25:56 wiz Exp $

DISTNAME=	nose2-0.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/nose2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/nose-devs/nose2
COMMENT=	Next generation of nicer testing for Python
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-six>=1.7:../../lang/py-six
.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
.endif

PYTHON_VERSIONED_DEPENDENCIES+=	coverage

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/bin/nose2

.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
