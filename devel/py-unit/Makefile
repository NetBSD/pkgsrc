# $NetBSD: Makefile,v 1.13 2012/10/03 23:40:38 cheusov Exp $

DISTNAME=	pyunit-1.4.1
PKGNAME=	${PYPKGPREFIX}-unit-1.4.1
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pyunit/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pyunit.sourceforge.net/
COMMENT=	Unit testing framework for python

PKG_DESTDIR_SUPPORT=	user-destdir

EGG_NAME=	PyUnit-${PKGVERSION_NOREV}

PYTHON_SELF_CONFLICT=	yes

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
