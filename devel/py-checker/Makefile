# $NetBSD: Makefile,v 1.7 2004/04/27 04:59:42 snj Exp $

DISTNAME=	pychecker-0.8.13
PKGNAME=	${PYPKGPREFIX}-checker-0.8.13
CATEGORIES=	devel
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
