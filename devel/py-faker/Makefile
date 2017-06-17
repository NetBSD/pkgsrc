# $NetBSD: Makefile,v 1.2 2017/06/17 19:37:12 joerg Exp $

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

.include "../../lang/python/pyversion.mk"

PLIST_VARS+=	python2 python3
.if !empty(PYVERSSUFFIX:M2.*)
PLIST.python2=	yes
.elif !empty(PYVERSSUFFIX:M3.*)
PLIST.python3=	yes
.endif

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
