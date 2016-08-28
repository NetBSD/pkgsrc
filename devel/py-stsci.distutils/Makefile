# $NetBSD: Makefile,v 1.2 2016/08/28 17:47:30 wiz Exp $

DISTNAME=	stsci.distutils-0.3.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_PYPI:=s/stsci.distutils/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://www.stsci.edu/resources/software_hardware/stsci_python
COMMENT=	Distutils/packaging-related utilities used by some of STScI's packages
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-d2to1-[0-9]*:../../devel/py-d2to1

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
