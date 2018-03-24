# $NetBSD: Makefile,v 1.2 2018/03/24 17:09:33 joerg Exp $

.include "../../emulators/unicorn/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES+=	python

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Python bindings for unicorn
LICENSE=	gnu-gpl-v2

PYSETUPSUBDIR=	bindings/python

.include "../../emulators/unicorn/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
