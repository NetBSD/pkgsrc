# $NetBSD: Makefile,v 1.1 2023/03/12 13:39:00 wiz Exp $

DISTNAME=	makefun-1.15.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=m/makefun/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/makefun/
COMMENT=	Small library to dynamically create python functions
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=0:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-test-runner>=0:../../devel/py-test-runner

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
