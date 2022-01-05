# $NetBSD: Makefile,v 1.21 2022/01/05 20:07:10 wiz Exp $

DISTNAME=	datapkg-0.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_PYPI:=d/datapkg/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://okfn.org/projects/project-archive/datapkg/
COMMENT=	Tool for distributing, discovering, and installing data packages
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-ckanclient>=0.3:../../databases/py-ckanclient

CONFLICTS=	datapkg-[0-9]*
PYTHON_VERSIONS_ACCEPTED= 27 # py-ckanclient

USE_PKG_RESOURCES=	yes

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
