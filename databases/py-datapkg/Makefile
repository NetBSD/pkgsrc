# $NetBSD: Makefile,v 1.14 2017/01/01 14:43:27 wiz Exp $

DISTNAME=	datapkg-0.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_PYPI:=d/datapkg/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://okfn.org/projects/project-archive/datapkg/
COMMENT=	Tool for distributing, discovering, and installing data packages
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-ckanclient-[0-9]*:../../databases/py-ckanclient

CONFLICTS=	datapkg-[0-9]*
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-ckanclient

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
