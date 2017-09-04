# $NetBSD: Makefile,v 1.7 2017/09/04 18:55:08 wiz Exp $

DISTNAME=	distorm3-3.3.0
PKGNAME=	${PYPKGPREFIX}-distorm3-3.3.0
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/distorm3/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	https://github.com/gdabah/distorm
COMMENT=	Powerful Disassembler Library For x86/AMD64
LICENSE=	gnu-gpl-v3

PYDISTUTILSPKG= yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
