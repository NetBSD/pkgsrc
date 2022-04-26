# $NetBSD: Makefile,v 1.7 2022/04/26 18:45:53 adam Exp $

DISTNAME=	immutables-0.17
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/immutables/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/MagicStack/immutables
COMMENT=	Immutable collections
LICENSE=	apache-2.0

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
