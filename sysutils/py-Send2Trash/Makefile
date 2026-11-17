# $NetBSD: Makefile,v 1.15 2026/11/17 09:42:32 adam Exp $

DISTNAME=	send2trash-2.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/send2t/Send2T/}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=S/Send2Trash/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hsoft/send2trash
COMMENT=	Send file to trash
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	send2trash

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
