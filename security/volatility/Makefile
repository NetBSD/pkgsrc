# $NetBSD: Makefile,v 1.7 2017/01/01 14:43:56 wiz Exp $

DISTNAME=	volatility-2.4
CATEGORIES=	security
MASTER_SITES=	http://downloads.volatilityfoundation.org/releases/2.4/

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://volatilityfoundation.org/
COMMENT=	Advanced memory forensics framework
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-crypto-[0-9]*:../../security/py-crypto
DEPENDS+=	${PYPKGPREFIX}-cElementTree-[0-9]*:../../textproc/py-cElementTree
DEPENDS+=	${PYPKGPREFIX}-distorm3-[0-9]*:../../devel/py-distorm3

PYDISTUTILSPKG= yes
REPLACE_PYTHON= tools/vtype_diff.py

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36

.include "../../lang/python/egg.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
