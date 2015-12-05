# $NetBSD: Makefile,v 1.3 2015/12/05 21:25:36 adam Exp $

DISTNAME=	distorm3-3.3.0
PKGNAME=	${PYPKGPREFIX}-distorm3-3.3.0
CATEGORIES=	devel python
MASTER_SITES=	https://pypi.python.org/packages/source/d/distorm3/
EXTRACT_SUFX=	.zip

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://code.google.com/p/distorm/
COMMENT=	Powerful Disassembler Library For x86/AMD64
LICENSE=	gnu-gpl-v3

PYDISTUTILSPKG= yes
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
