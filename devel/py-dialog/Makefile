# $NetBSD: Makefile,v 1.1 2015/01/11 20:14:58 bsiegert Exp $

VERSION=	3.2.1
DISTNAME=	pythondialog-${VERSION}
PKGNAME=	${PYPKGPREFIX}-dialog-${VERSION}
CATEGORIES=	devel python
MASTER_SITES=	https://pypi.python.org/packages/source/p/pythondialog/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pythondialog.sourceforge.net/
COMMENT=	Python wrapper for the dialog utility
LICENSE=	gnu-lgpl-v2.1

PYTHON_VERSIONS_INCOMPATIBLE=	26 27

.include "../../misc/dialog/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
