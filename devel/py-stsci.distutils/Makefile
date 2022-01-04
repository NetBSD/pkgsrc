# $NetBSD: Makefile,v 1.5 2022/01/04 20:53:40 wiz Exp $

DISTNAME=	stsci.distutils-0.3.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=s/stsci.distutils/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://www.stsci.edu/resources/software_hardware/stsci_python
COMMENT=	Distutils/packaging-related utilities used by some of STScI's packages
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-d2to1-[0-9]*:../../devel/py-d2to1

.include "../../lang/python/pyversion.mk"

.if ${PYPKGPREFIX} != "py27"
pre-build:
	cd ${WRKSRC} && 2to3-${PYVERSSUFFIX} -w --no-diff stsci
.endif

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
