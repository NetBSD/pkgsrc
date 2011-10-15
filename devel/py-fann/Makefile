# $NetBSD: Makefile,v 1.7 2011/10/15 12:17:26 obache Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../devel/fann-devel/Makefile.common"
PKGNAME=	${PYPKGPREFIX}-fann-${FANNVERSION}.${FANNDATE}
PKGREVISION=	1

COMMENT=		Fast Artificial Neural Network python interface

USE_LANGUAGES=		c c++

PYSETUPSUBDIR=		python

EGG_NAME=		pyfann-2.0.0

.include "../../devel/fann-devel/buildlink3.mk"
.include "../../devel/swig/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
