# $NetBSD: Makefile,v 1.2 2022/01/04 20:53:19 wiz Exp $

DISTNAME=	packageurl-python-0.9.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-python//}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/packageurl-python/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/package-url/packageurl-python
COMMENT=	Purl aka. Package URL parser and builder
LICENSE=	mit

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
