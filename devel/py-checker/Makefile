# $NetBSD: Makefile,v 1.11 2005/12/05 20:50:07 rillig Exp $

DISTNAME=	pychecker-0.8.14
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pychecker/}

MAINTAINER=	shell@NetBSD.org
HOMEPAGE=	http://pychecker.sourceforge.net/
COMMENT=	Python code checker

PYDISTUTILSPKG=	# defined
PLIST_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX:Q}
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q}

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
