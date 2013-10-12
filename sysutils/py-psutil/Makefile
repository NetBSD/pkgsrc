# $NetBSD: Makefile,v 1.1 2013/10/12 13:32:36 wiz Exp $

DISTNAME=	psutil-1.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils
MASTER_SITES=	http://psutil.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/psutil/
COMMENT=	Cross-platform process and system utilities module for Python
LICENSE=	modified-bsd

REPLACE_PYTHON=	psutil/*py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
