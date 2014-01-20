# $NetBSD: Makefile,v 1.19 2014/01/20 15:46:53 wiz Exp $

DISTNAME=	myhdl-0.7
PKGNAME=	${PYPKGPREFIX}-MyHDL-0.7
PKGREVISION=	1
CATEGORIES=	cad python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=myhdl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jandecaluwe.com/Tools/MyHDL/Overview.html
COMMENT=	Hardware description in Python

PYTHON_VERSIONS_INCOMPATIBLE=	33 # not yet ported as of 0.7

do-test:
	cd ${WRKSRC}/myhdl/test/core && ${PYTHONBIN} test_all.py

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
