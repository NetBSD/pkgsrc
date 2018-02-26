# $NetBSD: Makefile,v 1.1 2018/02/26 02:25:28 khorben Exp $

.include "../../emulators/unicorn/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES+=	python

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Python bindings for unicorn
LICENSE=	gnu-gpl-v2

PYSETUPSUBDIR=	bindings/python

.include "../../emulators/unicorn/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
