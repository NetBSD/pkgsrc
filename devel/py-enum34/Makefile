# $NetBSD: Makefile,v 1.10 2018/05/22 11:40:37 adam Exp $

DISTNAME=	enum34-1.1.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/enum34/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucket.org/stoneleaf/enum34
COMMENT=	Python module for enums like in python-3.4
LICENSE=	modified-bsd

PYTHON_VERSIONS_ACCEPTED=	27 # unnecessary on 34 and newer

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
