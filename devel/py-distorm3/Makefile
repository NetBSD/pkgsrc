# $NetBSD: Makefile,v 1.2 2015/06/06 08:13:50 pettai Exp $

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
PYTHON_VERSIONS_INCOMPATIBLE=	33 34

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
