# $NetBSD: Makefile,v 1.5 2003/07/21 16:43:45 martti Exp $

DISTNAME=	pychecker-0.8.12
PKGNAME=	${PYPKGPREFIX}-checker-0.8.12
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pychecker/}

MAINTAINER=	shell@NetBSD.org
HOMEPAGE=	http://pychecker.sourceforge.net/
COMMENT=	Python code checker

USE_BUILDLINK2=	yes
PYDISTUTILSPKG=	# defined
PLIST_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX}
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
