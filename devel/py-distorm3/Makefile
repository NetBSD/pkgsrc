# $NetBSD: Makefile,v 1.5 2016/07/09 13:03:40 wiz Exp $

DISTNAME=	distorm3-3.3.0
PKGNAME=	${PYPKGPREFIX}-distorm3-3.3.0
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/distorm3/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://code.google.com/p/distorm/
COMMENT=	Powerful Disassembler Library For x86/AMD64
LICENSE=	gnu-gpl-v3

PYDISTUTILSPKG= yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
