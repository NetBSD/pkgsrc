# $NetBSD: Makefile,v 1.8 2004/07/22 09:16:01 recht Exp $

DISTNAME=	pychecker-0.8.13
PKGNAME=	${PYPKGPREFIX}-checker-0.8.13
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pychecker/}

MAINTAINER=	shell@NetBSD.org
HOMEPAGE=	http://pychecker.sourceforge.net/
COMMENT=	Python code checker

USE_BUILDLINK3=	yes
PYDISTUTILSPKG=	# defined
PLIST_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX}
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
