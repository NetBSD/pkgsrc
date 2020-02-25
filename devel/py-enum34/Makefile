# $NetBSD: Makefile,v 1.11 2020/02/25 08:56:41 adam Exp $

DISTNAME=	enum34-1.1.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/enum34/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucket.org/stoneleaf/enum34
COMMENT=	Python 3.4 Enum backported
LICENSE=	modified-bsd

PYTHON_VERSIONS_ACCEPTED=	27 # unnecessary on 34 and newer

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
