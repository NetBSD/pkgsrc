# $NetBSD: Makefile,v 1.9 2019/09/02 13:19:43 adam Exp $

VERSION=	3.4.0
DISTNAME=	python2-pythondialog-${VERSION}
PKGNAME=	${PYPKGPREFIX}-dialog-${VERSION}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python2-pythondialog/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pythondialog.sourceforge.net/
COMMENT=	Python wrapper for the dialog utility
LICENSE=	gnu-lgpl-v2.1

PYTHON_VERSIONS_ACCEPTED=	 27

.include "../../misc/dialog/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
