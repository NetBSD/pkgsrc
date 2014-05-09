# $NetBSD: Makefile,v 1.17 2014/05/09 07:37:03 wiz Exp $

DISTNAME=	pyunit-1.4.1
PKGNAME=	${PYPKGPREFIX}-unitgui-1.4.1
PKGREVISION=	3
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pyunit/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pyunit.sourceforge.net/
COMMENT=	Unit testing framework for python tk

DEPENDS+=	${PYPKGPREFIX}-Tk-[0-9]*:../../x11/py-Tk

EGG_NAME=	PyUnit-${PKGVERSION_NOREV}

PYTHON_VERSIONS_INCOMPATIBLE=	33 34

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
