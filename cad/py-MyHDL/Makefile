# $NetBSD: Makefile,v 1.13 2006/05/04 16:58:05 drochner Exp $
#

DISTNAME=	myhdl-0.5.1
PKGNAME=	${PYPKGPREFIX}-MyHDL-0.5.1
CATEGORIES=	cad python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=myhdl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jandecaluwe.com/Tools/MyHDL/Overview.html
COMMENT=	Hardware description in Python

PYDISTUTILSPKG=	yes
PYTHON_VERSIONS_ACCEPTED=	24

do-test:
	cd ${WRKSRC}/myhdl/test && ${PYTHONBIN} test_all.py

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
