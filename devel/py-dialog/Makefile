# $NetBSD: Makefile,v 1.9 2021/11/27 16:44:22 adam Exp $

DISTNAME=	pythondialog-3.5.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^python//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pythondialog/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pythondialog.sourceforge.io/
COMMENT=	Python wrapper for the dialog utility
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../misc/dialog/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
