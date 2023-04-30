# $NetBSD: Makefile,v 1.1 2023/04/30 12:59:49 wiz Exp $

DISTNAME=	attrs-21.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/attrs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	https://www.attrs.org/
COMMENT=	Attributes without boilerplate
LICENSE=	mit

# can't run self tests because py-test depends on py-attrs

PYTHON_VERSIONS_ACCEPTED=	27

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
