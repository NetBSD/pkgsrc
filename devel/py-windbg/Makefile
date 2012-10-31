# $NetBSD: Makefile,v 1.10 2012/10/31 11:19:36 asau Exp $
#

DISTNAME=		winpdb-1.4.6
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		8
CATEGORIES=		devel python
MASTER_SITES=		http://winpdb.googlecode.com/files/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://winpdb.org
COMMENT=		Python GUI debugger
LICENSE=		gnu-gpl-v2 # or later

DEPENDS+=		${PYPKGPREFIX}-wxWidgets>=2.6:../../x11/py-wxWidgets

USE_LANGUAGES=		#none

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
