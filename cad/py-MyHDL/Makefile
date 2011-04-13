# $NetBSD: Makefile,v 1.16 2011/04/13 14:47:18 drochner Exp $
#

DISTNAME=	myhdl-0.7
PKGNAME=	${PYPKGPREFIX}-MyHDL-0.7
CATEGORIES=	cad python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=myhdl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jandecaluwe.com/Tools/MyHDL/Overview.html
COMMENT=	Hardware description in Python

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes
PYTHON_VERSIONS_ACCEPTED=	26 27

do-test:
	cd ${WRKSRC}/myhdl/test/core && ${PYTHONBIN} test_all.py

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
