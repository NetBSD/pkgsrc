# $NetBSD: Makefile,v 1.1 2015/06/03 22:21:41 pettai Exp $

DISTNAME=	volatility-2.4
CATEGORIES=	security
MASTER_SITES=	http://downloads.volatilityfoundation.org/releases/2.4/

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://volatilityfoundation.org/
COMMENT=	Volatility, Art of Memory Forensics
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-distorm3-[0-9]*:../../devel/py-distorm3

PYDISTUTILSPKG= yes
REPLACE_PYTHON= tools/vtype_diff.py

PYTHON_VERSIONS_INCOMPATIBLE=	33 34

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
