# $NetBSD: Makefile,v 1.3 2016/06/14 06:54:19 kamil Exp $

.include "../../devel/capstone/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES+=	python

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Python bindings for capstone
LICENSE=	modified-bsd

PYSETUPSUBDIR=	bindings/python

.include "../../devel/capstone/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
