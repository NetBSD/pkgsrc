# $NetBSD: Makefile,v 1.3 2002/10/24 21:08:52 drochner Exp $

DISTNAME=	pyunit-1.4.1
PKGNAME=	${PYPKGPREFIX}-unitgui-1.4.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pyunit/}

MAINTAINER=	shell@shellhung.org
HOMEPAGE=	http://pyunit.sourceforge.net/
COMMENT=	unit testing framework for python tk

PYDISTUTILSPKG=	# defined
USE_BUILDLINK2=	yes

.include "../../lang/python/extension.mk"
.include "../../x11/py-Tk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
