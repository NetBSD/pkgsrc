# $NetBSD: Makefile,v 1.11 2006/02/10 16:06:46 drochner Exp $
#

DISTNAME=	myhdl-0.5
PKGNAME=	${PYPKGPREFIX}-MyHDL-0.5
CATEGORIES=	cad python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=myhdl/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://jandecaluwe.com/Tools/MyHDL/Overview.html
COMMENT=	Hardware description in Python

PYDISTUTILSPKG=	yes
PYTHON_VERSIONS_ACCEPTED=	24

do-test:
	cd ${WRKSRC}/myhdl/test && ${PYTHONBIN} test_all.py

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
