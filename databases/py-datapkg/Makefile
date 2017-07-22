# $NetBSD: Makefile,v 1.15 2017/07/22 07:08:50 adam Exp $

DISTNAME=	datapkg-0.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_PYPI:=d/datapkg/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://okfn.org/projects/project-archive/datapkg/
COMMENT=	Tool for distributing, discovering, and installing data packages
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-ckanclient>=0.3:../../databases/py-ckanclient

CONFLICTS=	datapkg-[0-9]*
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-ckanclient

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
