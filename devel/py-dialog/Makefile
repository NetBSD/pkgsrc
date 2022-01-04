# $NetBSD: Makefile,v 1.10 2022/01/04 20:53:00 wiz Exp $

DISTNAME=	pythondialog-3.5.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^python//}
PKGREVISION=	1
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
