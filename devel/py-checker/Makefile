# $NetBSD: Makefile,v 1.12 2006/02/05 23:08:51 joerg Exp $

DISTNAME=	pychecker-0.8.14
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	1
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
