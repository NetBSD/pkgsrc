# $NetBSD: Makefile,v 1.1 2024/08/14 17:21:44 wiz Exp $

DISTNAME=	rfc6555-0.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rfc6555/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.github.com/sethmlarson/rfc6555
COMMENT=	Implementation of the Happy Eyeballs Algorithm described in RFC 6555
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-selectors2>=2.0.1:../../devel/py-selectors2

USE_LANGUAGES=	# none

PYTHON_27_ACCEPTED=	yes

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
