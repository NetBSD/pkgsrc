# $NetBSD: Makefile,v 1.1.1.1 2002/01/29 16:20:47 drochner Exp $

DISTNAME=	pyunit-1.4.1
PKGNAME=	${PYPKGPREFIX}-unitgui-1.4.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pyunit/}

MAINTAINER=	shell@shellhung.org
HOMEPAGE=	http://pyunit.sourceforge.net/
COMMENT=	unit testing framework for python tk

PYDISTUTILSPKG=	# defined

.include "../../lang/python/extension.buildlink.mk"
.include "../../x11/py-Tk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
