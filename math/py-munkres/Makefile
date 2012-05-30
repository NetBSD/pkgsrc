# $NetBSD: Makefile,v 1.1.1.1 2012/05/30 11:05:30 wiz Exp $
#

DISTNAME=	munkres-1.0.5.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	http://pypi.python.org/packages/source/m/munkres/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pypi.python.org/pypi/munkres/
COMMENT=	Munkres algorithm for the Assignment Problem
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none
REPLACE_PYTHON=	munkres.py

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
