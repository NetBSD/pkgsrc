# $NetBSD: Makefile,v 1.6 2004/07/22 09:16:01 recht Exp $

DISTNAME=	pyunit-1.4.1
PKGNAME=	${PYPKGPREFIX}-unitgui-1.4.1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pyunit/}

MAINTAINER=	shell@shellhung.org
HOMEPAGE=	http://pyunit.sourceforge.net/
COMMENT=	Unit testing framework for python tk

PYDISTUTILSPKG=	# defined
USE_BUILDLINK3=	yes

.include "../../lang/python/extension.mk"
.include "../../x11/py-Tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
