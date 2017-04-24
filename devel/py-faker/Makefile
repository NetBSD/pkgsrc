# $NetBSD: Makefile,v 1.1 2017/04/24 16:38:54 darcy Exp $

VERS=		  0.7.11
DISTNAME=	  Faker-${VERS}
PKGNAME=	  ${PYPKGPREFIX}-faker-${VERS}
CATEGORIES=	  devel python
MASTER_SITES= ${MASTER_SITE_PYPI:=F/Faker/}

MAINTAINER=	darcy@NetBSD.org
HOMEPAGE=	https://github.com/joke2k/faker
COMMENT=	Faker is a Python package that generates fake data for you
LICENSE=	mit

DEPENDS += ${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
