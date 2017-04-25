# $NetBSD: Makefile,v 1.1 2017/04/25 20:14:26 fhajny Exp $

DISTNAME=	nose2-0.6.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=n/nose2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/nose-devs/nose2/
COMMENT=	Next generation of nicer testing for Python
LICENSE=	2-clause-bsd

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-six>=1.1:../../lang/py-six

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/bin/nose2

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
