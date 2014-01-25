# $NetBSD: Makefile,v 1.16 2014/01/25 10:30:05 wiz Exp $

DISTNAME=	pyunit-1.4.1
PKGNAME=	${PYPKGPREFIX}-unit-1.4.1
PKGREVISION=	3
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pyunit/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pyunit.sourceforge.net/
COMMENT=	Unit testing framework for python

EGG_NAME=	PyUnit-${PKGVERSION_NOREV}

PYTHON_SELF_CONFLICT=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	33

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
