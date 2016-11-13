# $NetBSD: Makefile,v 1.4 2016/11/13 10:52:28 mef Exp $

VERSION=	3.4.0
DISTNAME=	pythondialog-${VERSION}
PKGNAME=	${PYPKGPREFIX}-dialog-${VERSION}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pythondialog/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pythondialog.sourceforge.net/
COMMENT=	Python wrapper for the dialog utility
LICENSE=	gnu-lgpl-v2.1

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../misc/dialog/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
