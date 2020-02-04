# $NetBSD: Makefile,v 1.6 2020/02/04 17:17:06 adam Exp $

DISTNAME=	pythondialog-3.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^python//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pythondialog/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pythondialog.sourceforge.net/
COMMENT=	Python wrapper for the dialog utility
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../misc/dialog/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
