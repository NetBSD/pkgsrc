# $NetBSD: Makefile,v 1.15 2008/06/12 02:14:16 joerg Exp $
#

DISTNAME=	myhdl-0.5.1
PKGNAME=	${PYPKGPREFIX}-MyHDL-0.5.1
CATEGORIES=	cad python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=myhdl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jandecaluwe.com/Tools/MyHDL/Overview.html
COMMENT=	Hardware description in Python

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes
PYTHON_VERSIONS_ACCEPTED=	25 24

do-test:
	cd ${WRKSRC}/myhdl/test && ${PYTHONBIN} test_all.py

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
