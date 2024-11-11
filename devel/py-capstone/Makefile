# $NetBSD: Makefile,v 1.9 2024/11/11 07:28:03 wiz Exp $

.include "../../devel/capstone/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES+=	python

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Python bindings for capstone
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/capstone-${GITHUB_TAG}
PYSETUPSUBDIR=	bindings/python

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../devel/capstone/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
