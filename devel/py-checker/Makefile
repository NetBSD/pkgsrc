# $NetBSD: Makefile,v 1.4 2003/07/17 21:33:20 grant Exp $

DISTNAME=	pychecker-0.8.12
PKGNAME=	${PYPKGPREFIX}-checker-0.8.12
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pychecker/}

MAINTAINER=	shell@NetBSD.org
HOMEPAGE=	http://pychecker.sourceforge.net/
COMMENT=	python code checker

USE_BUILDLINK2=	yes
PYDISTUTILSPKG=	# defined
PLIST_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX}
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
