# $NetBSD: Makefile,v 1.18 2026/04/04 07:44:34 tnn Exp $

DISTNAME=	kiwisolver-1.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=k/kiwisolver/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/nucleic/kiwi
COMMENT=	Fast implementation of the Cassowary constraint solver
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=3.4.3:../../devel/py-setuptools_scm

USE_LANGUAGES=	c c++

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/${PYSITELIB}/src/version.h
	${RMDIR} ${DESTDIR}${PREFIX}/${PYSITELIB}/src || ${TRUE}

BUILDLINK_API_DEPENDS.py-cppy+=	${PYPKGPREFIX}-cppy>=1.3.0
.include "../../devel/py-cppy/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
