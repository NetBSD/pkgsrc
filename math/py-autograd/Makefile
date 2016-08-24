# $NetBSD: Makefile,v 1.1 2016/08/24 23:50:12 markd Exp $

DISTNAME=	autograd-1.1.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=a/autograd/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/HIPS/autograd
COMMENT=	Efficiently computes derivatives of numpy code
LICENSE=	mit

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
