# $NetBSD: Makefile,v 1.3 2003/06/28 14:49:47 drochner Exp $

DISTNAME=	pychecker-0.8.12
PKGNAME=	${PYPKGPREFIX}-checker-0.8.12
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pychecker/}

MAINTAINER=	shell@netbsd.org
HOMEPAGE=	http://pychecker.sourceforge.net/
COMMENT=	python code checker

USE_BUILDLINK2=	yes
PYDISTUTILSPKG=	# defined
PLIST_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX}
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
