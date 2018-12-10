# $NetBSD: Makefile,v 1.10 2018/12/10 17:49:26 jperkin Exp $

DISTNAME=	PyMySQL-0.9.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyMySQL/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/PyMySQL/PyMySQL
COMMENT=	Pure-Python MySQL driver
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-cryptography-[0-9]*:../../security/py-cryptography

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
