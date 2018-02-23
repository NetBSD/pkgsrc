# $NetBSD: Makefile,v 1.4 2018/02/23 02:42:06 khorben Exp $

.include "../../devel/capstone/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES+=	python

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Python bindings for capstone
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/capstone-${GITHUB_TAG}
PYSETUPSUBDIR=	bindings/python

.include "../../devel/capstone/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
