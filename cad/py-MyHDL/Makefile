# $NetBSD: Makefile,v 1.17 2012/10/04 07:02:41 wiz Exp $
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

do-test:
	cd ${WRKSRC}/myhdl/test/core && ${PYTHONBIN} test_all.py

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
