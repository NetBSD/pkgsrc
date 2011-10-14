# $NetBSD: Makefile,v 1.4 2011/10/14 04:45:14 dholland Exp $
#

DISTNAME=	datapkg-0.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases
MASTER_SITES=	http://pypi.python.org/packages/source/d/datapkg/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://okfn.org/projects/datapkg/
COMMENT=	Tool for distributing, discovering, and installing data packages
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-ckanclient-[0-9]*:../../databases/py-ckanclient

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	datapkg-[0-9]*

# because of py-ckanclient
PYTHON_VERSIONS_INCOMPATIBLE=	24 25

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
