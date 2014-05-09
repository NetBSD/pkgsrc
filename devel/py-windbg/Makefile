# $NetBSD: Makefile,v 1.13 2014/05/09 07:37:03 wiz Exp $

DISTNAME=	winpdb-1.4.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	devel python
MASTER_SITES=	http://winpdb.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://winpdb.org/
COMMENT=	Python GUI debugger
LICENSE=	gnu-gpl-v2 # or later

DEPENDS+=	${PYPKGPREFIX}-wxWidgets>=2.6:../../x11/py-wxWidgets

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-wxWidgets

USE_LANGUAGES=	#none

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
