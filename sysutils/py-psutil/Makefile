# $NetBSD: Makefile,v 1.2 2013/11/02 09:38:34 wiz Exp $

DISTNAME=	psutil-1.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils
MASTER_SITES=	https://pypi.python.org/packages/source/p/psutil/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/psutil/
COMMENT=	Cross-platform process and system utilities module for Python
LICENSE=	modified-bsd

REPLACE_PYTHON=	psutil/*py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
