# $NetBSD: Makefile,v 1.23 2016/07/09 13:03:32 wiz Exp $

DISTNAME=	myhdl-0.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/myhdl/MyHDL/}
CATEGORIES=	cad python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=myhdl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jandecaluwe.com/Tools/MyHDL/Overview.html
COMMENT=	Hardware description in Python
LICENSE=	gnu-gpl-v2

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # not yet ported as of 0.7

do-test:
	cd ${WRKSRC}/myhdl/test/core && ${PYTHONBIN} test_all.py

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
