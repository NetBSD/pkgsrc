# $NetBSD: Makefile,v 1.1.1.1 2011/10/04 12:02:41 wiz Exp $
#

DISTNAME=	datapkg-0.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/okfn-datapkg-//:C/-0-.*$//}
CATEGORIES=	databases
MASTER_SITES=	http://pypi.python.org/packages/source/d/datapkg/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://okfn.org/projects/datapkg/
COMMENT=	Tool for distributing, discovering, and installing data packages
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-ckanclient-[0-9]*:../../databases/py-ckanclient

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	datapkg-[0-9]*

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
