# $NetBSD: Makefile,v 1.1 2016/05/08 14:11:37 wen Exp $

DISTNAME=	cycler-0.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=C/Cycler/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/matplotlib/cycler
COMMENT=	Composable style cycles
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-six>=0:../../lang/py-six

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
