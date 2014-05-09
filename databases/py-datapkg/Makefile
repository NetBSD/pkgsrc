# $NetBSD: Makefile,v 1.10 2014/05/09 07:36:57 wiz Exp $

DISTNAME=	datapkg-0.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases
MASTER_SITES=	http://pypi.python.org/packages/source/d/datapkg/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://okfn.org/projects/project-archive/datapkg/
COMMENT=	Tool for distributing, discovering, and installing data packages
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-ckanclient-[0-9]*:../../databases/py-ckanclient

CONFLICTS=	datapkg-[0-9]*
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-ckanclient

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
