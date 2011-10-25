# $NetBSD: Makefile,v 1.14 2011/10/25 09:24:21 obache Exp $
#

DISTNAME=	gnuplot-py-1.8
PKGNAME=	${PYPKGPREFIX}-gnuplot-1.8
PKGREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnuplot-py/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gnuplot-py.sourceforge.net/
COMMENT=	Python package that interfaces to gnuplot
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
EGG_NAME=	${DISTNAME:S/-/_/}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
